#include <stdio.h>			//standard also allows fopen
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>			//allow streaming
#include <mutex>

#include "main.h"
#include "pipeline/if.cpp"
#include "pipeline/id.cpp"
#include "pipeline/ex.cpp"
#include "pipeline/mem.cpp"
#include "pipeline/wb.cpp"


using namespace std;
int main(int argc, char *argv[]){
   FILE* input = NULL; 		//pointer to the file that we will be using to input x86 code
   FILE* output = NULL;		//pointer to the file we will write to with memory information

	if (argc == 3){ 			//check for the correct number of arguments (2) input/output files
		input = fopen(argv[1], "r");
		output = fopen(argv[2], "w");		
	}
	else {
		cout << "Please enter (INPUT OUTPUT) and nothing more" << endl;
		exit(0);
	}

	if (input == NULL || output == NULL){	//check that the inpute files exist
		cout << "Atleast one of the input files doesn't exist" << endl;
		exit(0);
	}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~set initial conditions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	for (int i=0; i<sizeof(registers); i++){	//set all the registers to be empty for start of program
		registers[i]=0;
	}
	int instructionnum = 0;






//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~fix input for common errors~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	char fixedcommand[100];

	while(fgets(fixedcommand, 100, input)){	//puts the line from file to fixedcommand one by one
		for(int i=0; i<sizeof(fixedcommand); i++){
			fixedcommand[i] = tolower(fixedcommand[i]);
		}
		

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~convert reg names to reg numbers~~~~~~~~~~~~~~~~~~~~~~~~
		for(int i=0; i<sizeof(fixedcommand); i++){
			if(fixedcommand[i] == '%'){
				i++;
				char reg[3] = {fixedcommand[i], fixedcommand[i+1], '\0'};
				if (!strcmp(reg, "ax")){
					fixedcommand[i] = '0';
					i++;
					fixedcommand[i] = ' ';
				}
				else if (!strcmp(reg, "bx")){
					fixedcommand[i] = '1';
					i++;
					fixedcommand[i] = ' ';
				}
				else if (reg == "cx"){
					fixedcommand[i] = '2';
					i++;
					fixedcommand[i] = ' ';
				}
				else if (reg == "dx"){
					fixedcommand[i] = '3';
					i++;
					fixedcommand[i] = ' ';
				}
				else if (reg == "si"){
					fixedcommand[i] = '4';
					i++;
					fixedcommand[i] = ' ';
				}
				else if (reg == "di"){
					fixedcommand[i] = '5';
					i++;
					fixedcommand[i] = ' ';
				}
				else if (reg == "bp"){
					fixedcommand[i] = '6';
					i++;
					fixedcommand[i] = ' ';
				}
				else if (reg == "sp"){
					fixedcommand[i] = '7';
					i++;
					fixedcommand[i] = ' ';
				}
				i++;
			}
		}	
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~store this code to instruction memory~~~~~~~~~~~~~~~~~~
		strcpy(im[instructionnum], fixedcommand);
		cout << "HERE: " << im[instructionnum];
		instructionnum++;
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
