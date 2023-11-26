OFILES = fileManager.o administrador.o main.o bodeguero.o vendedor.o

Tarea1: ${OFILES}
	gcc -o Tarea1 ${OFILES}

fileManager.o: fileManager.c data.h fileManager.h usuarios.h administrador.h bodeguero.h vendedor.h

administrador.o: administrador.c fileManager.h administrador.h usuarios.h

main.o: main.c administrador.h vendedor.h bodeguero.h usuarios.h data.h

bodeguero.o: fileManager.h bodeguero.h usuarios.h bodeguero.c

vendedor.o: fileManager.h vendedor.c vendedor.h bodeguero.h

clear: 
	rm *.o Tarea1
