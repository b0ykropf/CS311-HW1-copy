CC=gcc
CFLAGS=-Wall -std=c99
all: anycopy tex
anycopy: anycopy.c error.c
	$(CC) $(CFLAGS) anycopy.c error.c -o anycopy
tex: any_copy.tex
	pdflatex any_copy.tex
clean:
	rm -rf anycopy *aux *log *out *pdf
