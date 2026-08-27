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

APP=tools2
CXX=g++
CC=gcc
CXXFLAGS=-std=c++17 -Wall -DDEBUG -ggdb -fPIC
CFLAGS=
PREFIX=/usr/local

SRC=src
BLD=build
OBJ=build
TST=build

# lib settings
INCLUDES=-I"/home/brian/src/boost_1_91_0" -I./$(SRC) -I./$(BLD) -I./$(TST)
LIBS=-fPIC -L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64 -lfmt -lcppunit
LDFLAGS=$(INCLUDES) $(LIBS)

OBJS= \
$(OBJ)/utility.o \
$(OBJ)/fileio.o \
$(OBJ)/utest.o \
$(OBJ)/singleton.o \
$(OBJ)/variant.o \
$(OBJ)/logger.o \
$(OBJ)/loop.o \
$(OBJ)/SmartPtr.o \
$(OBJ)/symtab.o \
$(OBJ)/tools2.o \
$(OBJ)/tools2_test.o \
$(OBJ)/TEST_tools2.o \
$(OBJ)/TEST_variant.o
#$(OBJ)/selectfd.o

OBJ_TST= \
$(OBJ)/TEST.o \
$(OBJ)/TEST_variant.o \
$(OBJ)/TEST_utility.o \
$(OBJ)/TEST_tools2.o \
$(OBJ)/TEST_symtab.o \
$(OBJ)/TEST_logger.o \
$(OBJ)/TEST_fileio.o

all: $(BLD)/TEST # $(BLD)/iomanip_ex $(BLD)/logger_test
	@echo -e "building prequisite -> $^ ... \nbuilding -> $@ ...$(FMT_RESET)"

$(BLD)/TEST: $(OBJ_TST)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(BLD)/tools2_test: $(OBJ)/tools2_test.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(BLD)/libtools.a: $(OBJS) 
	ar rvs $@ $^
	chmod 755 $@
	cp $@ ~/src/lib

$(BLD)/libtools2.so: $(BLD)/tools2.o
	$(CXX) $(CXXFLAGS) --shared $(OBJ)/tools2.o $(LDFLAGS) -o $(BLD)/libtools2.so
	chmod 755 $(BLD)/libtools2.so
	cp $(BLD)/libtools2.so ~/src/lib

# observer / observable pattern
$(OBJ)/observable.o: $(SRC)/observable.cpp
		$(CXX) $(CXXFLAGS) -c $(SRC)/observable.cpp -o $(OBJ)/observable.o

$(OBJ)/observer.o: $(SRC)/observer.cpp
		$(CXX) $(CXXFLAGS) -c $(SRC)/observer.cpp -o $(OBJ)/observer.o

$(OBJ)/observable_test.o: $(SRC)/observable_test.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/observable_test.cpp -o $(OBJ)/observable_test.o

$(BLD)/observable_test: $(OBJ)/observable_test.o $(SRC)/observable.o $(OBJ)/observer.o
	$(CXX) $(CXXFLAGS) $(OBJ)/observable_test.o $(SRC)/observable.o $(OBJ)/observer.o -o $(BLD)/observable_test

$(BLD)/iomanip_ex: $(OBJ)/iomanip_ex.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BLD)/logger_test: $(OBJ)/logger.o $(OBJ)/logger_test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# build object files
$(OBJ)/%.o: $(SRC)/%.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: all clean install unintsall rebuild help
rebuild: clean all

install:
	cp ./$(BLD)/tools2 ./$(prefix)/bin/tools2

uninstall:
	-rm ./$(prefix)/bin/tools2

clean:
	@echo "removing files ..."
	-rm -f $(OBJ)/*
	-rm -f $(BLD)/*

help:
	@echo
	@echo  'Project: tools2 : version 0.0.1 : Mon Aug 17 09:38:40 AM CDT 2026 simple "tools2" framework.'
	@echo
	@echo  '    make [-f] [target]'
	@echo
	@echo  '   -Make Targets ...'
	@echo
	@echo  '        * all                              - build all'
	@echo  '        * $(BLD)/tools2:          - re/build tools2'
	@echo  '        * $(BLD)/tools2_utest:    - re/build tools2_utest, unit testing'
	@echo  '        * clean                            - remove most generated files but keep the config'
	@echo

