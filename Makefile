# Compiler
CC := gcc

# Flags for debugging and warnings
CFLAGS := -Wall -Wextra -std=c11

# Output executable names
FOOTBALL_EXEC := football.exe
TEMPERATURE_EXEC := temperature.exe

# Source files
FOOTBALL_SRC := football_main.c football.c
TEMPERATURE_SRC := temperature_main.c temperature.c

# Object files
FOOTBALL_OBJ := $(FOOTBALL_SRC:.c=.o)
TEMPERATURE_OBJ := $(TEMPERATURE_SRC:.c=.o)

# Default target (build everything)
all: $(FOOTBALL_EXEC) $(TEMPERATURE_EXEC)

# Rule to build football.exe
$(FOOTBALL_EXEC): $(FOOTBALL_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build temperature.exe
$(TEMPERATURE_EXEC): $(TEMPERATURE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(FOOTBALL_OBJ) $(TEMPERATURE_OBJ) $(FOOTBALL_EXEC) $(TEMPERATURE_EXEC)
