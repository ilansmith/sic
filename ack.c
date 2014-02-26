/* SIC Implemention of Ackermann:
 * A(0, q) = q + 1
 * A(p+1, 0) = A(p, 1)
 * A(p+1, q+1) = A(p, A(p+1, q))
 */

#include "sic.h"

/* indecies (start at 135) */
#define PTR_P 140
#define PTR_Q 141
#define TEST_P_IS_ZERO 142
#define TEST_Q_IS_ZERO 214
#define TEST_PHYSICAL_MEMORY 262
#define P_AND_Q_ARE_POSITIVE 277
#define PTR_ARGS -358
#define ARG_1 (-(PTR_ARGS) + 0)
#define ARG_2 (-(PTR_ARGS) + 1)

ADDR_SPC_T M[MAX_PHYSICAL_MEMORY] =
{
/* PTR */
/*   0 */    SIC_COMMON, /* common to all sic functions */

/* 135 */    PTR_ARGS, -(PTR_ARGS) + 1, /* SP, START */
/* 137 */    PTR_TMP2, PTR_SUB_ONE, TEST_P_IS_ZERO, /* run ackermann */
/* 140 */    DONT_CARE, DONT_CARE, /* P, Q */

/* 142 */    /* TEST_P_IS_ZERO */
/*   0 */    PTR_P, PTR_P, DONT_CARE,
/*   3 */    TEST_P_IS_ZERO + 10, TEST_P_IS_ZERO + 10, DONT_CARE,
/*   6 */    TEST_P_IS_ZERO + 10, PTR_SP, DONT_CARE,
/*   9 */    PTR_P, DONT_CARE, TEST_Q_IS_ZERO, /* p is positive */
/*  12 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  15 */    PTR_TMP1, PTR_P, ERROR_NEGATIVE_ARGS, /* error: p is negative */
/*  18 */    TEST_P_IS_ZERO + 30, TEST_P_IS_ZERO + 30, DONT_CARE, /* p==0 */
/*  21 */    TEST_P_IS_ZERO + 31, TEST_P_IS_ZERO + 31, DONT_CARE,
/*  24 */    TEST_P_IS_ZERO + 30, PTR_SP, DONT_CARE,
/*  27 */    TEST_P_IS_ZERO + 31, PTR_SP, DONT_CARE,
/*  30 */    DONT_CARE, DONT_CARE, DONT_CARE,
/*  33 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  36 */    TEST_P_IS_ZERO + 46, TEST_P_IS_ZERO + 46, DONT_CARE,
/*  39 */    TEST_P_IS_ZERO + 46, PTR_SP, DONT_CARE,
/*  42 */    TEST_P_IS_ZERO + 46, PTR_ADD_ONE, DONT_CARE,
/*  45 */    PTR_TMP1, DONT_CARE, TEST_P_IS_ZERO + 48,
/*  48 */    PTR_TMP1, PTR_SUB_ONE, TEST_P_IS_ZERO + 51,
/*  51 */    TEST_P_IS_ZERO + 57, TEST_P_IS_ZERO + 57, DONT_CARE,
/*  54 */    TEST_P_IS_ZERO + 57, PTR_SP, DONT_CARE,
/*  57 */    DONT_CARE, PTR_TMP1, DONT_CARE,

/*  60 */    SIC_COMPLETION_TEST,

/*  69 */    PTR_SP, PTR_ADD_ONE, TEST_P_IS_ZERO,
/*  72 */    

/* 214 */    /* TEST_Q_IS_ZERO */
/*   0 */    PTR_SP, PTR_SUB_ONE, TEST_Q_IS_ZERO + 3,
/*   3 */    PTR_Q, PTR_Q, DONT_CARE,
/*   6 */    TEST_Q_IS_ZERO + 13, TEST_Q_IS_ZERO + 13, DONT_CARE,
/*   9 */    TEST_Q_IS_ZERO + 13, PTR_SP, TEST_Q_IS_ZERO + 12,
/*  12 */    PTR_Q, DONT_CARE, TEST_PHYSICAL_MEMORY, /* q is positive */
/*  15 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  18 */    PTR_TMP1, PTR_Q, ERROR_NEGATIVE_ARGS, /* error: q is negagive */
/*  21 */    TEST_Q_IS_ZERO + 27, TEST_Q_IS_ZERO + 27, DONT_CARE, /* q==0 */
/*  24 */    TEST_Q_IS_ZERO + 27, PTR_SP, DONT_CARE,
/*  27 */    DONT_CARE, PTR_ADD_ONE, DONT_CARE,
/*  30 */    PTR_SP, PTR_ADD_ONE, TEST_Q_IS_ZERO + 33,
/*  33 */    TEST_Q_IS_ZERO + 39, TEST_Q_IS_ZERO + 39, DONT_CARE,
/*  36 */    TEST_Q_IS_ZERO + 39, PTR_SP, DONT_CARE,
/*  39 */    DONT_CARE, PTR_SUB_ONE, DONT_CARE,
/*  42 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  45 */    PTR_TMP1, PTR_SUB_ONE, TEST_P_IS_ZERO,
/*  48 */    

/* 262 */    SIC_MEMORY_TEST,

             /* M[M[sp] + 1] =  q - 1
	      * M[M[sp]] = p
	      * M[M[sp] - 1] = p - 1 */
/* 277 */    /* P_AND_Q_ARE_POSITIVE */
/*   0 */    P_AND_Q_ARE_POSITIVE + 30, P_AND_Q_ARE_POSITIVE + 30, DONT_CARE,
/*   3 */    P_AND_Q_ARE_POSITIVE + 30, PTR_SP, DONT_CARE,
/*   6 */    P_AND_Q_ARE_POSITIVE + 31, P_AND_Q_ARE_POSITIVE + 31, DONT_CARE,
/*   9 */    P_AND_Q_ARE_POSITIVE + 31, PTR_SP, DONT_CARE,
/*  12 */    P_AND_Q_ARE_POSITIVE + 33, P_AND_Q_ARE_POSITIVE + 33, DONT_CARE,
/*  15 */    P_AND_Q_ARE_POSITIVE + 33, PTR_SP, DONT_CARE,
/*  18 */    P_AND_Q_ARE_POSITIVE + 33, PTR_ADD_ONE, DONT_CARE,
/*  21 */    P_AND_Q_ARE_POSITIVE + 34, P_AND_Q_ARE_POSITIVE + 34, DONT_CARE,
/*  24 */    P_AND_Q_ARE_POSITIVE + 34, PTR_SP, DONT_CARE,
/*  27 */    P_AND_Q_ARE_POSITIVE + 34, PTR_ADD_ONE, DONT_CARE,
/*  30 */    DONT_CARE, DONT_CARE, DONT_CARE,
/*  33 */    DONT_CARE, DONT_CARE, DONT_CARE,

/*  36 */    PTR_Q, PTR_ADD_ONE, P_AND_Q_ARE_POSITIVE + 39,
/*  39 */    P_AND_Q_ARE_POSITIVE + 48, P_AND_Q_ARE_POSITIVE + 48, DONT_CARE,
/*  42 */    P_AND_Q_ARE_POSITIVE + 48, PTR_SP, DONT_CARE,
/*  45 */    P_AND_Q_ARE_POSITIVE + 48, PTR_ADD_ONE, DONT_CARE,
/*  48 */    DONT_CARE, PTR_Q, DONT_CARE,

/*  51 */    P_AND_Q_ARE_POSITIVE + 57, P_AND_Q_ARE_POSITIVE + 57, DONT_CARE,
/*  54 */    P_AND_Q_ARE_POSITIVE + 57, PTR_SP, DONT_CARE,
/*  57 */    DONT_CARE, PTR_P, DONT_CARE,

/*  60 */    PTR_P, PTR_ADD_ONE, P_AND_Q_ARE_POSITIVE + 63,
/*  63 */    P_AND_Q_ARE_POSITIVE + 72, P_AND_Q_ARE_POSITIVE + 72, DONT_CARE,
/*  66 */    P_AND_Q_ARE_POSITIVE + 72, PTR_SP, DONT_CARE,
/*  69 */    P_AND_Q_ARE_POSITIVE + 72, PTR_SUB_ONE, DONT_CARE,
/*  72 */    DONT_CARE, PTR_SUB_ONE, DONT_CARE,

/*  75 */    PTR_TMP1, PTR_TMP1, DONT_CARE,
/*  78 */    PTR_TMP1, PTR_SUB_ONE, TEST_P_IS_ZERO,
/*  81 */

/* 358 */    /* ARG_1 */
/* 359 */    /* ARG_2 */
};

int sic_init(int argc, ADDR_SPC_T args[MAX_ARGS])
{
    if (argc!=2)
	return -1;

    M[ARG_1] = args[0];
    M[ARG_2] = args[1];
    return 0;
}

