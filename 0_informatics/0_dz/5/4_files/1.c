#include <stdio.h>
#include <stdlib.h>




int main() {

    FILE *file = fopen("1.txt", "r");
    if (!file) {
        printf("Error openinig file!");
        return 1;
    }

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
