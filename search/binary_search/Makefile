main: main.o binary_search.o
	cc main.o binary_search.o

main.o: main.c binary_search.h
	cc -c main.c
binary_search.o: binary_search.c
	cc -c binary_search.c

clean:
	-rm *.out *.o two_dimension_array

