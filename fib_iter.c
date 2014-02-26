/* SIC Implemention of Fibonacci:
 * F(0) = 0
 * F(1) = 1
 * F(n+2) = F(n) + F(n+1)
 */

#include "sic.h"

/* indecies (start at 135) */
#define PTR_N 140
#define FIB_1 141
#define FIB_2 142
#define TEST_N_IS_NOT_NEG 143
#define TEST_N_LESS_THAN_TWO 155
#define N_NOT_LESS_THAN_TWO 167 
#define EPILOGUE 203
#define PTR_ARGS -281
#define ARG_N (-(PTR_ARGS) + 0)

ADDR_SPC_T M[MAX_PHYSICAL_MEMORY] =
{
/* PTR */
/*   0 */    SIC_COMMON, /* common to all sic functions */

/* 135 */    PTR_ARGS, -(PTR_ARGS) + 1, /* SP, START */
/* 137 */    PTR_TMP2, PTR_SUB_ONE, TEST_N_IS_NOT_NEG, /* run fibonacci */
/* 140 */    ZERO, DONT_CARE, DONT_CARE, /* N, FIB_1, FIB_2 */

/* 143 */    /* TEST_N_IS_NOT_NEG */
/*   0 */    TEST_N_IS_NOT_NEG + 4, PTR_SP, DONT_CARE,
/*   3 */    PTR_N, ZERO, TEST_N_IS_NOT_NEG + 6,
/*   6 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*   9 */    PTR_TMP1, PTR_N, ERROR_NEGATIVE_ARGS,
/*  12 */

/* 155 */    /* TEST_N_LESS_THAN_TWO */
/*   0 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*   3 */    PTR_TMP1, PTR_SUB_ONE, TEST_N_LESS_THAN_TWO + 6,
/*   6 */    PTR_TMP1, PTR_SUB_ONE, TEST_N_LESS_THAN_TWO + 9,
/*   9 */    PTR_TMP1, PTR_N, EPILOGUE,
/*  12 */

/* 167 */    /* N_NOT_LESS_THAN_TWO */
/*   0 */    SIC_MEMORY_TEST,
/*  15 */    PTR_SP, PTR_SUB_ONE, N_NOT_LESS_THAN_TWO + 18,
/*  18 */    PTR_N, PTR_ADD_ONE, N_NOT_LESS_THAN_TWO + 21,
/*  21 */    N_NOT_LESS_THAN_TWO + 27, N_NOT_LESS_THAN_TWO + 27, DONT_CARE,
/*  24 */    N_NOT_LESS_THAN_TWO + 27, PTR_SP, DONT_CARE,
/*  27 */    DONT_CARE, PTR_N, DONT_CARE,
/*  30 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  33 */    PTR_TMP1, PTR_SUB_ONE, TEST_N_LESS_THAN_TWO,
/*  36 */

/* 203 */    /* EPILOGUE */
/*   0 */    SIC_COMPLETION_TEST,
/*   9 */    EPILOGUE + 19, EPILOGUE + 19, DONT_CARE,
/*  12 */    EPILOGUE + 19, PTR_SP, DONT_CARE,
/*  15 */    FIB_1, FIB_1, DONT_CARE,
/*  18 */    FIB_1, DONT_CARE, EPILOGUE + 21,
/*  21 */    EPILOGUE + 34, EPILOGUE + 34, DONT_CARE,
/*  24 */    EPILOGUE + 34, PTR_SP, DONT_CARE,
/*  27 */    EPILOGUE + 34, PTR_ADD_ONE, DONT_CARE,
/*  30 */    FIB_2, FIB_2, DONT_CARE,
/*  33 */    FIB_2, DONT_CARE, EPILOGUE + 36,
/*  36 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  39 */    PTR_TMP1, FIB_2, DONT_CARE,
/*  42 */    FIB_1, PTR_TMP1, EPILOGUE + 45,
/*  45 */    PTR_SP, PTR_ADD_ONE, EPILOGUE + 48,
/*  48 */    EPILOGUE + 60, EPILOGUE + 60, DONT_CARE,
/*  51 */    EPILOGUE + 60, PTR_SP, DONT_CARE,
/*  54 */    EPILOGUE + 61, EPILOGUE + 61, DONT_CARE,
/*  57 */    EPILOGUE + 61, PTR_SP, DONT_CARE,
/*  60 */    DONT_CARE, DONT_CARE, ONE,
/*  63 */    EPILOGUE + 69, EPILOGUE + 69, DONT_CARE,
/*  66 */    EPILOGUE + 69, PTR_SP, DONT_CARE,
/*  69 */    DONT_CARE, FIB_1, DONT_CARE,
/*  72 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  75 */    PTR_TMP1, PTR_SUB_ONE, EPILOGUE,
/*  78 */

/* 281 */    /* ARG_N */
}; 

int sic_init(int argc, ADDR_SPC_T args[MAX_ARGS])
{
    if (argc!=1)
	return -1;

    M[ARG_N] = args[0];
    return 0;
}

