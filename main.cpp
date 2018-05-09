#include <stdio.h>			//standard also allows fopen
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <iostream>			//allow streaming
using namespace std;

enum regnum {ax = 0, bx, cx, dx, si, di, bp, sp, 8, 9 , 10, 11, 12, 13, 14, 15};




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
/*	for (i=0; i<regnum; i++){	//set all the registers to be empty for start of program
		reg[i]=0;
	}
*/





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
			
			}
		}	
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~store this code to instruction memory~~~~~~~~~~~~~~~~~~


	}
}
