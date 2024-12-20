#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "status.h"
#include "array_functions.h"



Status get_input(int *number, int is_option_num) {

    int input_status = scanf("%d", number);

    if (input_status == EOF) {
        printf("\nEOF!\n");
        return Eof;
    }

    while (getchar() != '\n');

    if (input_status != 1) {
        printf("Error: invalid input!\n");
        return Invalid_input;
    }

    if (is_option_num && (*number < 1 || *number > 5)) {
        printf("Error: incorrect value!\n");
        return Incorrect_value;
    }

    return Success;
}


Status initialize_array(int **array, int *len) {

    *len = 0;

    Status input_status;

    printf("Enter number of elements: ");
    int count;
    input_status = get_input(&count, 0);
    if (input_status != Success) return input_status;

    int value;
    for (int i = 0; i < count; i++) {

        printf("Enter element value: ");
        input_status = get_input(&value, 0);
        if (input_status != Success) return input_status;

        Status oper_status = array_insert_element(array, len, i, value);
        if (oper_status != Success) return oper_status;
    }

    return Success;
}


Status insert_element(int **array, int *len) {

    Status input_status;

    printf("Enter index: ");
    int index;
    input_status = get_input(&index, 0);
    if (input_status != Success) return input_status;

    printf("Enter value: ");
    int value;
    input_status = get_input(&value, 0);
    if (input_status != Success) return input_status;

    Status oper_status = array_insert_element(array, len, index, value);
    if (oper_status != Success) return oper_status;

    return Success;
}


Status delete_element(int **array, int *len) {

    printf("Enter index: ");
    int index;
    Status input_status = get_input(&index, 0);
    if (input_status != Success) return input_status;

    Status oper_status = array_delete_element(array, len, index);
    if (oper_status != Success) return oper_status;

    return Success;
}


Status sort_digits(int num, int *new_num) {

    int *digits = NULL;
    int len = 0;

    int sign = 1;
    if (num < 0) sign = -1;
    num *= sign;

    while (num != 0) {

        int digit = num % 10;
        num /= 10;

        int i = 0;
        while (i < len) {
            if (digits[i] >= digit) break;
            i++;
        }

        Status operation_status = array_insert_element(&digits, &len, i, digit);
        if (operation_status != Success) return operation_status;
    }

    *new_num = 0;
    for (int i = 0; i < len; i++) {
        *new_num += digits[i] * pow(10, i);
    }

    free(digits);

    *new_num *= sign;

    return Success;
}

Status rearrange_array(int **array, int *len, int **new_array, int *new_array_len) {

    if (*len == 0) return Success;

    Status operation_status;

    int i = 0;
    int g = 0;
    while(i < *len) {

        int old = (*array)[i];

        int new;
        operation_status = sort_digits(old, &new);
        if (operation_status != Success) return operation_status;

        operation_status = array_insert_element(new_array, new_array_len, g, new);
        if (operation_status != Success) return operation_status;
        g++;

        if (old == new) {
            int operation_status = array_delete_element(array, len, i);
            if (operation_status != Success) return operation_status;
        } else {
            i++;
        }
    }

    return Success;
}



int main() {

    int option_number;
    Status input_status;

    int *array = NULL;
    int array_len = 0;


    while (1) {
        printf(
            "\n----> MENU <----\n"
            "1) Initialize array\n" // insert multiply elemetns in cycle // enter number of new elements/ or stop symbol
            "2) Insert new element\n"
            "3) Delete element\n"
            "4) Individual task: rearrange numbers in elements\n" // create an array (outside: print it and destroy)
            "5) Display array content\n" // do nothing
            "\n"
            "Choose an option: "
        );

        input_status = get_input(&option_number, 1);

        if (input_status == Eof) break;
        if (input_status != Success) continue;


        // if just display an array
        Status operation_status = Success;

        if (option_number == 1) {
            operation_status = initialize_array(&array, &array_len);

        } else if (option_number == 2) {
            operation_status = insert_element(&array, &array_len);

        } else if (option_number == 3) {
            operation_status = delete_element(&array, &array_len);

        } else if (option_number == 4) {
            int *new_array = NULL;
            int new_array_len = 0;

            operation_status = rearrange_array(&array, &array_len, &new_array, &new_array_len);

            print_array(new_array, new_array_len);
            printf("\n");

            free(new_array);
        }

        
        if (operation_status == Memory_fault) printf("Error: memory fault!\n");;
        if (operation_status == Invalid_index) printf("Error: invalid index!\n");;
        if (operation_status == Empty_array) printf("Error: array is empty!\n");;

        if (operation_status == Eof) break;
        if (operation_status != Success) continue;


        // print array anyway
        print_array(array, array_len);
    }

    free(array);


    return 0;
}
