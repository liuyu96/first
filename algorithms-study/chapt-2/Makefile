#

sort: sort.o insertion_sort.o merge_sort.o choose_sort.o
	gcc $^ -o $@ -g

bisearch: binary-search.o
	gcc $^ -o $@ -g

clean:
	-rm *.o
	-rm sort
	-rm bisearch

%.o: %.c
	gcc -g -c $^
