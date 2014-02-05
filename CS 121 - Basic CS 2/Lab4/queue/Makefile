#  Makefile
#    a makefile for the stack example.
#

#            SHELL = 	/bin/sh

#              TOP = .
#      CURRENT_DIR = .

#              CPP = /lib/cpp $(STD_CPP_DEFINES)
              CXX  = g++

#        CCOPTIONS =
#           CFLAGS = $(CDEBUGFLAGS) $(CCOPTIONS) $(ALLDEFINES)
#           RM_CMD = $(RM) *.o core

SRCS=	listQ.cpp	\
	queueL.cpp	\
	testQueue.cpp

OBJS=	listQ.o		\
	queueL.o	\
	testQueue.o

listQ.o:	listQ.cpp \
	listQ.h

queueL.o:	queueL.cpp \
	queueL.h \
	listQ.h

testQueue.o:	testQueue.cpp \
	queueL.h \
	listQ.h

PROGRAMS = testQueue

all::  $(PROGRAMS)


testQueue: $(OBJS)
	$(CXX) -o $@ $(OBJS)
#$(CXX) -o $@ $(OBJS) $(LDOPTIONS) $(LOCAL_LIBRARIES) $(LDLIBS)  $(EXTRA_LOAD_FLAGS)

clean::
	$(RM) testQueue 

latex::
	latex queue.tex    

###########################################################################
# common rules for all Makefiles - do not edit

emptyrule::

clean::
	rm *.o

