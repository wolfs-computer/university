#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"
#include "menu.h"



int main() {
    srand(time(NULL));

    // starter product names
    int names_len = 5;
    char *possible_names[names_len];
    possible_names[0] = strdup("sugar");
    possible_names[1] = strdup("flour");
    possible_names[2] = strdup("oranges");
    possible_names[3] = strdup("milk");
    possible_names[4] = strdup("noodles");

    // declare list with uninitialized Products
    int list_len = 5;
    Product *list = (Product*) malloc(list_len * sizeof(Product));

    // initialize starting products
    for (int i = 0; i < list_len; i++) {
        list[i].name = possible_names[i];
        list[i].cost = rand() % 5 + 1;
        list[i].quantity = rand() % 1000 + 1;
        list[i].unit = rand() % 1000 + 1;
    }


    while (1) {
        printf("\n\n");
        print_list(list, list_len);

        printf("\n[0] Add element\n");
        printf("[1] Delete element\n");
        printf("[2] Edit element\n");
        printf("[3] Sort list by name\n");
        printf("[4] Sort list by total cost\n");
        printf("[5] Info by product\n");
        printf("[6] Clean list\n");
        printf("Action: ");


        int c = getchar();
        printf("\n");

        if (!isdigit(c)) {
            if (c == EOF) {
                printf("Quitting...\n");
                break;
            }
            printf("Incorrect input!\n");
            continue;
        }

        // clear input buffer
        if (c != '\n') {
            while (getchar() != '\n');
        }

        if (c - '0' < 7) {
            switch (c) {
                case '0':
                    menu_add(&list, &list_len);
                    break;
                case '1':
                    menu_del(&list, &list_len);
                    break;
                case '2':
                    menu_edit(&list, &list_len);
                    break;
                case '3':
                    menu_sort_name(&list, &list_len);
                    break;
                case '4':
                    menu_sort_tcost(&list, &list_len);
                    break;
                case '5':
                    menu_info(&list, &list_len);
                    break;
                case '6':
                    menu_clear(&list, &list_len);
                    break;
            }
        } else {
            printf("Out of range!\n");
        }
    }

    menu_clear(&list, &list_len);



    return 0;
}
