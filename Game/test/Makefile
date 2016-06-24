NAME = 7KeysTest

SRC_DIR = src
SRC_GAM_DIR = ../src
OBJ_DIR = ../obj
OBJ_GAM_DIR = ../obj
LIB_DIR = lib
BIN_DIR = bin

CC = g++

CFLAGS = -W -Wall -pedantic -std=c++11 -MMD -g3
INCLUDES = -Iinclude `sdl2-config --cflags` -I/usr/local/include/ijengine
LIBS = -lijengine `sdl2-config --libs` -lpthread -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lcppunit

TEST = $(BIN_DIR)/$(NAME)

SRC = ${wildcard $(SRC_DIR)/*.cpp}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.cpp=.o}}}
# SRC_GAM = ${wildcard $(SRC_GAM_DIR)/.cpp}
# SRC_GAM := $(filter-out $(SRC_GAM_DIR)/main.cpp, $(SRC_GAM))
# OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC_GAM:.cpp=.o}}}

.PHONY: clean depend

all:
	cd ../lib; make clean
	cd ../lib; make
	cd ..; sudo make clean
	cd ..; sudo make -j
	@mkdir -p $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)
	sudo $(MAKE) $(TEST)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Building $@ ...
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(TEST): $(OBJ)
	@echo Builting tests executable...
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@ $(LIBS)
	@echo --- Done

lib: $(OBJ)
	@echo ar rcs $(LIB_DIR)/libjtj.a $(OBJ)
	@ar rcs $(LIB_DIR)/libjtj.a $(OBJ)

clean:
	@echo Cleaning...
	@find . -name *.o -exec rm {} \;
	@find . -name *.d -exec rm {} \;
	@rm -rf *~ *.o bin out.txt obj lib/babel.a

testGuard: $(SRC_DIR)/guardTest.cpp
	@echo Compiling $@
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(BIN_DIR)/$@ $<  $(LIBS)
	@echo --- Done, $(BIN_DIR)/$@ created

-include $(OBJ:.o=.d)
