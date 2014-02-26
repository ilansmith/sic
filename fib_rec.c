/* SIC Implemention of Fibonacci:
 * F(0) = 0
 * F(1) = 1
 * F(n+2) = F(n) + F(n+1)
 */

#include "sic.h"

/* indecies (start at 135) */
#define PTR_N 140
#define TEST_N_IS_NOT_NEG 141
#define TEST_LESS_THAN_TWO 150
#define DO_FIB_1ST_K 174 
#define TEST_WHICH_K 258
#define DO_FIB_2ND_K 393
#define PTR_ARGS -466
#define ARG_N (-(PTR_ARGS) + 0)

ADDR_SPC_T M[MAX_PHYSICAL_MEMORY] =
{
/* PTR */
/*   0 */    SIC_COMMON, /* common to all sic functions */

/* 135 */    PTR_ARGS, -(PTR_ARGS) + 1, /* SP, START */
/* 137 */    PTR_TMP2, PTR_SUB_ONE, TEST_N_IS_NOT_NEG, /* run fibonacci */
/* 140 */    DONT_CARE, /* N */

/* 141 */    /* TEST_N_IS_NOT_NEG */
/*   0 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*   3 */    TEST_N_IS_NOT_NEG + 6, PTR_SP, DONT_CARE,
/*   6 */    ZERO, PTR_TMP1, ERROR_NEGATIVE_ARGS,
/*   9 */

/* 150 */    /* TEST_LESS_THAN_TWO */
/*   0 */    TEST_LESS_THAN_TWO + 10, TEST_LESS_THAN_TWO + 10, DONT_CARE,
/*   3 */    TEST_LESS_THAN_TWO + 10, PTR_SP, DONT_CARE,
/*   6 */    PTR_N, PTR_N, DONT_CARE,
/*   9 */    PTR_N, DONT_CARE, TEST_LESS_THAN_TWO + 12,
/*  12 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  15 */    PTR_TMP1, PTR_SUB_ONE, TEST_LESS_THAN_TWO + 18,
/*  18 */    PTR_TMP1, PTR_SUB_ONE, TEST_LESS_THAN_TWO + 21,
/*  21 */    PTR_TMP1, PTR_N, TEST_WHICH_K,
/*  24 */
 
/* 174 */    /* DO_FIB_1ST_K */
/*   0 */    SIC_MEMORY_TEST,
/*  15 */    PTR_SP, PTR_SUB_ONE, DO_FIB_1ST_K + 18, /* sp++ */
/*  18 */    DO_FIB_1ST_K + 30, DO_FIB_1ST_K + 30, DONT_CARE,
/*  21 */    DO_FIB_1ST_K + 30, PTR_SP, DONT_CARE,
/*  24 */    DO_FIB_1ST_K + 31, DO_FIB_1ST_K + 31, DONT_CARE,
/*  27 */    DO_FIB_1ST_K + 31, PTR_SP, DONT_CARE,
/*  30 */    DONT_CARE, DONT_CARE, DONT_CARE, /* M[sp] = 0 */
/*  33 */    SIC_MEMORY_TEST,
/*  48 */    PTR_SP, PTR_SUB_ONE, DO_FIB_1ST_K + 51, /* sp++ */
/*  51 */    PTR_N, PTR_ADD_ONE, DO_FIB_1ST_K + 54, /* n-- */
/*  54 */    DO_FIB_1ST_K + 66, DO_FIB_1ST_K + 66, DONT_CARE,
/*  57 */    DO_FIB_1ST_K + 66, PTR_SP, DONT_CARE,
/*  60 */    DO_FIB_1ST_K + 67, DO_FIB_1ST_K + 67, DONT_CARE,
/*  63 */    DO_FIB_1ST_K + 67, PTR_SP, DONT_CARE,
/*  66 */    DONT_CARE, DONT_CARE, DONT_CARE,
/*  69 */    DO_FIB_1ST_K + 75, DO_FIB_1ST_K + 75, DONT_CARE,
/*  72 */    DO_FIB_1ST_K + 75, PTR_SP, DONT_CARE,
/*  75 */    DONT_CARE, PTR_N, DONT_CARE, /* M[sp] = n */
/*  78 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  81 */    PTR_TMP1, PTR_SUB_ONE, TEST_LESS_THAN_TWO,
/*  84 */

/* 258 */    /* TEST_WHICH_K */
/*   0 */    TEST_WHICH_K + 13, TEST_WHICH_K + 13, DONT_CARE,
/*   3 */    TEST_WHICH_K + 13, PTR_SP, DONT_CARE,
/*   6 */    TEST_WHICH_K + 13, PTR_SUB_ONE, DONT_CARE,
/*   9 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  12 */    PTR_TMP1, DONT_CARE, DO_FIB_2ND_K,
/*  15 */    SIC_MEMORY_TEST,
/*  30 */    PTR_SP, PTR_SUB_ONE, TEST_WHICH_K + 33, /* sp++ */
/*  33 */    TEST_WHICH_K + 45, TEST_WHICH_K + 45, DONT_CARE,
/*  36 */    TEST_WHICH_K + 45, PTR_SP, DONT_CARE,
/*  39 */    TEST_WHICH_K + 46, TEST_WHICH_K + 46, DONT_CARE,
/*  42 */    TEST_WHICH_K + 46, PTR_SP, DONT_CARE,
/*  45 */    DONT_CARE, DONT_CARE, DONT_CARE, /* M[sp]=0 */
/*  48 */    TEST_WHICH_K + 54, TEST_WHICH_K + 54, DONT_CARE,
/*  51 */    TEST_WHICH_K + 54, PTR_SP, DONT_CARE,
/*  54 */    DONT_CARE, PTR_ADD_ONE, DONT_CARE, /* M[sp]++ */
/*  57 */    SIC_MEMORY_TEST,
/*  72 */    PTR_SP, PTR_SUB_ONE, TEST_WHICH_K + 75, /* sp++ */
/*  75 */    TEST_WHICH_K + 97, TEST_WHICH_K + 97, DONT_CARE,
/*  78 */    TEST_WHICH_K + 97, PTR_SP, DONT_CARE,
/*  81 */    TEST_WHICH_K + 97, PTR_SUB_ONE, DONT_CARE,
/*  84 */    TEST_WHICH_K + 97, PTR_SUB_ONE, DONT_CARE,
/*  87 */    TEST_WHICH_K + 97, PTR_SUB_ONE, DONT_CARE,
/*  90 */    TEST_WHICH_K + 97, PTR_SUB_ONE, DONT_CARE,
/*  93 */    PTR_N, PTR_N, ONE,
/*  96 */    PTR_N, DONT_CARE, TEST_WHICH_K + 99,
/*  99 */    PTR_N, PTR_ADD_ONE, TEST_WHICH_K + 102,
/* 102 */    PTR_N, PTR_ADD_ONE, TEST_WHICH_K + 105,
/* 105 */    TEST_WHICH_K + 117, TEST_WHICH_K + 117, DONT_CARE,
/* 108 */    TEST_WHICH_K + 117, PTR_SP, DONT_CARE,
/* 111 */    TEST_WHICH_K + 118, TEST_WHICH_K + 118, DONT_CARE,
/* 114 */    TEST_WHICH_K + 118, PTR_SP, DONT_CARE,
/* 117 */    DONT_CARE, DONT_CARE, DONT_CARE,
/* 120 */    TEST_WHICH_K + 126, TEST_WHICH_K + 126, DONT_CARE,
/* 123 */    TEST_WHICH_K + 126, PTR_SP, DONT_CARE,
/* 126 */    DONT_CARE, PTR_N, ONE,
/* 129 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/* 132 */    PTR_TMP1, PTR_SUB_ONE, TEST_LESS_THAN_TWO,
/* 135 */

/* 393 */    /* DO_FIB_2ND_K */
/*   0 */    SIC_COMPLETION_TEST,
/*   9 */    DO_FIB_2ND_K + 19, DO_FIB_2ND_K + 19, DONT_CARE,
/*  12 */    DO_FIB_2ND_K + 19, PTR_SP, DONT_CARE,
/*  15 */    PTR_N, PTR_N, ONE,
/*  18 */    PTR_N, DONT_CARE, DO_FIB_2ND_K + 21,
/*  21 */    PTR_SP, PTR_ADD_ONE, DO_FIB_2ND_K + 24,
/*  24 */    PTR_SP, PTR_ADD_ONE, DO_FIB_2ND_K + 27,
/*  27 */    DO_FIB_2ND_K + 34, DO_FIB_2ND_K + 34, DONT_CARE,
/*  30 */    DO_FIB_2ND_K + 34, PTR_SP, DONT_CARE,
/*  33 */    PTR_N, DONT_CARE, DO_FIB_2ND_K + 36,
/*  36 */    PTR_SP, PTR_ADD_ONE, DO_FIB_2ND_K + 39,
/*  39 */    PTR_SP, PTR_ADD_ONE, DO_FIB_2ND_K + 42,
/*  42 */    DO_FIB_2ND_K + 54, DO_FIB_2ND_K + 54, DONT_CARE,
/*  45 */    DO_FIB_2ND_K + 54, PTR_SP, DONT_CARE,
/*  48 */    DO_FIB_2ND_K + 55, DO_FIB_2ND_K + 55, DONT_CARE,
/*  51 */    DO_FIB_2ND_K + 55, PTR_SP, DONT_CARE,
/*  54 */    DONT_CARE, DONT_CARE, DONT_CARE,
/*  57 */    DO_FIB_2ND_K + 63, DO_FIB_2ND_K + 63, DONT_CARE,
/*  60 */    DO_FIB_2ND_K + 63, PTR_SP, DONT_CARE,
/*  63 */    DONT_CARE, PTR_N, DONT_CARE,
/*  66 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  69 */    PTR_TMP1, PTR_SUB_ONE, TEST_WHICH_K,
/*  72 */

/* 465 */    ONE,
/* 466 */    /* ARG_N */
};

int sic_init(int argc, ADDR_SPC_T args[MAX_ARGS])
{
    if (argc!=1)
	return -1;

    M[ARG_N] = args[0];
    return 0;
}

