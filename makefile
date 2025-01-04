# Makefile for compiling the project on Windows

# Compiler and flags
CC = gcc
CFLAGS = -I./Include

# Directories
SRCDIR = ./src
BUILDDIR = ./src

# Source, object files, and output
SRC = $(SRCDIR)/main.c
OBJ = $(BUILDDIR)/main.o
OUT = program.exe

# Default target to build the program
all: $(OUT)

# Link the object file to create the executable
$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ)

# Compile source file into object file in the src folder
$(OBJ): $(SRC)
	$(CC) -c $(SRC) $(CFLAGS) -o $(OBJ)

# Clean up build files (Windows-specific)
clean:
	del /f "$(BUILDDIR)\main.o" "$(OUT)"

# Rebuild the project (clean + build)
rebuild: clean all
