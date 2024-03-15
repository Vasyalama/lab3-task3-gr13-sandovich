bin/program: obj/main.o obj/marshrut.o
	gcc -o bin/program obj/marshrut.o obj/main.o

obj/main.o: src/main.c include/marshrut.h
	gcc -o obj/main.o -c src/main.c

obj/marshrut.o: src/marshrut.c include/marshrut.h
	gcc -o obj/marshrut.o -c src/marshrut.c

clean:
	rm -rf obj/*.o bin/program

