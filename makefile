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

APP=tools
CXX=g++
CC=gcc
CXXFLAGS=-std=c++17 -Wall -DDEBUG -ggdb -fPIC

SRC=src
BLD=build
OBJ=build
TST=build

# lib settings
INCLUDES=-I"/home/brian/src/boost_1_91_0" -I./$(SRC) -I./$(BLD) -I./$(TST)
LIBS=-fPIC -L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64 -lfmt -lcppunit
LDFLAGS=$(INCLUDES) $(LIBS)

all: $(BLD)/libtools.a $(BLD)/libtools.so $(BLD)/TEST $(BLD)/logger_test # $(BLD)/iomanip_ex $(BLD)/logger_test
	@echo -e "building prequisite -> $^ ... \nbuilding -> $@ ...$(FMT_RESET)"

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
$(OBJ)/tools.o \
$(OBJ)/tools_test.o \
$(OBJ)/singleton.o \
$(OBJ)/tools_test.o 

$(BLD)/libtools.a: $(OBJS) 
	ar rvs $@ $^
	chmod 755 $@
	cp $@ ~/src/lib

$(BLD)/libtools.so: $(BLD)/tools.o
	$(CXX) $(CXXFLAGS) --shared $(OBJ)/tools.o $(LDFLAGS) -o $(BLD)/libtools.so
	chmod 755 $(BLD)/libtools.so
	cp $(BLD)/libtools.so ~/src/lib


OBJ_TST= \
$(OBJ)/TEST.o \
$(OBJ)/TEST_variant.o \
$(OBJ)/TEST_utility.o \
$(OBJ)/TEST_tools.o \
$(OBJ)/TEST_symtab.o \
$(OBJ)/TEST_logger.o \
$(OBJ)/TEST_fileio.o \
$(OBJ)/TEST_singleton.o

$(BLD)/TEST: $(OBJ_TST)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# $(OBJ)/observable.o: $(SRC)/observable.cpp
# 		$(CXX) $(CXXFLAGS) -c $(SRC)/observable.cpp -o $(OBJ)/observable.o

# $(OBJ)/observer.o: $(SRC)/observer.cpp
# 		$(CXX) $(CXXFLAGS) -c $(SRC)/observer.cpp -o $(OBJ)/observer.o

# $(OBJ)/observable_test.o: $(SRC)/observable_test.cpp
# 	$(CXX) $(CXXFLAGS) -c $(SRC)/observable_test.cpp -o $(OBJ)/observable_test.o

# $(BLD)/observable_test: $(OBJ)/observable_test.o $(SRC)/observable.o $(OBJ)/observer.o
# 	$(CXX) $(CXXFLAGS) $(OBJ)/observable_test.o $(SRC)/observable.o $(OBJ)/observer.o -o $(BLD)/observable_test

$(BLD)/iomanip_ex: $(OBJ)/iomanip_ex.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BLD)/logger_test: $(OBJ)/logger.o $(OBJ)/logger_test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BLD)/tools_test: $(OBJ)/tools_test.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@


# build object files
$(OBJ)/%.o: $(SRC)/%.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: all clean install unintsall rebuild help
rebuild: clean all

install:
	cp ./$(BLD)/tools ./$(prefix)/bin/tools

uninstall:
	-rm ./$(prefix)/bin/tools

clean:
	@echo "removing files ..."
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
	@echo  '        * $(BLD)/tools:                   - re/build tools'
	@echo  '        * $(BLD)/tools_utest:             - re/build tools_utest, unit testing'
	@echo  '        * clean                            - remove most generated files but keep the config'
	@echo

