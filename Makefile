CC=gcc
CPP=cpp

SIC_TARGETS=ack fact fib_rec fib_iter

.PHONY: all clean cleanall
all: $(SIC_TARGETS)

CFLAGS=-g -Wall -ansi -Werror
LDLIBS=
OBJS=sic.o

#configs
CONFIG_CALCULATE_TIME=y
CONFIG_LARGE_ADDRESS=y

# add time calculation
ifeq ($(CONFIG_CALCULATE_TIME),y)
CFLAGS+=-DCONFIG_CALCULATE_TIME
LDLIBS+=-lm
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
	$(CC) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

%_pre.c: %.c
	$(CPP) -x c -o $@ $<

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

# clean up
clean:
	rm -rf *.o *_pre.c
cleanall: clean
	rm -rf *.mk tags
	file `ls` | grep executable | awk -F: '{ print $$1 }' | xargs rm -f

