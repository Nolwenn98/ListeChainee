#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "d_ll_functions.h"

int main()
{
    double_linked_list *liste;
    int length;

    printf("Initialisation :\n");
    liste = d_ll_get_new_elem(1);
    d_ll_print(liste);

    printf("Taille de la liste :\n");
    length = d_ll_length(liste);
    printf("%d \n", length);

    printf("Ajout d'un élément :\n");
    d_ll_push_elem(liste, d_ll_get_new_elem(2));
    d_ll_push_elem(liste, d_ll_get_new_elem(3));
    d_ll_push_elem(liste, d_ll_get_new_elem(4));
    d_ll_push_elem(liste, d_ll_get_new_elem(5));

    d_ll_print(liste);

    printf("Suppression du premier élément :\n");
    d_ll_pop(&liste);
    d_ll_print(liste);

    printf("Ajout de 6 à la place 1 :\n");
    double_linked_list *liste2 = d_ll_get_new_elem(6);
    d_ll_add_index(&liste, 1, liste2);
    d_ll_print(liste);

    printf("Suppression de la liste :\n");
    d_ll_free(&liste);
    d_ll_print(liste);

    return 0;
}