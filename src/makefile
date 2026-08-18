# FILE: makefile
# VERSION: 0.0.3
# FILE_DATE: Sat Sep 21 05:55:14 AM CDT 2024
# INFO: basic makefile

CXX = g++
CC = gcc
CXXFLAGS = -std=c++23 -Wall -DDEBUG -ggdb # -fanalyzer
#CXXFLAGS = -std=c++17 -Wall -DDEBUG -ggdb
CFLAGS=
CXXEXTRA = #-Wall -Wextra -Wno-interference-size
#LDFLAGS = -fPIC -L/usr/local/lib/libfmtd.so
#LDFLAGS = -fPIC -L/usr/local/lib64/libfmt.a
#LDFLAGS = -static -lcppunit -L/usr/local/lib/
#INCLUDES = -I/usr/local/include/cppunit/
PREFIX=/usr/local
APPNAME = tools
BLD = ../build
OBJ = ../build
SRC = .

# NEW
# lib settings
INCLUDES=-I/usr/local/include/cppunit/ -I"/home/brian/src/boost_1_91_0" -I./$(SRC) -I./$(BLD) -I./$(TST)
LIBS=-fPIC -L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64 -lfmt
LDFLAGS=$(INCLUDES) $(LIBS) $(INC)

OBJS= \
$(OBJ)/utility.o \
$(OBJ)/fileio.o \
$(OBJ)/utest.o \
$(OBJ)/singleton.o \
$(OBJ)/symtab.o \
$(OBJ)/variant.o \
$(OBJ)/logger.o \
$(OBJ)/loop.o \
#$(OBJ)/selectfd.o


tools: $(OBJS) 
	@echo "$(FMT)$(RELEASE)-building prequisite -> $^ ... \nbuilding -> $@ ...$(FMT_RESET)"
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# %.o: %.c:
# 	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BLD)/test1: $(SRC)/test1.cpp $(OBJ)/colorize.o
	$(CXX) $(CXXFLAGS) $(SRC)/test1.cpp $(OBJ)/colorize.o -o $(BLD)/test1

$(OBJ)/float_bytes: $(SRC)/float_bytes.cpp
	$(CXX) $(CXXFLAGS) $(SRC)/float_bytes.cpp -o $(OBJ)/float_bytes

# observer / observable pattern
$(OBJ)/observable.o: $(SRC)/observable.cpp
		$(CXX) $(CXXFLAGS) -c $(SRC)/observable.cpp -o $(OBJ)/observable.o

$(OBJ)/observer.o: $(SRC)/observer.cpp
		$(CXX) $(CXXFLAGS) -c $(SRC)/observer.cpp -o $(OBJ)/observer.o

$(OBJ)/observable_test.o: $(SRC)/observable_test.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/observable_test.cpp -o $(OBJ)/observable_test.o

$(BLD)/observable_test: $(OBJ)/observable_test.o $(SRC)/observable.o $(OBJ)/observer.o
	$(CXX) $(CXXFLAGS) $(OBJ)/observable_test.o $(SRC)/observable.o $(OBJ)/observer.o -o $(BLD)/observable_test

.PHONY: clean
clean:
	-rm -rf $(OBJ)/*
	-rm -rf $(BLD)/*

