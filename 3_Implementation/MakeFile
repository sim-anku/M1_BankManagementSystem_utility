PROJECT_NAME = main

SRC =src/add.c \
src/basicinfo.c \
src/delete.c \
src/display.c \
src/modify.c \
src/search.c \

BUILD = build

#INC=inc
UNI=unity/unity.c

INC	= inc\
-Iunity\

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
TEST_SRC = test/test_record


PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

INCLUDE_LIBS = -lcunit

PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

.PHONY: run clean test doc 

$(PROJECT_NAME).exe : $(SRC)
	gcc -I $(INC) $(PROJECT_NAME).c $(SRC)  -o $(PROJECT_NAME).exe

run: $(PROJECT_NAME).exe
	$(PROJECT_NAME).exe

doc:
	make -C ./documentation

test:$(TEST)
	gcc -Iinc $(INC) $(UNI) $(SRC) $(TEST_SRC).c -o test\test_record.exe
	./test\test_record.exe

clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)

$(BUILD):
	mkdir build

all: $(SRC) $(BUILD)
	    gcc -I inc $(UNI) $(SRC) $(INC) $(TEST_SRC).c -o $(PROJECT_OUTPUT)

run1:
	./$(PROJECT_OUTPUT)
