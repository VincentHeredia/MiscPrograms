###################################
# OS COURSE - Assignment 3
# 
###################################
CC = g++		# use g++ for compiling c++ code or gcc for c code
CFLAGS = -O -Wall	# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
LIB = -lm		# linked libraries	
LDFLAGS = -L.		# link flags
PROG = Assignment3Execute		# target executable (output)
OBJ = main.o random.o FCFS.o SJF.o Event.o Output.o Process.o  # object files for the target. Add more to this and next lines if there are more than one source files.
SRC = main.cpp random.cpp FCFS.cpp SJF.cpp Event.cpp Output.cpp Process.cpp		# .c or .cpp source files.  

all : $(PROG)

$(PROG): $(OBJ) 
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)


# cleanup
clean:
	/bin/rm -f *.o $(PROG)

# DO NOT DELETE
