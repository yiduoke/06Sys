all: linkedList.c
	gcc -o linked_list linkedList.c

clean:
	rm *.o
	rm *~

run: all
	./linked_list