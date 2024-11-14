#include <stdio.h>
#include <stdlib.h>

#include "status.h"
#include "array_functions.h"



int get_input(int *number, int is_option_num) {

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


int initialize_array(int **array) {

    int oper_status = array_init(array);

    if (oper_status == Memory_fault) {
        printf("Error: failed to allocate memory\n");
        return Memory_fault;
    }

    return Success;
}


int insert_element(int **array, int *len) {

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


int delete_element(int **array, int *len) {

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


int rearrange_array(int **array, int *len) {

    return Success;
}



int main() {

    int option_number;
    int input_status;

    int *array; 
    int array_len = 0;

    int operation_status = initialize_array(&array);
    if (operation_status != Success) return Failure;


    while (1) {
        printf(
            "\n----> MENU <----\n"
            "1) Initialize array\n" // clear array
            "2) Insert new element\n"
            "3) Delete element\n"
            "4) Individual task: rearrange numbers in elements\n"
            "5) Display array content\n" // do nothing
            "\n"
            "Choose an option: "
        );

        input_status = get_input(&option_number, 1);

        if (input_status == Eof) break;
        if (input_status != Success) continue;


        // if option_number
        int operation_status;

        if (option_number == 1) {
            operation_status = initialize_array(&array);

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
