#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_functions.h"

int main()
{
    Liste *liste;
    int length;

    printf("Initialisation :\n");
    liste = init_list(1);
    ll_print(liste);

    printf("Ajout d'un élément :\n");
    ll_get_new_elem(liste, 2);
    ll_get_new_elem(liste, 3);
    ll_get_new_elem(liste, 4);
    ll_get_new_elem(liste, 5);
    ll_get_new_elem(liste, 6);
    ll_get_new_elem(liste, 7);
    ll_print(liste);

    printf("Suppression du premier élément :\n");
    ll_pop(&liste);
    ll_print(liste);

    printf("Taille de la liste :\n");
    length = ll_length(liste);
    printf("%d \n", length);

    printf("Ajout de 4 à la place 1 :\n");
    Liste *liste2;
    liste2 = init_list(4);
    ll_add_index(&liste, 1, liste2);
    ll_print(liste);

    printf("Swap place 1 et 2 :\n");
    ll_swap_index(&liste, 1, 2);
    ll_print(liste);

    printf("Invertion de la liste :\n");
    ll_reverse(&liste);
    ll_print(liste);

    printf("Suppression de la liste :\n");
    ll_free(&liste);
    ll_print(liste);

    return 0;
}