proyecto: proyecto.o
        gcc proyecto.o -o Programa -lm

proyecto.o: proyecto.c lista.h
        gcc -c proyecto.c -lm

clean:
        rm -f Programa *.o

