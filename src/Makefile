# Time-stamp: <2018-06-11 19:44:20 daniel>

#
# Makefile
#

#
# This is the main Makefile for 'block.parse', a simplified
# listsinceblock parser.
#

# Macros
cc := /usr/bin/g++
ccflags := -g -std=c++17

# Rules
%.d : %.cc ; $(cc) $(ccflags) -c -MM -MT $(<:.cc=.o) -MT $(<:.cc=.d) -MF $(<:.cc=.d) $<
%.o : %.cc ; $(cc) $(ccflags) -c -o $@ $<
CC := /usr/bin/g++

# Libraries used to build block.parse
libs := -lboost_program_options -lsqlite3

# Source files plus the dependency and object files
source := lite query report json fstring notation transaction application main
dependents := $(addsuffix .d,$(source))
objs := $(addsuffix .o,$(source))

# Define the targets for this Makefile
target := block.parse deposit.db $(dependents)

# Main target - really several targets
all:	$(target) ; @./block.parse

# Required to add build instructions for all .cc files
include $(dependents)

# Targets
deposit.db: deposit.sql ; sqlite3 --init deposit.sql $@ .exit
block.parse:	$(objs) ; $(CC) $(libs) -o $@ $^

# Remove all 'built' files
.PHONY: clean
clean : ; rm -f *.o $(target)
