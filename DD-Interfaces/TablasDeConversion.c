#include "Conversion.h"

#include <stdio.h>
#include <assert.h>

const float lower = 0;
const float upper = 300;
const float step = 10;

void tablaConversion (void){

    float fahr;
    printf("Fahrenheit\tCelsius\n");
    for (fahr = lower; fahr <= upper; fahr = fahr + step)
    {
        printf ("%3.1f\t %12.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
    return;
}

void celsius (float cels){
    printf("\n%3.1f F, en Celsius es, %3.1f\n",cels,((9.0/5.0)*cels)+32 );
    return;
}

void fahrenheit(float fahr){
    printf("\n%3.1f C, en Fahrenheir es, %3.1f\n",fahr,(5.0/9.0)*(fahr-32) );
    return;
}