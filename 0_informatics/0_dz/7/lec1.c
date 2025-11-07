#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void print_arr(const int *arr, int arr_len) {
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int arr_len) {
    for (int i = 0; i < arr_len - 1; i++) {
        for (int g = arr_len - 1; g < i; g++) {
            if (arr[g - 1] > arr[g]) {
                int tmp = arr[g - 1];
                arr[g - 1] = arr[g];
                arr[g] = tmp;
            }
        }
    }
}



int main() {
    srand(time(NULL));

    int arr_len = rand() % 100;
    int *arr = malloc(sizeof(int) * arr_len);
    for (int i = 0; i < arr_len; i++) {
        arr[i] = rand() % 100;
    }

    printf("Before:\n");
    print_arr(arr, arr_len);

    bubble_sort(arr, arr_len);


    printf("After:\n");
    print_arr(arr, arr_len);



    return 0;
}
