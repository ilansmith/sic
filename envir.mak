CC=gcc
CFLAGS=-g -Wall -ansi -Werror
LDLIB=
OBJS=sic.o
COMPILE=$(CC) -o $@ $(CFLAGS) -c $<
LINK=$(CC) -o $@ $(LDLIB) $^
PREPROCESS=cpp -x c -o $@ $<

#configs
CONFIG_CALCULATE_TIME=n
CONFIG_LARGE_ADDRESS=n

# add time calculation
ifeq ($(CONFIG_CALCULATE_TIME),y)
CFLAGS+=-DCONFIG_CALCULATE_TIME
LDLIB+=-lm
OBJS+=time.o
endif

# use big numbers
ifeq ($(CONFIG_LARGE_ADDRESS),y)
CFLAGS+=-DCONFIG_LARGE_ADDRESS
else # ISO C90 does not support 'long long'
CFLAGS+=-pedantic-errors
endif

# rules
%: %.o
	$(LINK)
%.o: %.c
	$(COMPILE)
%_pre.c: %.c
	$(PREPROCESS)
%.mk: %.c
	echo $*: $*.o $(OBJS) > $@; \
	set -e; $(CC) -MM $< \
	| sed 's/\($*\)\.o[ :]*/\1.o $@: /g' >> $@; \
	echo $*_pre.c: $*.c >> $@

# test which targets to build
ifdef MAKECMDGOALS
ifeq ("$(MAKECMDGOALS)","all")
BUILD=$(SIC_TARGETS)
else
# XXX assert that MAKECMDGOALS is a subset of the available targets
BUILD=$(MAKECMDGOALS)
endif
else
BUILD=$(SIC_TARGETS)
endif

# include required targets for each application
ifneq ("$(strip $(BUILD))","")
-include $(BUILD:%=%.mk)
endif

