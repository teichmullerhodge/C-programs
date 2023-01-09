#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_RAND 4096
#define MAX_LEN 16
typedef long long Password;

//Global Variables//
int ArrayTable[MAX_LEN];
char RandomStr[MAX_LEN];
size_t Len;
//---------------//

void Usage(void){ 

    puts("Usage: <string> MAX 16 CHARACTERS");
	exit(0);
    
    }

void NtoDigits(long Value, size_t ArgvLen){

	ArrayTable[ArgvLen];
	for(int k = 0; k < ArgvLen; k++){
	ArrayTable[k] = Value % 10;
	Value /= 10;

	}
		}

int main(int argc, char *argv[]){


	if(argc != 2 || strlen(argv[1]) > 16){

               Usage();
               
     }
    
    Len = strlen(argv[1]);
	srand(time(NULL));
	int Ascii = 33;
	
    for(int i = 0; i < Len; i++){
    
    	Ascii += random() % 93;
    	RandomStr[i] = Ascii;
	    Ascii = 33;

        }

	Password SumArgv = random() % MAX_RAND;

	for(int j = 0; j < Len; j++){ 
        
        SumArgv += SumArgv + argv[1][j];

        }
  
    NtoDigits(SumArgv, Len);
    printf("Your password is: ");

	for(int k = 0; k < Len; k++){

	printf("%d", ArrayTable[k]);
 	printf("%c", RandomStr[k]);

	}

    puts("");
	return 0;

	}



