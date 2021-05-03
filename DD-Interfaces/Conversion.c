#include "Conversion.h"
#include <stdio.h>

int main (){
    int opcion;
    float cels, fahr;
    do{
    printf ("\nOpcion 1: Tabla de conversion de Fahrenheit a Celsius\nOpcion 2: Ingresar numero en Fahrenheit a convertir\nOpcion 3: Ingresar numero en Celsius a convertir\nOpcion 0: Abandonar\n\tIngrese su Opcion: ");
    scanf ("%d",&opcion);
    switch (opcion)
    {
    case 1:{
        tablaConversion();
        break;
        }
    case 2:{
        printf("Ingrese una temperatura a convertir: ");
        scanf("%f",&cels);
        celsius(cels);
        break;
    }
    case 3:{
        printf("Ingrese una temperatura a convertir: ");
        scanf("%f",&fahr);
        fahrenheit(fahr);
        break;
    }
    default:
        printf("\n\nIngrese una opcion correcta\n\n");
        break;
    }
}while (opcion !=0);

return (0);
}