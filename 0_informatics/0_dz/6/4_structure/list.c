#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"



void print_list(Product *list, int list_len) {
    if (list_len == 0) {
        printf("<List is empty>\n");
    }

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

    if (*list_len == 1) {
        (*list_len)--;
        free(*list);
        *list = NULL;
        return;
    }

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
