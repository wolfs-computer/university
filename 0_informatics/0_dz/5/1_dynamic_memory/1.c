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

    // sort
    for (int i = 0; i < rows * cols; i++) {
        for (int g = 0; g < rows * cols - 1; g++) {
            // [i / cols][i % cols]
            int current = arr[g / cols][g % cols];
            int next = arr[(g + 1) / cols][(g + 1) % cols];

            // swap
            if (current > next) {
                arr[g / cols][g % cols] = next;
                arr[(g + 1) / cols][(g + 1) % cols] = current;
            }
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
