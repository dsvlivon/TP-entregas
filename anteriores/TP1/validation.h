#ifndef VALIDATION_H_INCLUDED
#define VALIDATION_H_INCLUDED
/*******************************************************************
*Programa:TP1
*Objetivo: Hacer una calculadora
*Version:2.4 del 06 enero de 2016
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
/**
*\brief Solicita y valida un número al usuario
*\param puntero a fail. chequea condicion de error.
*\return El número (operando) validado.
*/
float getFloat(float *pFloat, int pLimit, char* askMsg, char* failMsg);

#endif // VALIDATION_H_INCLUDED
