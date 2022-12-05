#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "d_ll_functions.h"

// valgrind --leak-check=full ./debug_tests_d_ll

void test_init_list(void)
{
    double_linked_list *liste;
    liste = d_ll_get_new_elem(4);

    CU_ASSERT(liste->next == NULL);
    CU_ASSERT(liste->prev == NULL);
    CU_ASSERT(liste->number == 4);
    d_ll_free(&liste);
}

void test_d_ll_push_elem(void)
{
    double_linked_list *liste = d_ll_get_new_elem(1);
    double_linked_list *ptr = liste;

    d_ll_push_elem(liste, d_ll_get_new_elem(2));
    d_ll_push_elem(liste, d_ll_get_new_elem(3));

    ptr = ptr->next;

    CU_ASSERT(liste->number == 1);
    CU_ASSERT(ptr->prev->number == 1);
    CU_ASSERT(ptr->next->number == 3);

    ptr = ptr->next;

    CU_ASSERT(ptr->next == NULL);
    CU_ASSERT(ptr->prev->number == 2);

    d_ll_free(&liste);
}

void test_pop(void)
{
    double_linked_list *liste = d_ll_get_new_elem(1);

    d_ll_push_elem(liste, d_ll_get_new_elem(2));
    d_ll_push_elem(liste, d_ll_get_new_elem(3));
    d_ll_pop(&liste);

    CU_ASSERT(liste->number == 2);
    CU_ASSERT(liste->prev == NULL);
    CU_ASSERT(liste->next->number == 3);
    CU_ASSERT(liste->next->next == NULL);
    d_ll_free(&liste);
}

void test_length(void)
{
    int length;
    double_linked_list *liste = d_ll_get_new_elem(1);

    d_ll_push_elem(liste, d_ll_get_new_elem(2));
    d_ll_push_elem(liste, d_ll_get_new_elem(3));

    length = d_ll_length(liste);

    CU_ASSERT(length == 3);

    d_ll_pop(&liste);
    length = d_ll_length(liste);

    CU_ASSERT(length == 2);

    d_ll_free(&liste);
}

void test_ll_add_index(void)
{
    double_linked_list *liste = d_ll_get_new_elem(1);
    double_linked_list *liste2 = d_ll_get_new_elem(6);
    d_ll_push_elem(liste, d_ll_get_new_elem(2));
    d_ll_push_elem(liste, d_ll_get_new_elem(3));

    d_ll_add_index(&liste, 1, liste2);

    double_linked_list *ptr = liste;
    ptr = ptr->next;
    CU_ASSERT(liste->number == 1);
    CU_ASSERT(ptr->number == 6);
    CU_ASSERT(ptr->prev->number == 1);
    CU_ASSERT(ptr->next->number == 2);
    CU_ASSERT(ptr->number == 6);
    CU_ASSERT(liste->next->next->number == 2);
    CU_ASSERT(liste->next->next->next->number == 3);

    d_ll_free(&liste);
}

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main()
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if (
        NULL == CU_add_test(pSuite, "test of test_init_list()", test_init_list) ||
        NULL == CU_add_test(pSuite, "test of test_d_ll_push_elem()", test_d_ll_push_elem) ||
        NULL == CU_add_test(pSuite, "test of test_pop()", test_pop) ||
        NULL == CU_add_test(pSuite, "test of test_length()", test_length) ||
        NULL == CU_add_test(pSuite, "test of test_ll_add_index()", test_ll_add_index)

    )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
