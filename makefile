# change application name here (executable output name)
TARGET=initest
 
# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall
 
PTHREAD=-pthread
 
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

EVDEVLIB=
 
# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(EVDEVLIB) -export-dynamic
 
OBJS=	initest.o iniman.o
 
all: $(OBJS)
	$(LD) -g -o $(TARGET) $(OBJS) $(LDFLAGS)
    
iniman.o: iniman.c
	$(CC) -c $(CCFLAGS) iniman.c -o iniman.o

initest.o: initest.c
	$(CC) -c $(CCFLAGS) initest.c -o initest.o

clean:
	rm -f *.o $(TARGET)
