#include <stdio.h>
#include <stdlib.h>
#ifdef CONFIG_CALCULATE_TIME
#include <sys/time.h>
#include "time.h"
#endif
#include "sic.h"

#ifdef CONFIG_LARGE_ADDRESS
long long atoll(const char *nptr); /* for -ansi compilation switch */
#define ATOL(X) atoll(X)
#define STR_NUMERIC_FMT "%llu"
#else
#define ATOL(X) atol(X)
#define STR_NUMERIC_FMT "%lu"
#endif
#define STR_ALPHANUMERIC_FMT "%c"

static ADDR_SPC_T sic_args[MAX_ARGS];

static int sic_args_atol(int argc, char *argv[])
{
	int i;

	if (argc > MAX_ARGS)
		return -1;

	for (i = 0; i < argc; i++)
		sic_args[i] = ATOL(argv[i]);
	return 0;
}

int main(int argc, char *argv[])
{
	int i = 0, j;
	char *format = NULL;
#ifdef CONFIG_CALCULATE_TIME
	timeval tv1, tv2;

	time_clear(&tv1);
	time_clear(&tv2);
#endif

	if (sic_args_atol(argc - 1, argv + 1) || sic_init(argc - 1, sic_args))
		return -1;

#ifdef CONFIG_CALCULATE_TIME
	if (gettimeofday(&tv1, NULL))
		return -1;
#endif

	while (M[i] || M[i+1] || M[i+2]) {
		if ((M[M[i]] -= M[M[i+1]]) < 0)
			i = M[i+2];
		else
			i += 3;
	}

#ifdef CONFIG_CALCULATE_TIME
	if (gettimeofday(&tv2, NULL))
		return -1;
#endif

	format = M[0] ? STR_NUMERIC_FMT : STR_ALPHANUMERIC_FMT;
	for (i = M[1], j = M[2]; i > 0; --i, ++j)
		printf(format, M[j]);
	printf("\n");

#ifdef CONFIG_CALCULATE_TIME
	if (M[0])
		print_time(&tv1, &tv2);
#endif
	return 0;
}

