# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = 

# Automatically find all .c files in the current directory
SRCS = $(wildcard *.c) # main.c hello.c bye.c
OBJS = $(SRCS:.c=.o) # main.o hello.o bye.o

# Targets
all: program
	@echo "========================================Build is Done========================================"

# Preprocessing
preprocess: $(SRCS)
	$(CC) $(CFLAGS) -E $< -o $(basename $<).i

# Assembly
assemble: $(SRCS)
	$(CC) $(CFLAGS) -S $< -o $(basename $<).s

# Build the program
program: $(OBJS)
	$(CC) $(OBJS) -o program $(LDFLAGS)

# Rule to compile each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files, program, and intermediate files
clean:
	rm -f *.o program *.i *.s
