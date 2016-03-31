CC=gcc -O1 -march=native -mtune=native -std=c99

DEPS = tp9.h
OBJS = insertion_sort.o quick_sort.o heap_sort.o merge_sort.o shell_sort.o utils.o tp9.o

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@

tp9: $(OBJS)
	$(CC) $(OBJS) -lm -o $@

clean:
	rm *.o tp9 performans.pdf perf.txt
