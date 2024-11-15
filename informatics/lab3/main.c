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

    if (is_option_num && (*number < 1 && *number > 5)) {
        printf("Error: incorrect value!\n");
        return Incorrect_value;
    }

    return Success;
}


Status initialize_array(int **array, int *len) {

    int oper_status = array_init(array);

    if (oper_status == Memory_fault) {
        printf("Error: failed to allocate memory\n");
        return Memory_fault;
    }

    *len = 0;

    return Success;
}


Status insert_element(int **array, int *len) {

    printf("Enter index: ");
    int index;
    int input_status1 = get_input(&index, 0);
    if (input_status1 != Success) return input_status1;

    printf("Enter value: ");
    int value;
    int input_status2 = get_input(&value, 0);
    if (input_status2 != Success) return input_status2;

    int oper_status = array_insert_element(array, len, index, value);
    if (oper_status == Memory_fault) {
        printf("Error: failed to allocate memory\n");
        return Memory_fault;
    }
    if (oper_status == Invalid_index) {
        printf("Error: incorrect index!\n");
        return Invalid_index;
    }

    return Success;
}


Status delete_element(int **array, int *len) {

    printf("Enter index: ");
    int index;
    int input_status1 = get_input(&index, 0);
    if (input_status1 != Success) return input_status1;

    int oper_status = array_delete_element(array, len, index);
    if (oper_status == Invalid_index) {
        printf("Error: incorrect index!\n");
        return Invalid_index;
    }

    return Success;
}


Status sort_digits(int *num) {
    int *digits;
    int len = 0;

    int sign = 1;
    if (*num < 0) sign = -1;

    int operation_status = initialize_array(&digits, &len);
    if (operation_status != Success) return Failure;

    while (*num != 0) {
        int digit = *num % 10;
        *num /= 10;

        if (len == 0) {
            digits[0] = digit;
            len = 1;
            continue;
        }

        int i = 0;
        while (i < len) {
            printf("\n%d %d %d\n", digits[i], digit, digits[i] >= digit);
            if (digits[i] >= digit) {
                print_array(digits, len);
                operation_status = array_insert_element(&digits, &len, i, digit);
                if (operation_status != Success) return Failure;
                break;
            }

            i++;
        }
    }

    int new_num = 0;
    for (int i = 0; i < len; i++) {
        new_num += digits[i] * ((int) pow(10, i));
    }

    *num = new_num * sign;

    return Success;
}

Status rearrange_array(int **array, int *len) {

    if (*len == 0) return Empty_array;

    int i = 0;

    while(i < *len) {
        int old = (*array)[i];
        // printf("\nold -> %d\n", old);
        sort_digits(*array + i);

        if (old == (*array)[i]) {
            int operation_status = array_delete_element(array, len, i);
            if (operation_status != Success) return Failure;
            printf("\nsame\n");
        } else {
            i++;
        }
    }

    return Success;
}



int main() {

    int option_number;
    Status input_status;

    int *array; 
    int array_len;

    // at start array should be NULL
    Status operation_status = initialize_array(&array, &array_len);
    if (operation_status != Success) return Failure;


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


        // if option_number
        Status operation_status;

        if (option_number == 1) {
            operation_status = initialize_array(&array, &array_len);

        } else if (option_number == 2) {
            operation_status = insert_element(&array, &array_len);

        } else if (option_number == 3) {
            operation_status = delete_element(&array, &array_len);

        } else if (option_number == 4) {
            operation_status = rearrange_array(&array, &array_len);
        }

        if (operation_status == Eof) break;
        if (operation_status != Success) continue;


        // print array anyway
        print_array(array, array_len);
    }

    free(array);


    return 0;
}
