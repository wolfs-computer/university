#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_io.h"
#include "status.h"


// return Status

// check file format
// in-place check

// field 1 size correction to 9



// Status data_check



//################################################=-> std <-=################################################//



void data_write_std(const Data *data, const int data_len) {
    printf("%d\n", data_len);

    for (int i = 0; i < data_len; i++) {
        printf("%s\n", data[i].id);
        printf("%s\n", data[i].name);
        printf("%d\n", data[i].quantity);
    }
}

void data_read_std(Data **data, int *data_len) {
    // make it normal

    printf("Enter number of structs: ");
    scanf("%d", data_len);
    printf("%d\n", *data_len);

    for (int i = 0; i < *data_len; i++) {
        // printf("!!\n");
        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));
        // if (!data) exit(1);

        // always 8
        printf("name: ");
        scanf("%8s", (*data)[i].id);
        // printf("%s\n", (*data)[i].str);

        printf("name: ");
        (*data)[i].name = NULL;
        int l = 1;
        char c = getchar();
        while (c != '\n') {
            (*data)[i].name = (char*) realloc((*data)[i].name, (l + 1) * sizeof(char));
            (*data)[i].name[l - 1] = c;
            c = getchar();
            l++;
        }
        (*data)[i].name[l - 1] = '\0';
        printf("\n");
        // printf("%s\n", (*data)[i].name);

        printf("quantity: ");
        scanf("%d", &((*data)[i].quantity));
        // printf("%d\n", (*data)[i].quantity);
    }
}


static int does_file_exists(const char *filename) {
    FILE *f;
    if ((f = fopen(filename, "r"))) {
        fclose(f);
        return 1;
    }
    return 0;
}



//################################################=-> txt <-=################################################//



void data_write_text(const char *filename, const Data *data, const int data_len) {
    FILE *f = fopen(filename, "w");

    fprintf(f, "%d\n", data_len);
    for (int i = 0; i < data_len; i++) {
        fprintf(f, "%s\n", data[i].id);
        fprintf(f, "%s\n", data[i].name);
        fprintf(f, "%d\n", data[i].quantity);
    }

    fclose(f);
}

// start here <<<<----

Status data_read_text(const char *filename, Data **data, int *data_len) {
    if (!does_file_exists(filename)) return File_open_fault;

    FILE *f = fopen(filename, "r");

    fscanf(f, "%d\n", data_len);
    // printf("%d\n", *data_len);

    for (int i = 0; i < *data_len; i++) {
        // printf("!!\n");
        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));
        // if (!data) exit(1);

        // always 8
        fscanf(f, "%s\n", (*data)[i].id);
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



//################################################=-> bin <-=################################################//



Status data_write_bin(const char *filename, const Data *data, const int data_len) {
    FILE *f = fopen(filename, "w+b");

    fwrite(&data_len, sizeof(data_len), 1, f);
    for (int i = 0; i < data_len; i++) {
        // always 8
        fwrite(data[i].id, sizeof(char), 8, f);

        // size of next object
        int l = strlen(data[i].name) + 1;
        fwrite(&l, sizeof(l), 1, f);
        fwrite(data[i].name, sizeof(char), l, f);

        fwrite(&(data[i].quantity), sizeof(unsigned int), 1, f);
    }

    fclose(f);
}

Status data_read_bin(const char *filename, Data **data, int *data_len) {
    FILE *f = fopen(filename, "r+b");

    fread(data_len, sizeof(*data_len), 1, f);

    for (int i = 0; i < *data_len; i++) {
        // printf("!!\n");
        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));
        // if (!data) exit(1);

        // always 8
        fread((*data)[i].id, sizeof(char), 8, f);
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
