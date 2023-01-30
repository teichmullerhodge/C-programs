#define ANSI_WHITE     "\x1B[37m"
#define ANSI_RED       "\x1B[31m"
#define ANSI_GREEN     "\x1B[32m"
#define ANSI_YELLOW    "\x1B[33m"
#define ANSI_BLUE      "\x1B[34m"
#define ANSI_CYAN      "\x1B[36m"
#define ANSI_MAGENTA   "\x1B[35m"
#define ANSI_NORMAL    "\x1b[0m"
#define ANSI_CLEAR     "\e[1;1H\e[2J"
#define SCREEN_SIZE 6252

char BLUE [] = "BLUE";    char CYAN  [] = "CYAN";   char GREEN  [] =  "GREEN";
char RED  [] = "RED";     char YELLOW[] = "YELLOW"; char MAGENTA[] = "MAGENTA";
char WHITE[] = "WHITE";   char NORMAL[] = "NORMAL"; char CLEAR  [] = "CLEAR";
 
int DISPLAY = SCREEN_SIZE; int LINEJMP =  169;  int points[SCREEN_SIZE] = {0}; 

int square[18] = {
                    001, 002, 003, 004, 005, 006, 007, 170, 176, 
                    339, 345, 508, 509, 510, 511, 512, 513, 514
                                                                 };

void USAGE(void){ printf(ANSI_NORMAL); puts("Usage: <x> <y> pos: COLOR"); exit(0); };


void ChangeColor(char *color){

    if(strcmp(color,"RED")     == 0)    printf(ANSI_RED);
    if(strcmp(color,"WHITE")   == 0)    printf(ANSI_WHITE);
    if(strcmp(color,"GREEN")   == 0)    printf(ANSI_GREEN);
    if(strcmp(color,"YELLOW")  == 0)    printf(ANSI_YELLOW);
    if(strcmp(color,"BLUE")    == 0)    printf(ANSI_BLUE);
    if(strcmp(color,"CYAN")    == 0)    printf(ANSI_CYAN);
    if(strcmp(color,"MAGENTA") == 0)    printf(ANSI_MAGENTA);
    if(strcmp(color,"NORMAL")  == 0)    printf(ANSI_NORMAL);


} void CLEARSC(void){ printf(ANSI_CLEAR); }


void INIT_PIXEL(void){   for(int k = 0; k < DISPLAY; k++)    points[k] = 0;  } //inititalize pixels to '0' 

bool INIT_POINTS(int usr[], int array_size){ //change state of pixels

    for(int k = 0; k < array_size; k++){

    if (usr[k] > SCREEN_SIZE) return false;    
	else points[usr[k]] = usr[k];
    
	}
        return true;
}


void DISPLAY_(int x[], char *color){

    ChangeColor(color);
    
    for(int k = 0; k <= DISPLAY; k++){

        if(x[k]!= 0) printf("█");
        else printf(" ");

    }

}


void dSquare(int pos){


	size_t array_len = sizeof(square)/sizeof(square[0]);

    for(int i = 0; i < pos; i++){
    for(int k = 0; k < array_len; k++){
    
            square[k] += 1;   
     }  
                                }

	bool result = INIT_POINTS(square, array_len);
	if(result == false) USAGE();    

}

