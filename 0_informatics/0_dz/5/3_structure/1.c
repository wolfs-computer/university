#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*

1) Edit or add new products.
2) Sort by name or general price(cost * quantity * unit).
3) Print info about entered product (by name).
4) ???

*) Print whole list.

*/



typedef struct _Product {
    char *name;
    int cost;
    int quantity;
    int unit;
} Product;



void print_list(Product *list, int list_len) {
    for (int i = 0; i < list_len; i++) {
        printf("Product \"%s\":\n", list[i].name);
        printf("\tCost: %d\n"    , list[i].cost);
        printf("\tQuantity: %d\n", list[i].quantity);
        printf("\tUnit: %d\n"    , list[i].unit);
    }
    printf("\n");
}



int main() {
    srand(time(NULL));

    // starter product names
    int names_len = 5;
    char *possible_names[names_len];
    possible_names[0] = "sugar";
    possible_names[1] = "flour";
    possible_names[2] = "oranges";
    possible_names[3] = "milk";
    possible_names[4] = "noodles";

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

    print_list(list, list_len);




    return 0;
}
