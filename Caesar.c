//Simple Caesar Cypher
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Global Variables
int CharValue, Loop = 0;
size_t len;
//Functions Declarations
int DECRYPT(char *message, size_t msglen, int cyphervalue);
int ENCRYPT(char *message, size_t msglen, int cyphervalue);

char LowerCase(char Letters){

        Loop = CharValue - 122;
        Loop += 96;
        printf("%c", Loop);
        CharValue = '\0';

        }

char UpperCase(char Letters){

    Loop = CharValue - 90;
    Loop += 64;
    printf("%c", Loop);
    CharValue = '\0';
}


void Usage(void){

	puts("Usage: <mode> <message> <integer between 0-26>");
    puts("modes: -e for encrypt\n       -d for decrypt");
	exit(0);
	}


int main(int argc, char* argv[]){


	if(argc!=4 || atoi(argv[2]) > 26) Usage();
    len = strlen(argv[1]);
	if(strcmp(argv[3], "-e") == 0) ENCRYPT(argv[1], len, atoi(argv[2]));
	if(strcmp(argv[3], "-d") == 0) DECRYPT(argv[1], len, atoi(argv[2]));
    Usage();
	return 0;
}

int ENCRYPT(char *message, size_t msglen, int cyphervalue){

    for(int i = 0; i < msglen; i++){
    CharValue = message[i];
    CharValue += cyphervalue;
    if(CharValue > 122) LowerCase(CharValue);
    if(CharValue > 90 && CharValue - cyphervalue < 97) UpperCase(CharValue);
    printf("%c", CharValue);
}
    puts("");
    exit(0);

    }

int DECRYPT(char *message, size_t msglen, int cyphervalue){


    for(int i = 0; i < msglen; i++){
    CharValue = message[i];
    CharValue -= cyphervalue;
    if(CharValue > 122) LowerCase(CharValue);
    if(CharValue > 90 && CharValue - cyphervalue < 97) UpperCase(CharValue);
    printf("%c", CharValue);
}
    puts("");
    exit(0);

    }





