#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_io.h"
#include "status.h"


// return Status

// check file format
// in-place check



// Status data_check



//################################################=-> std <-=################################################//



// ok!
void data_write_std(const Data *data, const int data_len) {
    printf("%d\n", data_len);

    for (int i = 0; i < data_len; i++) {
        printf("%s\n", data[i].id);
        printf("%s\n", data[i].name);
        printf("%d\n", data[i].quantity);
    }
}


// error --> print error --> continue with zero/spaces/default value


static Status get_id(FILE *stream, Data *data) {
    data->id[0] = '\0';

    char c = getc(stream);
    int i = 0;
    for (; c != '\n' && c != EOF && i < ID_LEN - 1; i++) {
        data->id[i] = c;
        c = getc(stream);
    }

    if (c == EOF) return Eof;

    if (c == '\n' && i == ID_LEN - 1) {
        // printf("%d\n", i);
        data->id[ID_LEN - 1] = '\0';
        return Success;
    }

    fprintf(stderr, "[Error] Invalid input.\n");
    data->id[0] = '\0';
    if (c != '\n') {
        while (getc(stream) != '\n');
    }

    return Invalid_input;
}

static Status get_name(FILE *stream, Data *data) {
    data->name = NULL;

    char c = getc(stream);
    int i = 0;
    for (; c != '\n' && c != EOF; i++) {
        data->name = (char*) realloc(data->name, (i + 1) * sizeof(char));
        data->name[i] = c;
        c = getc(stream);
        // printf("%s\n", data->name);
    }

    if (c == EOF) return Eof;

    data->name = (char*) realloc(data->name, (i + 1) * sizeof(char));
    data->name[i] = '\0';

    return Success;
}


static Status get_number(FILE *stream, int *num) {
    *num = 0;

    int status = fscanf(stream, "%d", num);

    if (status == EOF) {
        return Eof;
    }

    // if (status == 0) while (getc(stream) != '\n');
    while (getc(stream) != '\n');

    if (status != 1 || *num < 1) {
        fprintf(stderr, "[Error] Invalid input.\n");
        // *num = 1;
        return Invalid_input;
    }

    return Success;
}


// ok!
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
    if (st == Invalid_input) *data_len = 1;
    printf("Number of structs -> %d\n\n", *data_len);
    if (*data_len < 1) *data_len = 1;

    int i = 0;
    for (; i < *data_len; i++) {
        printf("Struct %d\n", i + 1);

        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));

        printf("id: ");
        st = get_id(stdin, *data + i);
        if (st == Eof) break;
        // printf("!! |%s|\n", (*data)[i].id);

        printf("name: ");
        get_name(stdin, *data + i);
        if (st == Eof) break;
        // printf("!! |%s|\n", (*data)[i].name);

        printf("quantity: ");
        get_number(stdin, (int*) &((*data)[i].quantity));
        if (st == Eof) break;
        if (st == Invalid_input) (*data)[i].quantity = 1;
        if ((*data)[i].quantity < 1) (*data)[i].quantity = 1;
        // printf("!! %d\n", (*data)[i].quantity);
    }
    // if (i < *data_len - 1) {
    if (st != Success) {
        printf("\n");
        *data = (Data*) realloc(*data, (i - 1) * sizeof(Data));
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
Status data_write_text(const char *filename, const Data *data, const int data_len) {
    FILE *f = fopen(filename, "w");
    if (feof(f) || ferror(f)) {
        fclose(f);
        return File_open_fault;
    }

    fprintf(f, "%d\n", data_len);
    for (int i = 0; i < data_len; i++) {
        fprintf(f, "%s\n", data[i].id);
        fprintf(f, "%s\n", data[i].name);
        fprintf(f, "%d\n", data[i].quantity);
    }

    fclose(f);
    return Success;
}


Status data_read_text(const char *filename, Data **data, int *data_len) {
    *data = NULL;
    *data_len = 0;
    Status st = Failure;

    if (!does_file_exists(filename)) {
        fprintf(stderr, "[Error] Input file does not exists.\n");
        return File_open_fault;
    }

    FILE *f = fopen(filename, "r");

    st = get_number(f, data_len);

    // printf("%d\n", *data_len);
    if (*data_len < 1 || st == Eof) {
        fclose(f);
        return Data_format_fault;
    }

    int i = 0;
    for (; i < *data_len; i++) {
        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));

        // id
        st = get_id(f, *data + i);
        if (st != Success) break;
        // printf("!! |%s|\n", (*data)[i].id);

        // name
        st = get_name(f, *data + i);
        if (st != Success) break;
        // printf("!! |%s|\n", (*data)[i].name);

        // quantity
        get_number(f, (int*) &((*data)[i].quantity));
        if (st != Success) break;
        // printf("%d\n", (*data)[i].quantity);
    }
    if (st != Success) {
        *data = (Data*) realloc(*data, (i - 1) * sizeof(Data));
        fclose(f);
        return Data_format_fault;
    }

    fclose(f);

    return Success;
}



//################################################=-> bin <-=################################################//



Status data_write_bin(const char *filename, const Data *data, const int data_len) {
    FILE *f = fopen(filename, "w+b");
    if (feof(f) || ferror(f)) {
        fclose(f);
        return File_open_fault;
    }

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
    return Success;
}

Status data_read_bin(const char *filename, Data **data, int *data_len) {
    *data = NULL;
    *data_len = 0;

    if (!does_file_exists(filename)) {
        fprintf(stderr, "[Error] Input file does not exists.\n");
        return File_open_fault;
    }

    FILE *f = fopen(filename, "r+b");

    fread(data_len, sizeof(*data_len), 1, f);

    // printf("%d\n", *data_len);
    if (*data_len < 1 || feof(f) || ferror(f)) {
        fclose(f);
        return Data_format_fault;
    }

    int i = 0;
    for (; i < *data_len; i++) {
        *data = (Data*) realloc(*data, (i + 1) * sizeof(Data));

        // always 8
        fread((*data)[i].id, sizeof(char), ID_LEN, f);
        if (feof(f) || ferror(f)) break;
        // printf("%s\n", (*data)[i].id);

        // size of next object
        // int l = strlen(data[i].name) + 1;
        int l;
        fread(&l, sizeof(l), 1, f);
        if (feof(f) || ferror(f)) break;
        // printf("%d\n", l);
        (*data)[i].name = (char*) calloc(l, sizeof(char));
        fread((*data)[i].name, sizeof(char), l, f);
        if (feof(f) || ferror(f)) break;
        // printf("%s\n", (*data)[i].name);

        fread(&((*data)[i].quantity), sizeof(unsigned int), 1, f);
        if (feof(f) || ferror(f)) break;
        // printf("%d\n", (*data)[i].quantity);
    }
    if (feof(f) || ferror(f)) {
        *data = (Data*) realloc(*data, (i - 1) * sizeof(Data));
        fclose(f);
        return Data_format_fault;
    }

    fclose(f);
    return Success;
}



// int main() {
//
//     Data *data = NULL;
//     int data_len = 0;
//
//     // data_read_std(&data, &data_len);
//     // data_read_text("/home/Cyber_Wolf/Programs/5_university/informatics/lab5/tests/1_text", &data, &data_len);
//     data_read_bin("/home/Cyber_Wolf/Programs/5_university/informatics/lab5/tests/1_bin", &data, &data_len);
//
//
//     for (int i = 0; i < data_len; i++) {
//         printf("%s\n", data[i].id);
//         printf("%s\n", data[i].name);
//         printf("%d\n", data[i].quantity);
//         free(data[i].name);
//     }
//     free(data);
//
//     return 0;
// }
