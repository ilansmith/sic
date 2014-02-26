#include <sys/time.h>

typedef struct timeval timeval;
typedef unsigned long ulong;

void time_clear(timeval *tv);
void print_time(timeval *tv1, timeval *tv2);

