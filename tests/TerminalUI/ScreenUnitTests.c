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

static void test_whenInputValid_makeSquare_returnsSquare() 
{
    struct Square sqr = makeSquare(1, 2, makeColor(3, 4, 5));

    CU_ASSERT_EQUAL(sqr.x, 1);
    CU_ASSERT_EQUAL(sqr.y, 2);
    CU_ASSERT_EQUAL(sqr.col.r, 3);
    CU_ASSERT_EQUAL(sqr.col.g, 4);
    CU_ASSERT_EQUAL(sqr.col.b, 5);
}

static struct Shape shp;

static void test_whenInputIsValid_makeShape_returnsShape() 
{
    shp = makeShape(2, 2);

    CU_ASSERT_EQUAL(shp.w, 2);
    CU_ASSERT_EQUAL(shp.h, 2);
    CU_ASSERT_PTR_NOT_NULL(shp.mtrx);
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

    if (CU_add_test(pSuite, "returns correct square when makeSquare", test_whenInputValid_makeSquare_returnsSquare) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "returns correct square when makeShape", test_whenInputIsValid_makeShape_returnsShape) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_suite(pSuite);
    CU_cleanup_registry();
    return CU_get_error();
}