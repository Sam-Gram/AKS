#makefile for the AKS prime finder version 0.1
CC=g++

CFLAGS=-lgmp

all: AKS

AKS: main.o aks.o binomial.o 
	$(CC) main.o aks.o binomial.o $(CFLAGS) -o AKS

main.o: main.cpp
	$(CC) -c main.cpp

aks.o: aks.cpp
	$(CC) -c aks.cpp

binomial.o: binomial.cpp
	$(CC) -c binomial.cpp

clean:
	rm *o
