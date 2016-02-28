#

sort: sort.o insertion_sort.o merge_sort.o choose_sort.o
	gcc $^ -o $@ -g

clean:
	-rm *.o
	-rm sort

%.o: %.c
	gcc -g -c $^
