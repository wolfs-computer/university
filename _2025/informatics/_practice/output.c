#include <stdio.h>


void draw_rectangle(int len, int width) {

    for (int row = 0; row < width; row++) {
        for (int col = 0; col < len; col++) {
            printf("*");
        }
        printf("\n");
    }
}


int main() {


    int len;
    int width;

    scanf("%d", &len);
    scanf("%d", &width);

    draw_rectangle(len, width);



    return 0;
}
