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


// error --> print error --> continue with zero/spaces/default value


static Status get_1st_field(FILE *stream, Data data) {

    char c = getc(stream);
    int i = 0;
    for (; c != '\n' && c != EOF && i < ID_LEN - 1; i++) {
        data.id[i] = c;
        c = getc(stream);
    }

    if (c == EOF) return Eof;

    if (c == '\n' && i == ID_LEN - 1) {
        data.id[ID_LEN - 1] = '\0';
        return Success;
    }

    fprintf(stderr, "[Error] Invalid input.\n");
    if (c != '\n') {
        while (getc(stream) != '\n');
    }

    return Invalid_input;
}

static void get_2nd_field(FILE *stream, Data data) {

    data.name = NULL;

    char c = getc(stream);
    int i = 0;
    for (; c != '\n' && c != EOF; i++) {
        data.name = (char*) realloc(data.name, (i + 1) * sizeof(char));
        data.name[i] = c;
        c = getc(stream);
    }
    data.name = (char*) realloc(data.name, (i + 1) * sizeof(char));
    data.name[i] = '\0';
}


static Status get_number(FILE *stream, int *num) {

    int status = fscanf(stream, "%d", num);

    if (status == EOF) {
        return Eof;
    }

    if (status == 0) while (getc(stream) != '\n');

    if (status != 1 || *num < 1) {
        fprintf(stderr, "[Error] Invalid input.\n");
        *num = 1;
        return Invalid_input;
    }

    return Success;
}

static void end_input(Data **data, int *data_len) {
    

}


void data_read_std(Data **data, int *data_len) {
    *data = NULL;
    *data_len = 0;
    Status st = Failure;

    printf("Enter number of structs: ");
    st = get_number(stdin, data_len);
    if (st == Eof) {
        printf("\n");
        return;
    }
    printf("Number of structs -> %d\n\n", *data_len);
    // *data_len = 1;

    int i = 0;
    for (; i < *data_len; i++) {
        printf("Struct %d\n", i + 1);

        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));

        printf("id: ");
        st = get_1st_field(stdin, (*data)[i]);
        if (st == Eof) break;
        printf("!! |%s|\n", (*data)[i].id);

        printf("name: ");
        get_2nd_field(stdin, (*data)[i]);
        if (st == Eof) break;
        printf("!! |%s|\n", (*data)[i].name);

        printf("quantity: ");
        get_number(stdin, (int*) &((*data)[i].quantity));
        if (st == Eof) break;
        printf("!! %d\n", (*data)[i].quantity);
    }
    printf("\n");
    *data = (Data*) realloc(*data, (i - 1) * sizeof(Data));
}


static int does_file_exists(const char *filename) {
    FILE *f;
    if ((f = fopen(filename, "r"))) {
        fclose(f);
        return 1;
    }
    return 0;
}

static int does_file_end(FILE *f) {
    long start_pos = ftell(f);
    if (fseek(f, 0, SEEK_END) == start_pos) {
        return 1;
    }
    fseek(f, start_pos, SEEK_SET);
    return 0;
}



//################################################=-> txt <-=################################################//



// ok!
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


Status data_read_text(const char *filename, Data **data, int *data_len) {
    if (!does_file_exists(filename)) return File_open_fault;

    FILE *f = fopen(filename, "r");

    *data_len = 1;
    fscanf(f, "%d\n", data_len);
    if (*data_len < 1 || does_file_end(f)) {
        fclose(f);
        return Data_format_fault;
    }

    for (int i = 0; i < *data_len; i++) {
        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));
        if (!data) return Memory_fault;

        for (int g = 0; g < ID_LEN - 1; g++) {
            char c = getc(f);
            if (c == '\n') { // if too little
                fprintf(stderr, "[Error] Invalid data field in input file.\n");
                (*data)[i].id[0] = '\0'; // erase field 1
                break;
            }
        }
        if (getc(f) == '\n') (*data)[i].id[ID_LEN - 1] = '\0';
        else { // if too much
            fprintf(stderr, "[Error] Invalid data field in input file.\n");
            (*data)[i].id[0] = '\0'; // erase field 1
        }

        if (does_file_end(f)) return Data_format_fault;

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



int main() {

    Data *data = NULL;
    int data_len = 0;

    data_read_std(&data, &data_len);


    for (int i = 0; i < data_len; i++) {
        printf("%s\n", data[i].id);
        printf("%s\n", data[i].name);
        printf("%d\n", data[i].quantity);
        free(data[i].name);
    }
    free(data);

    return 0;
}
