CC=g++
CCFLAGS=-std=c++11
LIBS=-lm

driver: StudentDatabase.o Driver.o
		$(CC) $(CCFLAGS) StudentDatabase.o Driver.o -o driver $(LIBS)
		
StudentDatabase.o: StudentDatabase.cpp StudentDatabase.h
				$(CC) $(CCFLAGS) StudentDatabase.cpp -c
				
Driver.o: Driver.cpp
		$(CC) $(CCFLAGS) Driver.cpp -c

run: 
		./driver
		
clean: 
		@rm -f *.o
		@rm -f driver
		
install: 
		@mv Driver -/bin
