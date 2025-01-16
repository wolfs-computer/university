#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



typedef struct _Data {
    char str[8];
    char *name;
    unsigned int quantity;
} Data;


void write_data_text(char *filename, Data *data, int data_len) {
    FILE *f = fopen(filename, "w");

    fprintf(f, "%d\n", data_len);
    for (int i = 0; i < data_len; i++) {
        fprintf(f, "%s\n", data[i].str);
        fprintf(f, "%s\n", data[i].name);
        fprintf(f, "%d\n", data[i].quantity);
    }

    fclose(f);
}

void read_data_text(char *filename, Data **data, int *data_len) {
    FILE *f = fopen(filename, "r");

    fscanf(f, "%d\n", data_len);

    for (int i = 0; i < *data_len; i++) {
        // printf("!!\n");
        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));
        // if (!data) exit(1);

        // always 8
        fscanf(f, "%s\n", (*data)[i].str);
        // printf("%s\n", (*data)[i].str);

        (*data)[i].name = NULL;
        int l = 1;
        char c = fgetc(f);
        while (c != '\n') {
            (*data)[i].name = (char*) realloc((*data)[i].name, (l + 1) * sizeof(char));
            (*data)[i].name[l - 1] = c;
            c = fgetc(f);
            l++;
        }
        (*data)[i].name[l - 1] = '\0';
        // printf("%s\n", (*data)[i].name);

        fscanf(f, "%d\n", &((*data)[i].quantity));
        // printf("%d\n", (*data)[i].quantity);
    }

    fclose(f);
}

void write_data_bin(char *filename, Data *data, int data_len) {
    FILE *f = fopen(filename, "w+b");

    fwrite(&data_len, sizeof(data_len), 1, f);
    for (int i = 0; i < data_len; i++) {
        // always 8
        fwrite(data[i].str, sizeof(char), 8, f);

        // size of next object
        int l = strlen(data[i].name) + 1;
        fwrite(&l, sizeof(l), 1, f);
        fwrite(data[i].name, sizeof(char), l, f);

        fwrite(&(data[i].quantity), sizeof(unsigned int), 1, f);
    }

    fclose(f);
}

void read_data_bin(char *filename, Data **data, int *data_len) {
    FILE *f = fopen(filename, "r+b");

    fread(data_len, sizeof(*data_len), 1, f);

    for (int i = 0; i < *data_len; i++) {
        // printf("!!\n");
        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));
        // if (!data) exit(1);

        // always 8
        fread((*data)[i].str, sizeof(char), 8, f);
        // printf("%s\n", (*data)[i].str);

        // size of next object
        // int l = strlen(data[i].name) + 1;
        int l;
        fread(&l, sizeof(l), 1, f);
        // printf("%d\n", l);
        (*data)[i].name = (char*) calloc(l, sizeof(char));
        fread((*data)[i].name, sizeof(char), l, f);
        // printf("%s\n", (*data)[i].name);

        fread(&((*data)[i].quantity), sizeof(unsigned int), 1, f);
        // printf("%d\n", (*data)[i].quantity);
    }

    fclose(f);
}



int main() {

    Data a = {
        "1234567",
        "random string",
        9
    };

    Data b = {
        "0000000",
        "random string and more data!!!",
        11
    };

    Data list[] = {a, b};


    write_data_text("1test", list, 2);

    int data_len = 0;
    Data *l = NULL;
    read_data_text("1test", &l, &data_len);

    for (int i = 0; i < data_len; i++) {
        printf("%s\n", l[i].str);
        printf("%s\n", l[i].name);
        printf("%d\n", l[i].quantity);
        free(l[i].name);
    }
    free(l);


    // write_data_bin("2test", list, 2);
    //
    // int data_len = 0;
    // Data *l = NULL;
    // read_data_bin("2test", &l, &data_len);
    //
    // for (int i = 0; i < data_len; i++) {
    //     printf("%s\n", l[i].str);
    //     printf("%s\n", l[i].name);
    //     printf("%d\n", l[i].quantity);
    //     free(l[i].name);
    // }
    // free(l);



    return 0;
}
