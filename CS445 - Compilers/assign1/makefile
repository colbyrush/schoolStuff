BIN  = scanner
CC   = g++
CFLAGS = -DCPLUSPLUS -g  

SRCS = $(BIN).y $(BIN).l tree.c yyerror.cpp
HDRS = tokenStruct.h tree.h
OBJS = lex.yy.o $(BIN).tab.o
LIBS = -lfl -lm

$(BIN): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBS) -o c-

$(BIN).tab.h $(BIN).tab.c: $(BIN).y
	bison -v -t -d $(BIN).y  

lex.yy.c: $(BIN).l $(BIN).tab.h
	flex $(BIN).l

all:    
	touch $(SRCS)
	make

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c $(BIN).tab.h $(BIN).tab.c $(BIN).tar $(BIN).output *~

tar:
	tar -cvf $(BIN).tar $(SRCS) $(HDRS) makefile 
	ls -l $(BIN).tar
