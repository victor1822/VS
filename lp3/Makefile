sumdata.o : sumdata.c sumdata.h
	gcc -Wall -Werror -E sumdata.c > sumdata.i
	gcc -Wall -Werror -S sumdata.i
	gcc -Wall -Werror -c sumdata.s
summain.o : summain.c sumdata.h
	gcc -Wall -Werror -E summain.c > summain.i
	gcc -Wall -Werror -S summain.i
	gcc -Wall -Werror -c summain.s

sqrmain.o : sqrmain.c sumdata.h
	gcc -Wall -Werror -E sqrmain.c > sqrmain.i
	gcc -Wall -Werror -S sqrmain.i
	gcc -Wall -Werror -c sqrmain.s

sum : summain.o sumdata.o
	gcc -Wall -Werror sumdata.o summain.o -o sum

sqr : sumdata.o sqrmain.o
	gcc -Wall -Werror sumdata.o sqrmain.o -o sqr
 .PHONY: clean

clean:
	rm *.i *.s *.o sum

all: clean sqr sum
