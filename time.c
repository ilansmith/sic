#include <stdio.h>
#include <math.h>
#include "time.h"

#define C_RED "\033[1;31m"
#define C_DEF "\033[0m"

/* for -ansi compilation switch */
int snprintf(char * str, size_t size, const char *format, ...);

void time_clear(timeval *tv)
{
	if (!tv)
		return;

	tv->tv_sec = 0;
	tv->tv_usec = 0;
}

void print_time(timeval *tv1, timeval *tv2)
{
#define MAX_UNIT_SIZE 50
#define WRITE_TIME_BUF(_buf_, _fmt_, _val_) do { \
	snprintf(_buf_, MAX_UNIT_SIZE, _fmt_"%s ", (_val_), \
		(_val_) == 1 ? "" : "s"); \
} while (0)

	ulong days = 0, hours = 0, minutes = 0;
	double precision; /* seconds.microseconds */
	static char d_str[MAX_UNIT_SIZE];
	static char h_str[MAX_UNIT_SIZE];
	static char m_str[MAX_UNIT_SIZE];
	static char s_str[MAX_UNIT_SIZE];

	precision = ((double)tv2->tv_sec + (double)tv2->tv_usec/1000000) -
		((double)tv1->tv_sec + (double)tv1->tv_usec/1000000);
	if (precision) {
		ulong seconds = (ulong)precision;

		minutes = seconds / 60;

		precision -= seconds; /* microseconds */
		seconds %= 60;
		precision += seconds;

		WRITE_TIME_BUF(s_str, "%f second", precision);
	}
	if (minutes) {
		hours = minutes / 60;
		minutes %= 60;
		WRITE_TIME_BUF(m_str, "%lu minute", minutes);
	}
	if (hours) {
		days = hours / 24;
		hours %= 24;
		WRITE_TIME_BUF(h_str, "%lu hour", hours);
	}
	if (days)
		WRITE_TIME_BUF(d_str, "%lu day", days);

	printf("%scalculation time:%s %s%s%s%s\n", C_RED, C_DEF, d_str, h_str,
		m_str, s_str);
}

