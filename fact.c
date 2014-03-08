/* SIC Implemention of Factorial:
 * F(0) = 1
 * F(n+1) = n * F(n)
 */

#include "sic.h"

/* indecies (start at 135) */
#define PTR_N 140
#define TEST_N_IS_ZERO 141
#define EPILOGUE 168
#define TEST_PHYSICAL_MEMORY 180
#define PROLOGUE 195
#define DO_MULTIPLY 225
#define PTR_ARGS -300
#define ARG_N (-(PTR_ARGS) + 0)

ADDR_SPC_T M[MAX_PHYSICAL_MEMORY] = {
/* PTR */
/*   0 */    SIC_COMMON, /* common to all sic functions */

/* 135 */    PTR_ARGS, -(PTR_ARGS) + 1, /* SP, START */
/* 137 */    PTR_TMP2, PTR_SUB_ONE, TEST_N_IS_ZERO, /* run factorial */
/* 140 */    DONT_CARE, /* N */

/* 141 */    /* TEST_N_IS_ZERO */
/*   0 */    PTR_N, PTR_N, DONT_CARE,
/*   3 */    TEST_N_IS_ZERO + 10, TEST_N_IS_ZERO + 10, DONT_CARE,
/*   6 */    TEST_N_IS_ZERO + 10, PTR_SP, DONT_CARE,
/*   9 */    PTR_N, DONT_CARE, TEST_PHYSICAL_MEMORY, /* n is positive */
/*  12 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  15 */    PTR_TMP1, PTR_N, ERROR_NEGATIVE_ARGS, /* error: n is negative */
/*  18 */    TEST_N_IS_ZERO + 24, TEST_N_IS_ZERO + 24, DONT_CARE, /* n==0 */
/*  21 */    TEST_N_IS_ZERO + 24, PTR_SP, DONT_CARE,
/*  24 */    DONT_CARE, PTR_ADD_ONE, DONT_CARE,
/*  27 */

/* 168 */    /* EPILOGUE */
/*   0 */    SIC_COMPLETION_TEST,
/*   9 */    PTR_SP, PTR_ADD_ONE, DO_MULTIPLY,
/*  12 */

/* 180 */    /* TEST_PHYSICAL_MEMORY */
/*   0 */    SIC_MEMORY_TEST,
/*  15 */

/* 195 */    /* PROLOGUE */
/*   0 */    PTR_N, PTR_N, DONT_CARE,
/*   3 */    PROLOGUE + 10, PROLOGUE + 10, DONT_CARE,
/*   6 */    PROLOGUE + 10, PTR_SP, DONT_CARE,
/*   9 */    PTR_N, DONT_CARE, PROLOGUE + 12,
/*  12 */    PTR_N, PTR_ADD_ONE, PROLOGUE + 15,
/*  15 */    PROLOGUE + 24, PROLOGUE + 24, DONT_CARE,
/*  18 */    PROLOGUE + 24, PTR_SP, DONT_CARE,
/*  21 */    PROLOGUE + 24, PTR_ADD_ONE, DONT_CARE,
/*  24 */    DONT_CARE, PTR_N, DONT_CARE,
/*  27 */    PTR_SP, PTR_SUB_ONE, TEST_N_IS_ZERO,
/*  30 */

/* 225 */     /* DO_MULTIPLY */
/*   0 */    PTR_N, PTR_N, DONT_CARE,
/*   3 */    DO_MULTIPLY + 10, DO_MULTIPLY + 10, DONT_CARE,
/*   6 */    DO_MULTIPLY + 10, PTR_SP, DONT_CARE,
/*   9 */    PTR_N, DONT_CARE, DO_MULTIPLY + 12, /* N = -M[sp] */
/*  12 */    PTR_N, PTR_SUB_ONE, DO_MULTIPLY + 15,
/*  15 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  18 */    PTR_TMP2, PTR_TMP2, DONT_CARE,
/*  21 */    DO_MULTIPLY + 31, DO_MULTIPLY + 31, DONT_CARE,
/*  24 */    DO_MULTIPLY + 31, PTR_SP, DONT_CARE,
/*  27 */    DO_MULTIPLY + 31, PTR_ADD_ONE, DONT_CARE,
/*  30 */    PTR_TMP1, DONT_CARE, DO_MULTIPLY + 36, /* TMP1 = -M[sp+1] */

/*  33 */    PTR_TMP2, PTR_TMP1, DO_MULTIPLY + 36,
/*  36 */    PTR_N, PTR_ADD_ONE, DO_MULTIPLY + 33,

/*  39 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  42 */    PTR_TMP1, PTR_TMP2, DO_MULTIPLY + 45,
/*  45 */    DO_MULTIPLY + 57, DO_MULTIPLY + 57, DONT_CARE,
/*  48 */    DO_MULTIPLY + 57, PTR_SP, DONT_CARE,
/*  51 */    DO_MULTIPLY + 58, DO_MULTIPLY + 58, DONT_CARE,
/*  54 */    DO_MULTIPLY + 58, PTR_SP, DONT_CARE,
/*  57 */    DONT_CARE, DONT_CARE, DONT_CARE,
/*  60 */    DO_MULTIPLY + 66, DO_MULTIPLY + 66, DONT_CARE,
/*  63 */    DO_MULTIPLY + 66, PTR_SP, DONT_CARE,
/*  66 */    DONT_CARE, PTR_TMP1, DONT_CARE,
/*  69 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  72 */    PTR_TMP1, PTR_SUB_ONE, EPILOGUE,
/*  75 */

/* 300 */    /* ARG_N */
};

int sic_init(int argc, ADDR_SPC_T args[MAX_ARGS])
{
	if (argc!=1)
		return -1;

	M[ARG_N] = args[0];
	return 0;
}

