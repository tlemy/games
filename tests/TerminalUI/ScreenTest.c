#include "../../include/TerminalUI/Screen.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>

static void test_whenInputStreamValid_drawSquare_returns0() 
{
    FILE *fptr = fopen("test1.txt", "w");

    CU_ASSERT_EQUAL(drawSquare(0, 0, 0, 0, 0, fptr), 0);

    fclose(fptr);
}

int main() 
{
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry()) 
    {
        return CU_get_error();
    }

    pSuite = CU_add_suite("TerminalUI/Screen", NULL, NULL);

    if (pSuite == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "returns success value", test_whenInputStreamValid_drawSquare_returns0) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_suite(pSuite);
    CU_cleanup_registry();
    return CU_get_error();
}