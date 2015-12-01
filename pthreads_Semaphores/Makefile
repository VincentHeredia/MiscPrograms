###################################
# Assignment 4
# 
###################################
CC = g++		# use g++ for compiling c++ code or gcc for c code
CFLAGS = -O2 -Wall	# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
LIB = -lm -pthread		# linked libraries	
LDFLAGS = -L.		# link flags
PROG = assign4run		# target executable (output)
OBJ = main.o 		# object files for the target. Add more to this and next lines if there are more than one source files.
SRC = main.cpp		# .c or .cpp source files.  

all : $(PROG)

$(PROG): $(OBJ) 
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)


# cleanup
clean:
	/bin/rm -f *.o $(PROG)

# DO NOT DELETE
