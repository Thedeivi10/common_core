OBJS = main.o salida.o calculadora.o 
BINARY = programa 
#Esto es un comentario
CFLAGS = -g -Wall 
all: programa 
#Primera regla antes de los dos puntos esta el objetivo y lo que lo sigue son las dependencias que es lo necesario
programa: $(OBJS)
	gcc -o $@ $? 

%.o: %.c
		gcc $(CFLAGS) -c $< -o $@
clean: 
		@rm -f $(BINARY) $(OBJS) 
#clean es una regla phony que no necesita dependencias y es ficticia es para hacer algo y borra los punto o y programa ahora
				