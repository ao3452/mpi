# Makefile
# プログラム名とオブジェクトファイル名
program = Mpi
OBJ     = mpi1.o
OPT	= -O2 -Wall
LINK    = $(HOME)/zemi/b4kadai/MPI/include
CC      = gcc

$(program): $(OBJ)
	$(CC) -o  $(program) $(OBJ) 
# サフィックスルール
.c.o:
	$(CC) -c $< $(OPT) -I$(LINK)

.PHONY: clean
clean:
	rm -f $(program) $(OBJ)