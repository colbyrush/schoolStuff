BIN  = parser
CC   = g++
CFLAGS = -DCPLUSPLUS -g     # for use with C++ if file ext is .c

SRCS = $(BIN).y $(BIN).l tree.c analyze.c symtab.cpp yyerror.cpp mystrings.cpp
HDRS = tokenStruct.h tree.h symtab.h yyerror.h mystrings.h
OBJS = lex.yy.o $(BIN).tab.o
LIBS = -lfl -lm

$(BIN):$(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) yyerror.cpp mystrings.cpp $(LIBS) -o c-

$(BIN).tab.h $(BIN).tab.c:$(BIN).y
	bison -v -t -d $(BIN).y  

lex.yy.c:$(BIN).l $(BIN).tab.h
	flex $(BIN).l

all:    
	touch $(SRCS)
	make

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c $(BIN).tab.h $(BIN).tab.c $(BIN).tar $(BIN).output *~