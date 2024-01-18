all:repeatedly_run

repeatedly_run: main.o
				gcc main.o -o repeatedly_run

main.o:	main.c
		gcc	-c	main.c

clean:
		rm	-rf	*o repeatedly_run