#include <stdio.h>
#include <ctype.h>
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
    free((*list)[index].name);
    for (int i = index; i < *list_len - 1; i++) {
        (*list)[i] = (*list)[i + 1];
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



void get_string(char **s) {
    *s = NULL;
    int len = 0;
    char c;

    while ((c = getchar()) != '\n') {
        len++;
        *s = (char*) realloc(*s, sizeof(char) * len);
        (*s)[len - 1] = c;
    }

    // // clear input buffer
    // if (c != '\n') {
    //     while (getchar() != '\n');
    // }
}


void menu_add(Product **list, int *list_len) {
    Product p;

    printf("Name: ");
    get_string(&p.name);
    printf("Cost: ");
    scanf("%d", &p.cost);
    printf("Quantity: ");
    scanf("%d", &p.quantity);
    printf("Unit: ");
    scanf("%d", &p.unit);

    list_add(list, list_len, p);
}

void menu_del(Product **list, int *list_len) {
    int index;
    printf("Enter index of product: ");
    scanf("%d", &index);

    list_del(list, list_len, index - 1);
}

void menu_edit(Product **list, int *list_len) {
    int index;
    printf("Enter index of product: ");
    scanf("%d", &index);
    index--;

    // clear input buffer
    while (getchar() != '\n');

    printf("Name[%s]: ", (*list)[index].name);
    get_string(&(*list)[index].name);
    printf("Cost[%d]: ", (*list)[index].cost);
    scanf("%d", &(*list)[index].cost);
    printf("Quantity[%d]: ", (*list)[index].quantity);
    scanf("%d", &(*list)[index].quantity);
    printf("Unit[%d]: ", (*list)[index].unit);
    scanf("%d", &(*list)[index].unit);
}

int comp_name(const void *a, const void *b) {
    const char *s1 = ((const Product*) a)->name;
    const char *s2 = ((const Product*) b)->name;
    int r = strcmp(s1, s2);

    printf("%s and %s = %d\n", s1, s2, r);

    if (r > 0) return 1; // a > b
    if (r < 0) return -1; // b > a

    return 0; // b == a
}

int comp_tcost(const void *a, const void *b) {
    Product *p1 = (Product*) a;
    Product *p2 = (Product*) b;
    int r = p1->cost * p1->unit * p1->quantity > p2->cost * p2->unit * p2->quantity;

    printf("%d and %d = %d\n", ((Product*) a)->unit, ((Product*) b)->unit, r);

    if (r > 0) return 1; // a > b
    if (r < 0) return -1; // b > a

    return 0; // b == a
}

void menu_sort_name(Product **list, int *list_len) {
    qsort(*list, *list_len, sizeof(Product), comp_name);
}




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


    // menu_add(&list, &list_len);
    // print_list(list, list_len);

    // print_list(list, list_len);
    // menu_del(&list, &list_len);
    // print_list(list, list_len);

    // print_list(list, list_len);
    // menu_edit(&list, &list_len);
    // print_list(list, list_len);

    print_list(list, list_len);
    menu_sort_name(&list, &list_len);
    print_list(list, list_len);



    return 0;



    const int action_count = 7;


    while (1) {
        print_list(list, list_len);

        printf("\n\n[0] Add element\n");
        printf("[1] Delete element\n");
        printf("[2] Edit element\n");
        printf("[3] Sort list by name\n");
        printf("[4] Sort list by total cost\n");
        printf("[5] Info by product\n");
        printf("[6] Clean list\n");
        printf("Action: ");


        int c = getchar();
        printf("\n");

        if (isdigit(c)) {
            if (c - '0' < action_count) {
                printf("Action %c\n", c);

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
                    // case '3':
                    //     menu_sort_name(&list, &list_len);
                    //     break;
                    // case '4':
                    //     menu_sort_tcost(&list, &list_len);
                    //     break;
                    // case '5':
                    //     menu_edit(&list, &list_len);
                    //     break;
                    // case '6':
                    //     menu_edit(&list, &list_len);
                    //     break;
                }

            } else {
                printf("Out of range!\n");
            }
        } else {
            if (c == EOF) {
                printf("Quitting...\n");
                break;
            }
            printf("Incorrect input!\n");
        }

        // clear input buffer
        if (c != '\n') {
            while (getchar() != '\n');
        }
    }





    return 0;
}
