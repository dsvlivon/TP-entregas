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
#define length 12

/**
*\brief Declaración de variables:
*\param puntero a OperandA.
*\param puntero a OperandB.
*\return El número (operando) ingresado por el usuario
*/
float functions(float *auxOpA, float *auxOpB)
{//declaracion de la funcion gerenciadora
        float opA = *auxOpA;
        float opB = *auxOpB;
        float add;
        float substract;
        float divide;
        float multiply;
        float factorialA;
        float factorialB;
        int option;
        int fail=0;

        printf("Que desea hacer?");
        scanf("%d",&option);
//pregunta master que asigna valor al menu
        switch(option)
        {
        case 1:
        opA = getNumber("Ingrese un operando: ");
        break;
        case 2:
        opB = getNumber("Ingrese un operando: ");
        break;
        case 3:
        add = getAdd(opA,opB);
        substract = getSubstract(opA,opB);
        multiply = getMultiply(opA,opB);
        divide = getDivide(opA,opB);
        factorialA = getFactorial(opA);
        factorialB = getFactorial(opB);
        break;
        case 4:
        printf("El resultado de A+B es: %.2f",add);
        printf("\nEl resultado de A-B es: %.2f",substract);
        printf("\nEl resultado de A/B es: %.2f",divide);
        printf("\nEl resultado de A*B es: %.2f",multiply);
        printf("\nEl factorial de A es: %.2f",factorialA);
        printf("\nEl factorial de B es: %.2f",factorialB);
        break;
        case 5:
        free(opA);
        free(opB);
        break;
        default:
        printf("Opción inválida.");
        fail=-1;
        }
        *auxOpA=opA;
        *auxOpB=opB;

        return fail;
}//funcionamiento del menu

/**
*\brief Solicita un número al usuario
*\param Mensaje para pedir numero/ Length hace referencia a un define
*\return El número (operando) ingresado por el usuario
*/
float getNumber(char msg[length])
{
        float auxFloat;
        int validation;
        int fail=0;

        printf("%s", mensaje);
        scanf("%f", &auxFloat);

        validation=scanf("%f",&auxFloat);
        if(validation!=0)
        {
            fail=-1;
        }

        return auxFloat;
}
/**
*\brief Realiza una función matemática: sumar
*\param float a valor de OperandA
*\param float b valor de OperandB
*\return El valor de operación
*/
float getAdd(float a, float b)
{
        float add;
        add = a+b;
        return add;
}
/**
*\brief Realiza una función matemática: restar.
*\param float a valor de OperandA
*\param float b valor de OperandB
*\return El valor de operación
*/
float getSubstract(float a, float b)
{
        float substract;
        if(a<0&& b<0 || a>0&&b<0)
        {
                substract = a+b;
        }
        else if
        {
                substract = a-b;
        }
        return substract;
}
/**
*\brief Realiza una función matemática: multiplicar.
*\param float a valor de OperandA
*\param float b valor de OperandB
*\return El valor de operación
*/
float getMultiply(float a, float b)
{
        float multiply;
        add = a*b;
        return multiply;
}
/**
*\brief Realiza una función matemática: dividir.
*\param float a valor de OperandA
*\param float b valor de OperandB
*\return El valor de operación
*/
float getDivide(float a, float b)
{
        float divide;
        if(b==0)
        {
                printf("Error. No es posible dividir por 0.")
        }
        else
        {
                add = a/b;
        }
        return divide;
}
/**
*\brief Realiza una función matemática: factorial.
*\param float x valor de OperandA/B
*\return El valor de operación
*/
int getFactorial (float x)
{
	float factorial = 1;
	int i;
	for(i=1;i<=x;i++)
        {
                factorial = factorial*i;
        }
	return factorial;
}
