#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*

list of products.

product:
    name,
    cost of unit,
    quantity,
    units

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
        printf("%d) \"%s\":\n", i + 1, list[i].name);
        printf("\tCost: %d\n"    , list[i].cost);
        printf("\tQuantity: %d\n", list[i].quantity);
        printf("\tUnit: %d\n"    , list[i].unit);
    }
    printf("\n");
}


void list_add(Product **list, int *list_len, Product p) {
    (*list_len)++;
    *list = (Product*) realloc(*list, *list_len * sizeof(Product));
    
    (*list)[*list_len - 1] = p;
}

void list_del(Product **list, int *list_len, int index) {
    for (int i = index; i < *list_len - 1; i++) {
        (*list)[index] = (*list)[index + 1];
    }

    (*list_len)--;
    *list = (Product*) realloc(*list, *list_len * sizeof(Product));
}

int list_find(const Product *list, int list_len, const char *name) {
    for (int i = 0; i < list_len; i++) {
        if (strcmp(list[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void list_show(const Product *list, int list_len, int index) {
    printf("%d) \"%s\":\n", index + 1, list[index].name);
    printf("\tCost: %d\n"    , list[index].cost);
    printf("\tQuantity: %d\n", list[index].quantity);
    printf("\tUnit: %d\n"    , list[index].unit);
}

void list_edit(Product *list, int list_len, int index) {
    list_show(list, list_len, index);

    printf("New name: ");
    // input here i am lazy
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


    // TEST (OK): list_add()
    // Product p1 = {
    //     .name = "GH for h",
    //     .cost = 20,
    //     .quantity = 19,
    //     .unit = 1
    // };
    // list_add(&list, &list_len, p1);
    //
    // print_list(list, list_len);

    // TEST (OK): list_find()
    // printf("%d\n", list_find(list, list_len, "milk") + 1);

    // TEST (OK): list_del()
    // list_del(&list, &list_len, list_find(list, list_len, "milk"));
    // print_list(list, list_len);

    // TEST (OK): list_show()
    // list_show(list, list_len, 1);





    return 0;
}
