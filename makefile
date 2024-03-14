bin/program: obj/main.o obj/server.o
	gcc -o bin/program obj/server.o obj/main.o

obj/main.o: src/main.c include/interface.h
	gcc -o obj/main.o -c src/main.c

obj/server.o: src/server.c include/interface.h
	gcc -o obj/server.o -c src/server.c

clean:
	rm -rf obj/*.o bin/program

check: 
	shell: /usr/bin/bash -e {0}

distcheck:
	shell: /usr/bin/bash -e {0}
