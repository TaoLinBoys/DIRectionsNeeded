compile: dirInfo.c
	gcc dirInfo.c -o directions

run: directions
	./directions

clean:
	rm *~
	rm *.o
