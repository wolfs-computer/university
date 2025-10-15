#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void print_arr(int **arr, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}



int main() {
    srand(time(NULL));

    int **arr = NULL;
    int rows = 10; // > 1
    int cols = 10; // > 1

    // initialize with random numbers
    arr = (int**) malloc(rows * sizeof(int*));
    for (int row = 0; row < rows; row++) {
        arr[row] = (int*) malloc(cols * sizeof(int));

        for (int col = 0; col < cols; col++) {
            arr[row][col] = rand() % 1000;
        }
    }

    print_arr(arr, rows, cols);

    // find max and min
    int min = arr[0][0];
    int max = arr[0][0];
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int num = arr[row][col];
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }
    }
    // printf("Min: %d\n", min);
    // printf("Max: %d\n\n", max);

    // change all values
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            arr[row][col] = min + max - min; // ???
        }
    }


    print_arr(arr, rows, cols);


    // free memory
    for (int row = 0; row < rows; row++) {
        free(arr[row]);
    }
    free(arr);


    return 0;
}
