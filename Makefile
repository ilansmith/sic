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

define hl
\033[1m$1\033[0m
endef

define help_print_tool
  @printf "$(call hl,%-8s) - %s.\n" $1 $2
endef

help:
	@printf "usage:\n"
	@printf "     $$ $(call hl,make [TARGETS] [OPTIONS])      [build the sic functions]\n"
	@printf "     or\n"
	@printf "     $$ $(call hl,make [TARGETS]_pre.c)          [preprocess a sic function c file]\n"
	@printf "\n"
	@printf "Where $(call hl,TARGETS) is any combination of:\n"
	$(call help_print_tool,"fact","factorial function")
	$(call help_print_tool,"fib_iter","fibonacci function iterative implementation")
	$(call help_print_tool,"fib_rec","fibonacci function recursive implementation")
	$(call help_print_tool,"ack","ackermann function")
	@printf "Specifying no targets is equivilent to specifying all of them.\n"
	@printf "\n"
	@printf "And $(call hl,OPTIONS) is any combination of:\n"
	$(call help_print_tool,"CONFIG_CALCULATE_TIME=y","time execution duration")
	$(call help_print_tool,"CONFIG_LARGE_ADDRESS=y","use a large address space (useful on 32-bit systems)")
	@printf "\n"
	@printf "     or\n"
	@printf "\n"
	@printf "     $$ $(call hl,make clean)                    [clean intermediate files]\n"
	@printf "     $$ $(call hl,make cleanall)                 [clean everything]\n"


