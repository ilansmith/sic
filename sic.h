#ifndef _SIC_H_
#define _SIC_H_

#ifdef CONFIG_LARGE_ADDRESS
#define ADDR_SPC_T long long
#else
#define ADDR_SPC_T long
#endif

#define MAX_ARGS 2
#define KB 1024
#define MB (KB * KB)
#define MAX_PHYSICAL_MEMORY (4 * MB)

/* error messages */
#define ERR_ARGS_STR 'e', 'r', 'r', 'o', 'r', ':', ' ', 'n', 'e', 'g', 'a', \
	't', 'i', 'v', 'e', ' ', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', 's'
#define ERR_ARGS_STR_LEN -25
#define ERR_MEMORY_STR 'e', 'r', 'r', 'o', 'r', ':', ' ', 'o', 'u', 't', ' ', \
	'o', 'f', ' ', 'p', 'h', 'y', 's', 'i', 'c', 'a', 'l', ' ', 'm', 'e', \
	'm', 'o', 'r', 'y'
#define ERR_MEMORY_STR_LEN -29

/* constants */
#define ZERO 0
#define ONE 1
#define ADD_ONE -1
#define SUB_ONE 1
#define DONT_CARE 1

/* indecies */
#define PTR_0 0
#define PTR_1 1
#define PTR_2 2
#define TERMINATE 3
#define PTR_MAX_PHYSICAL_MEMORY 6
#define PTR_ADD_ONE 7
#define PTR_SUB_ONE 8
#define PTR_TMP1 9
#define PTR_TMP2 10
#define PTR_PTR_ERR_ARGS_STR 11
#define PTR_ERR_ARGS_STR -12
#define PTR_ERR_ARGS_STR_LEN 37
#define PTR_PTR_ERR_MEMORY_STR 38
#define PTR_ERR_MEMORY_STR -39
#define PTR_ERR_MEMORY_STR_LEN 68
#define SUCCESS 69
#define ERROR_NEGATIVE_ARGS 93
#define ERROR_OUT_OF_MEMORY 114
#define PTR_SP 135
#define PTR_START 136
#define RUN_FUNC 137

/* common use macors */
#define SIC_COMMON \
/* PTR */ \
/*   0 */    PTR_TMP1, PTR_SUB_ONE, RUN_FUNC, \
/*   3 */    ZERO, ZERO, ZERO, /* TERMINATE */ \
/*   6 */    -(MAX_PHYSICAL_MEMORY - 1), \
/*   7 */    ADD_ONE, SUB_ONE, \
/*   9 */    ZERO, ZERO, /* TMP1, TMP2 */ \
/*  11 */    PTR_ERR_ARGS_STR, ERR_ARGS_STR, ERR_ARGS_STR_LEN, \
/*  38 */    PTR_ERR_MEMORY_STR, ERR_MEMORY_STR, ERR_MEMORY_STR_LEN, \
\
/*  69 */    /* SUCCESS */ \
/*   0 */    PTR_0, PTR_0, DONT_CARE, \
/*   3 */    PTR_1, PTR_1, DONT_CARE, \
/*   6 */    PTR_2, PTR_2, DONT_CARE, \
/*   9 */    PTR_0, PTR_ADD_ONE, DONT_CARE, \
/*  12 */    PTR_1, PTR_ADD_ONE, DONT_CARE, \
/*  15 */    PTR_2, PTR_SP, DONT_CARE, \
/*  18 */    PTR_TMP1, PTR_TMP1, DONT_CARE, \
/*  21 */    PTR_TMP1, PTR_SUB_ONE, TERMINATE, \
/*  24 */    \
\
/*  93 */    /* ERROR_NEGATIVE_ARGS */ \
/*   0 */    PTR_0, PTR_0, DONT_CARE, \
/*   3 */    PTR_1, PTR_1, DONT_CARE, \
/*   6 */    PTR_2, PTR_2, DONT_CARE, \
/*   9 */    PTR_1, PTR_ERR_ARGS_STR_LEN, DONT_CARE, \
/*  12 */    PTR_2, PTR_PTR_ERR_ARGS_STR, DONT_CARE, \
/*  15 */    PTR_TMP1, PTR_TMP1, DONT_CARE, \
/*  18 */    PTR_TMP1, PTR_SUB_ONE, TERMINATE, \
/*  21 */    \
\
/* 114 */    /* ERROR_OUT_OF_MEMORY */ \
/*   0 */    PTR_0, PTR_0, DONT_CARE, \
/*   3 */    PTR_1, PTR_1, DONT_CARE, \
/*   6 */    PTR_2, PTR_2, DONT_CARE, \
/*   9 */    PTR_1, PTR_ERR_MEMORY_STR_LEN, DONT_CARE, \
/*  12 */    PTR_2, PTR_PTR_ERR_MEMORY_STR, DONT_CARE, \
/*  15 */    PTR_TMP1, PTR_TMP1, DONT_CARE, \
/*  18 */    PTR_TMP1, PTR_SUB_ONE, TERMINATE \
/*  21 */    /* 135 */

#define SIC_COMPLETION_TEST \
             /* test M[SP]==M[START] */ \
/*   0 */    PTR_TMP1, PTR_TMP1, DONT_CARE, \
/*   3 */    PTR_TMP1, PTR_SP, DONT_CARE, \
/*   6 */    PTR_TMP1, PTR_START, SUCCESS \
/*   9 */

#define SIC_MEMORY_TEST \
             /* test physical memory */ \
/*   0 */    PTR_TMP1, PTR_TMP1, DONT_CARE, \
/*   3 */    PTR_TMP1, PTR_SP, DONT_CARE, \
/*   6 */    PTR_TMP2, PTR_TMP2, DONT_CARE, \
/*   9 */    PTR_TMP2, PTR_MAX_PHYSICAL_MEMORY, DONT_CARE, \
/*  12 */    PTR_TMP2, PTR_TMP1, ERROR_OUT_OF_MEMORY \
/*  15 */    

extern ADDR_SPC_T M[MAX_PHYSICAL_MEMORY];
int sic_init(int argc, ADDR_SPC_T args[MAX_ARGS]);
#endif

