#include <stdio.h>



int main() {

    // open file
    FILE *file = fopen("1.txt", "r");
    if (!file) {
        printf("Error opening file!");
        return 1;
    }

    // print quoited text
    int flag = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\'' || c == '\"') {
            flag = !flag;

            if (!flag) {
                printf("%c\n", c);
            }
        }
        if (flag) {
            printf("%c", c);
        }
    }


    fclose(file);


    return 0;
}
