#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list_functions.h"

// valgrind --leak-check=full ./debug_tests_list

void test_init_list(void)
{
    Liste *liste;
    liste = init_list(4);

    CU_ASSERT(liste->next == NULL);
    CU_ASSERT(liste->number == 4);
    ll_free(&liste);
}

void test_add_element(void)
{
    Liste *liste;
    liste = init_list(1);

    ll_get_new_elem(liste, 2);
    ll_get_new_elem(liste, 3);
    ll_get_new_elem(liste, 4);

    CU_ASSERT(liste->number == 1);
    CU_ASSERT(liste->next->number == 2);
    CU_ASSERT(liste->next->next->number == 3);
    CU_ASSERT(liste->next->next->next->number == 4);
    ll_free(&liste);
}

void test_pop(void)
{
    Liste *liste;
    liste = init_list(1);

    ll_get_new_elem(liste, 1);
    ll_get_new_elem(liste, 2);
    ll_pop(&liste);

    CU_ASSERT(liste->number == 1);
    CU_ASSERT(liste->next->number == 2);
    CU_ASSERT(liste->next->next == NULL);
    ll_free(&liste);
}

void test_length(void)
{
    Liste *liste;
    int length;
    liste = init_list(0);

    ll_get_new_elem(liste, 1);
    ll_get_new_elem(liste, 2);
    ll_get_new_elem(liste, 3);
    length = ll_length(liste);

    CU_ASSERT(length == 4);

    ll_pop(&liste);
    length = ll_length(liste);

    CU_ASSERT(length == 3);

    ll_free(&liste);
}

void test_ll_add_index(void)
{
    Liste *liste, *liste2;
    liste = init_list(0);
    liste2 = init_list(2);

    ll_get_new_elem(liste, 1);
    ll_get_new_elem(liste, 3);
    ll_add_index(&liste, 1, liste2);

    CU_ASSERT(liste->number == 0);
    CU_ASSERT(liste->next->number == 1);
    CU_ASSERT(liste->next->next->number == 2);
    CU_ASSERT(liste->next->next->next->number == 3);

    ll_free(&liste);
}

void test_ll_get_index(void)
{
    Liste *liste;
    int test1, test2;
    liste = init_list(0);

    ll_get_new_elem(liste, 1);
    ll_get_new_elem(liste, 3);
    test1 = ll_get_value_index(&liste, 0);
    test2 = ll_get_value_index(&liste, 2);

    CU_ASSERT(test1 == 0);
    CU_ASSERT(test2 == 3);

    ll_free(&liste);
}

void test_ll_swap_index(void)
{
    Liste *liste;
    liste = init_list(0);
    ll_get_new_elem(liste, 1);
    ll_get_new_elem(liste, 2);
    ll_get_new_elem(liste, 3);

    ll_swap_index(&liste, 1, 2);

    CU_ASSERT(liste->number == 0);
    CU_ASSERT(liste->next->number == 2);
    CU_ASSERT(liste->next->next->number == 1);
    CU_ASSERT(liste->next->next->next->number == 3);

    ll_swap_index(&liste, 0, 3);
    CU_ASSERT(liste->number == 3);
    CU_ASSERT(liste->next->number == 2);
    CU_ASSERT(liste->next->next->number == 1);
    CU_ASSERT(liste->next->next->next->number == 0);

    ll_free(&liste);
}

void test_ll_reverse(void)
{
    Liste *liste;
    liste = init_list(0);

    ll_get_new_elem(liste, 1);
    ll_get_new_elem(liste, 2);
    ll_get_new_elem(liste, 3);

    ll_reverse(&liste);

    CU_ASSERT(liste->number == 3);
    CU_ASSERT(liste->next->number == 2);
    CU_ASSERT(liste->next->next->number == 1);
    CU_ASSERT(liste->next->next->next->number == 0);

    ll_free(&liste);
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
        NULL == CU_add_test(pSuite, "test of test_add_element()", test_add_element) ||
        NULL == CU_add_test(pSuite, "test of test_pop()", test_pop) ||
        NULL == CU_add_test(pSuite, "test of test_length()", test_length) ||
        NULL == CU_add_test(pSuite, "test of test_ll_add_index()", test_ll_add_index) ||
        NULL == CU_add_test(pSuite, "test of test_ll_get_index()", test_ll_get_index) ||
        NULL == CU_add_test(pSuite, "test of test_ll_swap_index()", test_ll_swap_index) ||
        NULL == CU_add_test(pSuite, "test of test_ll_reverse()", test_ll_reverse)

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
