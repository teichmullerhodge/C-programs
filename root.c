//implementation of square root from "scratch"
#define epsilon 0.0000000000000000001 //almost zero number
#include <stdio.h>
#include <stdlib.h>

typedef long double REAL;

REAL root (REAL num);
REAL expn (REAL num);
REAL nlog (REAL num);
REAL fact (REAL num);
REAL pown (REAL num, int expoent);

void Usage(void){ 

    puts("Usage: <number>");
    exit(0);

}

int main(int argc, char *argv[] ){

        if(argc!=2) Usage();
        printf("%Lf\n", root(atof(argv[1])));
        return 0;



}

REAL pown(REAL num, int expoent){ //creation of the power function

    if(expoent == 0) return 1;

    REAL value = num;

    for(int k = 1; k < expoent; k++){

            value *= num;
            
    }
            return value;
}


REAL fact(REAL num){ //factorial function

        REAL value = num;
        if(num == 1 || num == 0){ return 1;} 
        return value * (fact(value-1));

}

REAL expn(REAL num){ //exponential function


            REAL divisor = 0;
            REAL value = 0;
            while(divisor < 21){
            value += (pown(num, divisor)/fact(divisor));
            divisor++;
            }
            return value;
}

REAL nlog(REAL num){ //natural log function

        double sum = 0;
        double xmlxpl = (num-1) / (num+1);
        double denom = 1.0;
        double frac = xmlxpl;
        double term = frac / denom;

        while( term > epsilon ){

        sum += term;
        denom += 2.0;
        frac = frac * xmlxpl * xmlxpl;
        term = frac / denom;

        }

        return 2.0 * sum;

}

REAL root(REAL num){

    return expn(nlog(num)/2);
}