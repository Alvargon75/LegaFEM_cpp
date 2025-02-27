# DEFAULT UNTOCHED MAKEFILE

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := inc
BIN_DIR := .

# Final target
EXE := $(BIN_DIR)/main

# Source files
C_SRC := $(wildcard $(SRC_DIR)/*.c)
CPP_SRC := $(wildcard $(SRC_DIR)/*.cpp)


# Get generated object files
C_OBJ := $(C_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CPP_OBJ := $(CPP_SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJ := $(C_OBJ) $(CPP_OBJ)

# Set compiler and flags
CC   := gcc
CXX  := g++
CEXE := $(CXX)                       # important, if your main file is .c set to $(CC), if main file is .cpp set to $(CXX)

CPPFLAGS := -I$(INC_DIR) -MMD -MP   # -I is a preprocessor flag, not a compiler flag
CFLAGS   := -Wall -Wextra           # some warnings about bad code for C
CXXFLAGS := -Wall -Wextra           # some warnings about bad code for CPP
LDFLAGS  := -Llib                   # -L is a linker flag
LDLIBS   := -lm                     # Left empty if no libs are needed


# RULES
.PHONY: all clean cleanWin

# main rule
all: $(EXE)

# linking rule
$(EXE): $(OBJ) | $(BIN_DIR)
	$(CEXE) $(LDFLAGS) $^ $(LDLIBS) -o $@

# C compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# CPP compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# BIN_DIR creation
$(BIN_DIR):
	mkdir $@

# OBJ_DIR creation
$(OBJ_DIR):
	mkdir $@

# Linux clean object and executable
clean:
	$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

# Windows clean object and executable
cleanWin:
	rmdir /q /s $(OBJ_DIR)
	del "$(EXE).exe"


-include $(OBJ:.o=.d)