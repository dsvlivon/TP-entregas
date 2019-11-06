#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
/*******************************************************************
*Programa:TP1
*Objetivo: Hacer una calculadora
*Version:2.3 del 06enerode2016
*Autor:Daniel S.Vizgarra Livón
*Curso:1°E T.N.
********************************************************************/
int main()
{
    float operandA,operandB;
//creación de variables.

    printf("1) Ingrese el 1er operando: \n");
    printf("2) Ingrese el 2do operando: \n");
    printf("3) Calcular todas las operaciones \n");
    printf("4) Informe de los resultados: \n");
    printf("5) Salir. \n\n");
//print de menu principal
    functions(&operandA,&operandB);
//llamo a funcion principal
    printf("Operando A: %.2f\n",operandA);
    printf("Operando B: %.2f\n",operandB);
//muestra de valores actuales
    return 0;
}


