unic: main.o lex.yy.o
	cc -o unic main.o lex.yy.o -ll

main.o: main.c unic.h
	cc -c -g main.c

lex.yy.o: lex.yy.c unic.h
	cc -c -g lex.yy.c

lex.yy.c: unic.l
	flex unic.l
