#include "../../include/TerminalUI/Screen.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>

#define TEST_FILE_NAME "ScreenTest.txt"

FILE *fptr;

static struct Shape shp;

static void test_whenInputStreamValid_drawSquare_returns0() 
{
    CU_ASSERT_EQUAL(drawSquare(makeSquare(0, 0, makeColor(0, 0, 0)), fptr), 0);
}

static void test_whenInputStreamValid_clearScreen_returns0() 
{
    CU_ASSERT_EQUAL(clearScreen(fptr), 0);
}

static void test_whenInputStreamValid_moveCursor_returns0() 
{
    CU_ASSERT_EQUAL(moveCursor(0, 0, fptr), 0);
}

static void test_whenInputStreamValid_resetCursorPosition_returns0() 
{
    CU_ASSERT_EQUAL(resetCursorPosition(fptr), 0);
}

static void test_whenInputStreamValid_setColor_returns0() 
{
    CU_ASSERT_EQUAL(setColor(makeColor(0, 0, 0), fptr), 0);
}

static void test_whenInputStreamValid_resetColor_returns0() 
{
    CU_ASSERT_EQUAL(resetColor(fptr), 0);
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

static void test_whenInputIsValid_makeShape_returnsShape() 
{
    shp = makeShape(makeSquare(1, 2, makeColor(3, 4, 5)));

    CU_ASSERT_EQUAL(shp.sqr.x, 1);
    CU_ASSERT_EQUAL(shp.sqr.y, 2);
    CU_ASSERT_EQUAL(shp.sqr.col.r, 3);
    CU_ASSERT_EQUAL(shp.sqr.col.g, 4);
    CU_ASSERT_EQUAL(shp.sqr.col.b, 5);
    CU_ASSERT_EQUAL(shp.idx, 0);
    CU_ASSERT_PTR_NULL(shp.nxt);
}

static void test_whenInputIsValid_addSquareToShape_squareIsAdded() 
{
    shp = addSquareToShape(shp, makeSquare(6, 7, makeColor(8, 9, 10)));

    CU_ASSERT_EQUAL(shp.nxt->sqr.x, 6);
    CU_ASSERT_EQUAL(shp.nxt->sqr.y, 7);
    CU_ASSERT_EQUAL(shp.nxt->sqr.col.r, 8);
    CU_ASSERT_EQUAL(shp.nxt->sqr.col.g, 9);
    CU_ASSERT_EQUAL(shp.nxt->sqr.col.b, 10);
    CU_ASSERT_EQUAL(shp.nxt->idx, 1);
    CU_ASSERT_PTR_NULL(shp.nxt->nxt);
}

static void test_whenShapeLinkedListHasMulitpleElements_deleteShape_deletesLinkedList()
{
    CU_ASSERT_NOT_EQUAL(shp.nxt, NULL);
    CU_ASSERT_EQUAL(deleteShape(shp), 0);
    CU_ASSERT_EQUAL(shp.nxt, NULL);
}

int setup() 
{
    fptr = fopen(TEST_FILE_NAME, "w");

    if (fptr != NULL) 
    {
        return 0;
    }
    return -1;
}

int cleanup() 
{
    if (fclose(fptr) == 0) 
    {
        return remove(TEST_FILE_NAME);
    }
    return -1;
}

int main() 
{
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry()) 
    {
        return CU_get_error();
    }

    pSuite = CU_add_suite("TerminalUI/Screen", setup, cleanup);

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

    if (CU_add_test(pSuite, "adds correct square when addSquareToShape", test_whenInputIsValid_addSquareToShape_squareIsAdded) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(pSuite, "deletes shape linked list when deleteShape", test_whenShapeLinkedListHasMulitpleElements_deleteShape_deletesLinkedList) == NULL) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_suite(pSuite);
    CU_cleanup_registry();
    return CU_get_error();
}