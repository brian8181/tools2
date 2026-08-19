# FILE: makefile
# VERSION: 0.0.3
# FILE_DATE: Tue Aug 18 05:08:41 PM CDT 2026
# INFO: basic makefile

CXX=g++
CC=gcc
CXXFLAGS=-std=c++17 -Wall -DDEBUG -ggdb
CFLAGS=
CXXEXTRA=#-Wall -Wextra -Wno-interference-size
PREFIX=/usr/local
APPNAME=tools
BLD=build
OBJ=build
SRC=src

# lib settings
INCLUDES=-I/usr/local/include/cppunit -I"/home/brian/src/boost_1_91_0" -I"/home/brian/src/cppunit-1.15.1/include/" -I./$(SRC) -I./$(BLD) -I./$(TST)
LIBS=-fPIC -L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64 -lfmt -lcppunit
LDFLAGS=$(INCLUDES) $(LIBS) $(INC)

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
$(OBJ)/TEST_tools2.o \
$(OBJ)/tools2_test.o
#$(OBJ)/TEST_variant.o
#$(OBJ)/selectfd.o


all: $(BLD)/libtools.a $(BLD)/TEST_tools2
	@echo -e "building prequisite -> $^ ... \nbuilding -> $@ ...$(FMT_RESET)"
#$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

rebuild: clean all

$(OBJ)/%.o: $(SRC)/%.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(BLD)/libtools.a: $(OBJS) 
	ar rvs $@ $^
	chmod 755 $@
	cp $@ ~/src/lib

$(BLD)/await: $(OBJ)/await.o
	$(CXX) $(CXXFLAGS) -std=c++23 -fcoroutines $^ -o $@

$(OBJ)/%.o: $(SRC1)/%.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(BLD)/TEST_tools2: $(OBJ)/TEST_tools2.o 
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(BLD)/tools2_test: $(OBJ)/tools2_variant.o $(OBJ)/tools2_test.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# $(OBJ)/float_bytes: $(SRC)/float_bytes.cpp
# 	$(CXX) $(CXXFLAGS) $(SRC)/float_bytes.cpp -o $(OBJ)/float_bytes

# # observer / observable pattern
# $(OBJ)/observable.o: $(SRC)/observable.cpp
# 		$(CXX) $(CXXFLAGS) -c $(SRC)/observable.cpp -o $(OBJ)/observable.o

# $(OBJ)/observer.o: $(SRC)/observer.cpp
# 		$(CXX) $(CXXFLAGS) -c $(SRC)/observer.cpp -o $(OBJ)/observer.o

# $(OBJ)/observable_test.o: $(SRC)/observable_test.cpp
# 	$(CXX) $(CXXFLAGS) -c $(SRC)/observable_test.cpp -o $(OBJ)/observable_test.o

# $(BLD)/observable_test: $(OBJ)/observable_test.o $(SRC)/observable.o $(OBJ)/observer.o
# 	$(CXX) $(CXXFLAGS) $(OBJ)/observable_test.o $(SRC)/observable.o $(OBJ)/observer.o -o $(BLD)/observable_test

# $(BLD)/libutility.so: $(BLD)/utility.o
# 	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared $(OBJ)/utility.o -o $(BLD)/libutility.so
# 	chmod 755 $(BLD)/libutility.so
# 	cp $(BLD)/libutility.so ~/src/lib

# $(BLD)/fileio.so: $(BLD)/fileio.o
# 	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared $(OBJ)/fileio.o -o $(BLD)/libfileio.so
# 	chmod 755 $(BLD)/libfileio.so
# 	cp $(BLD)/libfileio.so ~/src/lib

# $(BLD)/libutility.a: $(BLD)/utility.o
# 	ar rvs $(BLD)/libutility.a $(OBJ)/utility.o
# 	chmod 755 $(BLD)/libutility.a
# 	cp $(BLD)/libutility.a ~/src/lib

# $(BLD)/libfileio.so: $(BLD)/fileio.o
# 	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared $(OBJ)/fileio.o -o $(BLD)/libfileio.so
# 	chmod 755 $(BLD)/libfileio.so
# 	cp $(BLD)/libfileio.so ~/src/lib

# $(BLD)/libfileio.a: $(BLD)/fileio.o
# 	ar rvs $(BLD)/libfileio.a $(OBJ)/fileio.o
# 	chmod 755 $(BLD)/libfileio.a
# 	cp $(BLD)/libfileio.a ~/src/lib

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

