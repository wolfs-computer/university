#include <stdio.h>



int main() {

    // // 1_2 9_8 3_4 7_6 5_
    // int n = 9;
    // int arr[] = {
    //     1, 2, 3, 4, 5, 6, 7, 8, 9
    // };

    // 1_2 11_10 3_4 9_8 5_6 7_
    int n = 11;
    int arr[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    };

    // // 1_2 8_7 3_4 6_5
    // int n = 8;
    // int arr[] = {
    //     1, 2, 3, 4, 5, 6, 7, 8
    // };

    // // 1_2 6_5 3_4
    // int n = 6;
    // int arr[] = {
    //     1, 2, 3, 4, 5, 6
    // };


    int flag = 1;
    int i = 0;
    int g = n - 1;

    // + 1 because i++ and g-- change indexes for future iterations
    // therefore to reflect actual position increase g or decrease i.
    while (i != g + 1) {
        // if opp -> n - i - 1
        // if norm-> i

        if (flag) {
            printf("%d ", arr[i]);
            i++;
            flag = !(i % 2 == 0);
        } else {
            printf("%d ", arr[g]);
            g--;
            flag = ((n - 1 - g) % 2 == 0);
        }
    }
    printf("\n");


    return 0;
}
