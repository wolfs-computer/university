#ifndef _MENU_H_
#define _MENU_H_



#include "list.h"



void menu_add(Product **list, int *list_len);
void menu_del(Product **list, int *list_len);
void menu_edit(Product **list, int *list_len);
int comp_name(const void *a, const void *b);
int comp_tcost(const void *a, const void *b);
void menu_sort_name(Product **list, int *list_len);
void menu_sort_tcost(Product **list, int *list_len);
void menu_clear(Product **list, int *list_len);
void menu_info(Product **list, int *list_len);



#endif
