#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"



static void get_string(char **s) {
    *s = NULL;
    int len = 0;
    char c;

    while ((c = getchar()) != '\n') {
        len++;
        *s = (char*) realloc(*s, sizeof(char) * len);
        (*s)[len - 1] = c;
    }

    // \0 at the end
    len++;
    *s = (char*) realloc(*s, sizeof(char) * len);
    (*s)[len - 1] = '\0';
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

    // clear input buffer
    while (getchar() != '\n');

    list_add(list, list_len, p);
}

void menu_del(Product **list, int *list_len) {
    int index;
    printf("Enter index of product: ");
    scanf("%d", &index);

    // clear input buffer
    while (getchar() != '\n');

    if (index > *list_len || index < 1) {
        printf("Wrong index!\n");
        return;
    }

    list_del(list, list_len, index - 1);
}

void menu_edit(Product **list, int *list_len) {
    int index;
    printf("Enter index of product: ");
    scanf("%d", &index);

    if (index > *list_len || index < 1) {
        printf("Wrong index!\n");
        return;
    }

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

    // clear input buffer
    while (getchar() != '\n');
}


int comp_name(const void *a, const void *b) {
    return strcmp(((const Product*) a)->name, ((const Product*) b)->name);
}
int comp_tcost(const void *a, const void *b) {
    Product *p1 = (Product*) a;
    Product *p2 = (Product*) b;
    int r = p1->cost * p1->quantity > p2->cost * p2->quantity;

    if (r > 0) return 1; // a > b
    if (r < 0) return -1; // a < b

    return 0; // a == b
}

void menu_sort_name(Product **list, int *list_len) {
    qsort(*list, *list_len, sizeof(Product), comp_name);
}

void menu_sort_tcost(Product **list, int *list_len) {
    qsort(*list, *list_len, sizeof(Product), comp_tcost);
}


void menu_clear(Product **list, int *list_len) {
    int len = *list_len;
    for (int i = 0; i < len; i++) {
        list_del(list, list_len, 0);
    }
}


void menu_info(Product **list, int *list_len) {
    char *name;
    printf("Name: ");
    get_string(&name);

    int index = list_find(*list, *list_len, name);
    if (index == -1) {
        printf("Wrong name!\n");
        return;
    }

    list_show(*list, *list_len, index);
}
