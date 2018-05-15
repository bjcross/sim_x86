#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <iostream>
#include <mutex>
#include <algorithm>


struct instructions{
	int opcode;
	int destination;
	int source1;
	int source2;
	int imm;
	int writereg;
};




//struct instructions im[1000];
char im[1000][100];
int registers[14];

//struct 

/*
void fetch();
void identify();
void execute();
void memory();
void writeback();
*/
