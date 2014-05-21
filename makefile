# Author -- Nafees Noor #
# UNIX ID -- nn319918   #
# This is a make file   #


.SUFFIXES: .c .o

CC = gcc 

CFLAGS = -g -Wall

.c.o:
	$(CC) $(CFLAGS) -c $<

all:    p5a  p5b_server  p5b_client

p5a: 	p5a.o Check_Flag.o
	gcc p5a.o Check_Flag.o -o p5a

p5a.o:	macros.h

p5b_server:	p5b_server.o partb_Check_Arg.o
		gcc p5b_server.o partb_Check_Arg.o -o p5b_server

p5b_server.o:	struct_def.h macros.h

p5b_client:	p5b_client.o CHECK_FLAG.o
		gcc p5b_client.o CHECK_FLAG.o -o p5b_client

p5b_client.o:	struct_def.h macros.h

clean:
	rm -f *.o core
