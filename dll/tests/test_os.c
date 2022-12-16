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

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_append);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
