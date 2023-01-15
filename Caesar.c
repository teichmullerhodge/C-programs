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
//--------------------//

void Usage(void){

	puts("Usage: <mode> <message> <integer between 0-26>");
        puts("modes: -e for encrypt\n       -d for decrypt\n       -b for bruteforce");
	exit(0);

	}


int main(int argc, char* argv[]){


	if(argc!=4 || atoi(argv[2]) > 26) Usage();

        len = strlen(argv[1]);

	if(strcmp(argv[3], "-e") == 0){ ENCRYPT(argv[1], len, atoi(argv[2])); puts(""); exit(0); }
	if(strcmp(argv[3], "-d") == 0){ DECRYPT(argv[1], len, atoi(argv[2])); puts(""); exit(0); }
        if(strcmp(argv[3], "-b") == 0){
                                    int initial_value = atoi(argv[2]);
                                    while(initial_value <= 26){
                                    DECRYPT(argv[1], len, initial_value);
                                    puts("");
                                    initial_value++;                                    
                                            }
                                    exit(0);
                    }

        Usage();
	return 0;
}

int ENCRYPT(char *message, size_t msglen, int cyphervalue){

    for(int i = 0; i < msglen; i++){
    if(cyphervalue == 26 || 0){ printf("%s\n", message); exit(0); }
    
    ENCRYPT_CHAR:

    CharValue = message[i]; 
    CharValue += cyphervalue;

    if(CharValue > 122){  
    CharValue -= 26;
    printf("%c", CharValue);
    if(i < msglen){
                    i++;
                    goto ENCRYPT_CHAR;
                    }
    else{
             return 1;
    
                }
                        }
    if(CharValue > 90 && message[i] < 97){ 
    CharValue -= 26;
    printf("%c", CharValue);
    if(i < msglen){
                    i++;
                    goto ENCRYPT_CHAR;
                    }
    else{
             return 1;
    
                }
    }
    
    printf("%c", CharValue);
    
    } puts("");
      exit(0);
            
            }

int DECRYPT(char *message, size_t msglen, int cyphervalue){


    for(int i = 0; i < msglen; i++){
    if(cyphervalue == 26 || 0){ printf("%s\n", message); exit(0); }
    
    DECRYPT_CHAR:

    CharValue = message[i]; 
    CharValue -= cyphervalue;
 
    if(CharValue < 65){  
        CharValue += 26;
        printf("%c", CharValue);
        if(i < msglen){
                    i++;
                    goto DECRYPT_CHAR;
                                        }
        else { 
                return 1;
                       }
                            }
    if(CharValue < 97 && message[i] > 90){ 
        CharValue += 26;
        printf("%c", CharValue);
        if(i < msglen){
                    i++;
                    goto DECRYPT_CHAR;
                                        }
       else { 
                 return 1;
                       }
                            }
    
    printf("%c", CharValue);
    }   

            }
