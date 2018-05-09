#include <iostream>

int main(int argc, char *argv[]){
   FILE* input = NULL; 		//pointer to the file that we will be using to input x86 code
   FILE* output = NULL;		//pointer to the file we will write to with memory information

	if (argc == 2){ 			//check for the correct number of arguments (2) input/output files
		input = fopen(argv[0], "r");
		output = fopen(argv[1], "w");		
	}
	else {
		cout << "Please enter (INPUT OUTPUT) and nothing more";
		exit(0);
	}

	if (input == NULL || output == NULL){	//check that the inpute files exist
		cout << "Atleast one of the input files doesn't exist";	
		exit(0);
	}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~set initial conditions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*	for (i=0; i<regnum; i++){	//set all the registers to be empty for start of program
		reg[i]=0;
	}
*/





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~fix input for common errors~~~~~~~~~~~~~~~~~~~~~~~~~~~~



	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~convert reg names to reg numbers~~~~~~~~~~~~~~~~~~~~~~~~

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~store this code to instruction memory~~~~~~~~~~~~~~~~~~
}
