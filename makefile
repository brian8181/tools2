# @name     tools2
# @file:    makefile
# @date:    Mon Aug 17 09:38:40 AM CDT 2026
# @version: version 0.0.1

# g++ warnings
#-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror -Wundef
#-fsanitize=undefined,address -Wfloat-equal -Wformat-nonliteral
#-Wformat-security -Wformat-y2k -Wformat=2 -Wimport -Winvalid-pch
#-Wlogical-op -Wmissing-declarations -Wmissing-field-initializers
#-Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn
#-Wnested-externs -Wpacked -Wpointer-arith -Wredundant-decls
#-Wstack-protector -Wstrict-null-sentinel -Wswitch-enum -Wwrite-strings
SHELL:=bash
RED=\033[31m
GREEN=\033[32m
RESET=\033[0m

APP=tools
CXX=g++
CC=gcc
CXXFLAGS=-std=c++17 -Wall -DDEBUG -ggdb -fPIC

SRC=src
BLD=build
OBJ=build
TST=build

# lib settings
#INCLUDES=-I"/home/brian/src/boost_1_91_0" -I./$(SRC) -I./$(BLD) -I./$(TST)
#INCLUDES=
LIBS=/usr/local/lib/libcppunit.a
#LDFLAGS=$(INCLUDES) $(LIBS)
LDFLAGS= $(LIBS)

all: $(BLD)/libutilcxx.a $(BLD)/libutilcxx.so $(BLD)/TEST $(BLD)/utilcxx $(BLD)/utilcxx2
	@echo -e "building prequisite -> $^ ... \nbuilding -> $@ ...$(FMT_RESET)"
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	ls -alF $(BLD)
	@echo -e "$(GREEN)Build \"$@\" complete ...$(RESET)"

OBJS=\
$(OBJ)/string.o \
$(OBJ)/fileio.o \
$(OBJ)/utest.o \
$(OBJ)/variant.o \
$(OBJ)/logger.o \
$(OBJ)/symtab.o

$(BLD)/libutilcxx.a: $(OBJS)
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	ar rvs $@ $^
	chmod 755 $@
	cp $@ ~/src/lib

$(BLD)/libutilcxx.so: $(OBJS)
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) -shared -o $@ $^
	chmod 755 $@
	cp $@ ~/src/lib #sudo ldconfig

OBJ_TST= \
$(OBJ)/TEST.o \
$(OBJ)/variant.o \
$(OBJ)/string.o \
$(OBJ)/logger.o \
$(OBJ)/fileio.o \
$(OBJ)/symtab.o \
$(OBJ)/utest.o \
$(OBJ)/TEST_variant.o \
$(OBJ)/TEST_string.o \
$(OBJ)/TEST_tools.o \
$(OBJ)/TEST_logger.o \
$(OBJ)/TEST_fileio.o \
$(OBJ)/TEST_singleton.o \
$(OBJ)/TEST_symtab.o \
$(OBJ)/TEST_observer_observable.o \
$(OBJ)/TEST_utest.o

$(BLD)/TEST: $(OBJ_TST)
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(BLD)/utilcxx: $(BLD)/tools.o $(BLD)/libutilcxx.a  
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# target for the executable (linking against the shared library)
$(BLD)/utilcxx2: $(BLD)/tools.o $(BLD)/libutilcxx.so
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) $(CXXFLAGS) $< -L$(BLD) -lutilcxx $(LDFLAGS) -Wl,-rpath,$(BLD) -o $@
	
# build object files
$(OBJ)/%.o: $(SRC)/%.c
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	@echo -e "$(GREEN)Target -> \"$@: $^$(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean install unintsall rebuild help
rebuild: clean all

install:
	cp ./$(BLD)/utilcxx ./$(prefix)/bin/utilcxx

uninstall:
	-rm ./$(prefix)/bin/utilcxx

clean:
	@echo -e "$(RED)Removing files ...$(RESET)"
	-rm -f $(OBJ)/*
	-rm -f $(BLD)/*

help:
	@echo
	@echo  'Project: tools : version 0.0.1 : Mon Aug 17 09:38:40 AM CDT 2026 simple "tools" framework.'
	@echo
	@echo  '    make [-f] [target]'
	@echo
	@echo  '    -Make Targets ...'
	@echo
	@echo  '        * all                              - build all'
	@echo  '        * $(BLD)/utilcxx:                 - re/build utilcxx'
	@echo  '        * $(BLD)/utilcxx2:                - re/build utilcxx2'
	@echo  '        * clean                            - remove most generated files but keep the config'
	@echo

