#include <stdio.h>



int main() {

    // file paths
    const char file_path1[] = "2.1.txt";
    const char file_path2[] = "2.2.txt";


    // open files
    FILE *file1 = fopen(file_path1, "r+");
    FILE *file2 = fopen(file_path2, "r");
    FILE *tmp_file = fopen("tmp", "w+");
    if (!file1 || !file2 || !tmp_file) {
        printf("Error opening file/s!");
        return 1;
    }

    // write to tmp file
    char c;
    while ((c = fgetc(file1)) != EOF) {
        if (c == '\n') {
            while ((c = fgetc(file2)) != EOF) {
                if (c == '\n') break;
                fputc(c, tmp_file);
            }
            c = '\n';
        }
        // write char to tmp file
        fputc(c, tmp_file);
    }
    fclose(file2);

    // copy content of tmp_file to file1
    fseek(file1, 0, SEEK_SET);
    fseek(tmp_file, 0, SEEK_SET);
    while ((c = fgetc(tmp_file)) != EOF) {
        fputc(c, file1);
    }

    // close all files
    fclose(file1);
    fclose(tmp_file);



    return 0;
}
