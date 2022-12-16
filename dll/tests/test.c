#ifdef TEST
#endif

#include "../list.h"
#include "minunit.h"

MU_TEST(test_append)
{
    list_t liste = {.start = NULL, .end = NULL};
    element_t *element1, *element3;
    uint8_t data1 = 0, data2 = 1, data3 = 2;

    element1 = list_append(&liste, &data1);
    list_append(&liste, &data2);
    element3 = list_append(&liste, &data3);

    mu_check(liste.start->data == &data1);
    mu_check(liste.start->next->data == &data2);
    mu_check(liste.end->data == &data3);

    mu_check(liste.start == element1);
    mu_check(liste.end == element3);
}

MU_TEST(test_length)
{
    list_t liste = {.start = NULL, .end = NULL};

    for (uint8_t len = 0; len < 5; len++)
    {
        mu_assert_int_eq(len, list_length(&liste));
        list_append(&liste, 0);
    }
}

MU_TEST(test_prepend)
{

    list_t liste = {.start = NULL, .end = NULL};
    element_t *element1, *element3;
    uint8_t data1 = 0, data2 = 1, data3 = 2;

    element1 = list_prepend(&liste, &data1);
    list_prepend(&liste, &data2);
    element3 = list_prepend(&liste, &data3);

    mu_check(liste.start->data == &data3);
    mu_check(liste.start->next->data == &data2);
    mu_check(liste.end->data == &data1);

    mu_check(liste.start == element3);
    mu_check(liste.end == element1);
}

MU_TEST(test_pop_first)
{
    list_t liste = {.start = NULL, .end = NULL};
    element_t *element2, *element3;
    uint8_t data1 = 0, data2 = 1, data3 = 2;

    list_append(&liste, &data1);
    element2 = list_append(&liste, &data2);
    element3 = list_append(&liste, &data3);

    list_pop_first(&liste);

    mu_check(liste.start->data == &data2);
    mu_check(liste.end->data == &data3);

    mu_check(liste.start == element2);
    mu_check(liste.end == element3);
}

MU_TEST(test_pop_last)
{
    list_t liste = {.start = NULL, .end = NULL};
    element_t *element1, *element2;
    uint8_t data1 = 0, data2 = 1, data3 = 2;

    element1 = list_append(&liste, &data1);
    element2 = list_append(&liste, &data2);
    list_append(&liste, &data3);

    list_pop_last(&liste);

    mu_check(liste.start->data == &data1);
    mu_check(liste.end->data == &data2);

    mu_check(liste.start == element1);
    mu_check(liste.end == element2);
}

MU_TEST(test_insert_at_begin)
{
    // insert at 0
    list_t liste = {.start = NULL, .end = NULL};
    element_t *element1, *element_insert;
    uint8_t data1 = 0, data2 = 1, data3 = 2, data_insert = 5;

    element1 = list_append(&liste, &data1);
    list_append(&liste, &data2);
    list_append(&liste, &data3);

    element_insert = list_insert_at(&liste, &data_insert, 0);

    mu_check(liste.start->data == &data_insert);
    mu_check(liste.start->next == element1);
    mu_check(liste.start->previous == NULL);

    mu_check(liste.start == element_insert);
}
MU_TEST(test_insert_at)
{
    // insert at 1
    list_t liste = {.start = NULL, .end = NULL};
    element_t *element1, *element3, *element_insert;
    uint8_t data1 = 0, data2 = 1, data3 = 2, data_insert = 5;

    element1 = list_append(&liste, &data1);
    list_append(&liste, &data2);
    element3 = list_append(&liste, &data3);

    element_insert = list_insert_at(&liste, &data_insert, 1);

    mu_check(liste.start->next->data == &data_insert);
    mu_check(liste.start->next == element_insert);

    mu_check(liste.start == element1);
    mu_check(liste.end == element3);
}
MU_TEST(test_insert_at_end)
{
    // insert at end
    list_t liste = {.start = NULL, .end = NULL};
    element_t *element3, *element_insert;
    uint8_t data1 = 0, data2 = 1, data3 = 2, data_insert = 5;

    list_append(&liste, &data1);
    list_append(&liste, &data2);
    element3 = list_append(&liste, &data3);

    element_insert = list_insert_at(&liste, &data_insert, 3);

    mu_check(liste.end->data == &data_insert);
    mu_check(liste.end->previous == element3);
    mu_check(liste.end->next == NULL);

    mu_check(liste.end == element_insert);
}
MU_TEST(test_remove_at_begin)
{
    // remove at begin
    list_t liste = {.start = NULL, .end = NULL};
    element_t *element2, *element3;
    uint8_t data1 = 0, data2 = 1, data3 = 2;

    list_append(&liste, &data1);
    element2 = list_append(&liste, &data2);
    element3 = list_append(&liste, &data3);

    list_remove_at(&liste, 0);

    mu_check(liste.end == element3);
    mu_check(liste.start == element2);
    mu_check(liste.start->previous == NULL);
}

MU_TEST(test_remove_at)
{
    // remove at 1
    list_t liste = {.start = NULL, .end = NULL};
    element_t *element1, *element3;
    uint8_t data1 = 0, data2 = 1, data3 = 2;

    element1 = list_append(&liste, &data1);
    list_append(&liste, &data2);
    element3 = list_append(&liste, &data3);

    list_remove_at(&liste, 1);

    mu_check(liste.end == element3);
    mu_check(liste.start == element1);
    mu_check(liste.start->next == element3);
    mu_check(liste.end->previous == element1);
}

MU_TEST(test_remove_at_end)
{
    // remove at end
    list_t liste = {.start = NULL, .end = NULL};
    element_t *element1, *element2;
    uint8_t data1 = 0, data2 = 1, data3 = 2;

    element1 = list_append(&liste, &data1);
    element2 = list_append(&liste, &data2);
    list_append(&liste, &data3);

    list_remove_at(&liste, 2);

    mu_check(liste.end == element2);
    mu_check(liste.start == element1);
    mu_check(liste.end->next == NULL);
}

void test_map(void *data)
{
    *(uint8_t *)data *= 2;
}

MU_TEST(teslist_t_map)
{
    list_t liste = {.start = NULL, .end = NULL};
    uint8_t data1 = 0, data2 = 1, data3 = 2;

    list_append(&liste, &data1);
    list_append(&liste, &data2);
    list_append(&liste, &data3);

    list_map(&liste, test_map);

    mu_check(*(uint8_t *)liste.start->data == 0 * 2);
    mu_assert_int_eq(*(uint8_t *)liste.start->next->data, 1 * 2);
    mu_assert_int_eq(*(uint8_t *)liste.end->data, 2 * 2);
}

MU_TEST(teslist_t_index)
{
    list_t liste = {.start = NULL, .end = NULL};
    uint8_t data1 = 0, data2 = 1, data3 = 2, data4 = 3;

    list_append(&liste, &data1);
    list_append(&liste, &data2);
    list_append(&liste, &data3);

    mu_assert_int_eq(list_index(&liste, &data1), 0);
    mu_assert_int_eq(list_index(&liste, &data2), 1);
    mu_assert_int_eq(list_index(&liste, &data3), 2);
    mu_assert_int_eq(list_index(&liste, &data4), -1);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_append);
    MU_RUN_TEST(test_length);
    MU_RUN_TEST(test_prepend);
    MU_RUN_TEST(test_pop_first);
    MU_RUN_TEST(test_pop_last);
    MU_RUN_TEST(test_insert_at_begin);
    MU_RUN_TEST(test_insert_at);
    MU_RUN_TEST(test_insert_at_end);
    MU_RUN_TEST(test_remove_at_begin);
    MU_RUN_TEST(test_remove_at);
    MU_RUN_TEST(test_remove_at_end);
    MU_RUN_TEST(teslist_t_map);
    MU_RUN_TEST(teslist_t_index);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
