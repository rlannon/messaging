SRC_DIR=./src
INCLUDE_DIR=./include
OBJ_DIR=./bin
SRC_FILES=$(wildcard $(SRC_DIR)/*.cxx)
OBJ_FILES=$(patsubst %.cxx, $(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))
cc=clang++
cppversion=c++20
flags=-std=$(cppversion) -g -I $(INCLUDE_DIR)
target=messaging.a

default: $(target)

$(target): $(OBJ_FILES)
	@echo Creating library file...
	ar r $@ $^
	@echo Done.

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cxx
	$(cc) $(flags) -c -o $@ $<

clean:
	rm -f bin/*.o
	rm -f ./$(target)

.PHONY: $(target) clean
