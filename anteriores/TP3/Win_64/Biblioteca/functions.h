#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
/*******************************************************************
*Programa:TP1
*Objetivo: Hacer una calculadora
*Version:2.4 del 06 enero de 2016
*Autor:Daniel S.Vizgarra Livon
*Curso:1�E T.N.
********************************************************************/
/**

*\brief Realiza una funci�n matem�tica: sumar
*\param float a valor de OperandA
*\param float b valor de OperandB
*\return El valor de operaci�n
*/
float getAdd(float a, float b);

/**
*\brief Realiza una funci�n matem�tica: restar.
*\param float a valor de OperandA
*\param float b valor de OperandB
*\return El valor de operaci�n
*/
float getSubstract(float a, float b);

/**
*\brief Realiza una funci�n matem�tica: multiplicar.
*\param float a valor de OperandA
*\param float b valor de OperandB
*\param float b valor de OperandB
*\return El valor de operaci�n
*/
float getMultiply(float a, float b);

/**
*\brief Realiza una funci�n matem�tica: dividir.
*\param float a valor de OperandA
*\param float b valor de OperandB
*\param puntero a fail.
*\return El valor de operaci�n
*/
float getDivide(float a, float b);

/**
*\brief Realiza una funci�n matem�tica: factorial.
*\param float x valor de OperandA/B
*\return El valor de operaci�n
*/
float getFactorial (float x);

#endif // FUNCTIONS_H_INCLUDED
