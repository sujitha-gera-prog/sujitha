all: calculator
	echo "done"
calculator: fun.o add.o 
	gcc fun.o add.o -o cal
fun.o:fun.c
	gcc -c fun.c
add.o:add.c
	gcc -c add.c
clean:
	rm *.o calculator
