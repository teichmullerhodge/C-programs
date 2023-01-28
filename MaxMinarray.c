//program to return MIN and MAX value of a given array of numbers
#include <stdio.h>
#include <stdlib.h>
//function declarations
int MAX_ARRAY(int arr[], size_t lenarray);
int MIN_ARRAY(int arr[], size_t lenarray);

void Usage(void){

			puts("Usage: <len array>"); //case argc!=2
				exit(0); //exit program
}


int main(int argc, char *argv[]){

		if(argc!=2) Usage(); 
		size_t lenarray = atoi(argv[1]); //len of array is provided by the user via command line
		int usrArray[lenarray];
		for(int i = 0; i < lenarray; i++){ //usr gives the array values
			scanf("%d", &usrArray[i]);
		}

		int MAX = MAX_ARRAY(usrArray, lenarray);
		int MIN = MIN_ARRAY(usrArray, lenarray);
		printf("Max element of array is: %d\nMin Element of array is %d\n", MAX, MIN);//print the MIN and MAX values of the given array
		return 0;
}


int MAX_ARRAY(int arr[], size_t lenarray){ //function for calculate the MAX element of an array


	for(int k = 0; k < lenarray; k++){

	INITIAL:

     for(int i = 1; i < lenarray; i++){

	  if(arr[k] < arr[i]){
			
				if(k < lenarray){
				k++;

				goto INITIAL;

						}else{

						return arr[i];

							}
		}
	}

		return arr[k];
		
	}
	
				}

int MIN_ARRAY(int arr[], size_t lenarray){ //Same function, with a little difference...

	for(int k = 0; k < lenarray; k++){

	INITIAL:

     for(int i = 1; i < lenarray; i++){

	  if(arr[k] > arr[i]){
			
				if(k < lenarray){
				k++;

				goto INITIAL;

						}else{

						return arr[i];

							}
		}
	}

		return arr[k];

	}


}







//END :)
