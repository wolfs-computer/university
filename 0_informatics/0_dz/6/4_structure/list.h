#ifndef _LIST_H_
#define _LIST_H_



/*
list of products.

product:
    name,
    cost of unit,
    quantity,
    units

1) Edit or del/add new products.
2) Sort by name or general price(cost * quantity * unit).
3) Print info about entered product (by name).
4) clear list.
*/



typedef struct _Product {
    char *name;
    int cost;
    int quantity;
    int unit;
} Product;



void print_list(Product *list, int list_len);
void list_add(Product **list, int *list_len, Product p);
void list_del(Product **list, int *list_len, int index);
int list_find(const Product *list, int list_len, const char *name);
void list_show(const Product *list, int list_len, int index);



#endif
