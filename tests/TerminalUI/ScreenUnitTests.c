#include "../../include/TerminalUI/Screen.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#define TEST_FILE_NAME "ScreenTest.txt"

static void test_whenInputStreamValid_drawSquare_returns0() 
{
    FILE *fptr = fopen(TEST_FILE_NAME, "w");

    CU_ASSERT_EQUAL(drawSquare(makeSquare(0, 0, makeColor(0, 0, 0)), fptr), 0);

    fclose(fptr);
}

static void test_whenInputStreamValid_clearScreen_returns0() 
{
    FILE *fptr = fopen(TEST_FILE_NAME, "w");

    CU_ASSERT_EQUAL(clearScreen(fptr), 0);

    fclose(fptr);
}

static void test_whenInputStreamValid_moveCursor_returns0() 
{
    FILE *fptr = fopen(TEST_FILE_NAME, "w");

    CU_ASSERT_EQUAL(moveCursor(0, 0, fptr), 0);

    fclose(fptr);
}

static void test_whenInputStreamValid_resetCursorPosition_returns0() 
{
    FILE *fptr = fopen(TEST_FILE_NAME, "w");

    CU_ASSERT_EQUAL(resetCursorPosition(fptr), 0);

    fclose(fptr);
}

static void test_whenInputStreamValid_setColor_returns0() 
{
    FILE *fptr = fopen(TEST_FILE_NAME, "w");

    CU_ASSERT_EQUAL(setColor(makeColor(0, 0, 0), fptr), 0);

    fclose(fptr);
}

static void test_whenInputStreamValid_resetColor_returns0() 
{
    FILE *fptr = fopen(TEST_FILE_NAME, "w");

    CU_ASSERT_EQUAL(resetColor(fptr), 0);

    fclose(fptr);
}

int cleanup() 
{
    return remove(TEST_FILE_NAME);
}

int main() 
{
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry()) 
    {
        return CU_get_error();
    }

    pSuite = CU_add_suite("TerminalUI/Screen", NULL, cleanup);

    if (pSuite == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "returns success value when drawSquare", test_whenInputStreamValid_drawSquare_returns0) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "returns success value when clearScreen", test_whenInputStreamValid_clearScreen_returns0) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "returns success value when moveCursor", test_whenInputStreamValid_moveCursor_returns0) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "returns success value when resetCursorPosition", test_whenInputStreamValid_resetCursorPosition_returns0) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "returns success value when setColor", test_whenInputStreamValid_setColor_returns0) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "returns success value when resetColor", test_whenInputStreamValid_resetColor_returns0) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_suite(pSuite);
    CU_cleanup_registry();
    return CU_get_error();
}