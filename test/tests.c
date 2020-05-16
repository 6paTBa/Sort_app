#include "functions.h"
#include <ctest.h>

CTEST(check_invalid_string, invalid_minus)
{
    char string[] = "--1\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_minus_position)
{
    char string[] = "1-5\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, illegal_symbol)
{
    char string[] = "5b\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, illegal_symbol_2)
{
    char string[] = "b\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, illegal_symbol_3)
{
    char string[] = "1 . 5\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, illegal_symbol_4)
{
    char string[] = " 1.5\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_double)
{
    char string[] = ".5\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_double_2)
{
    char string[] = "5.\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_double_3)
{
    char string[] = "5.0.0\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_double_4)
{
    char string[] = "-.5\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, minus_zero)
{
    char string[] = "-0\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, minus_zero_2)
{
    char string[] = "-0.000000\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, empty_string)
{
    char string[] = "\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_int)
{
    char string[] = "01\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_valid_string, valid_uint)
{
    char string[] = "0\n";
    size_t is_uint = 1;
    size_t expect = 1;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_valid_string, valid_uint_2)
{
    char string[] = "1000\n";
    size_t is_uint = 1;
    size_t expect = 1;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_valid_string, valid_double)
{
    char string[] = "-10\n";
    size_t is_uint = 1;
    size_t expect = 1;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_valid_string, valid_double_2)
{
    char string[] = "1.05\n";
    size_t is_uint = 1;
    size_t expect = 1;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_valid_string, valid_double_3)
{
    char string[] = "-0.05\n";
    size_t is_uint = 1;
    size_t expect = 1;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}
