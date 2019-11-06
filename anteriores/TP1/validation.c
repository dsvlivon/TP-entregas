#include <stdio.h>
#include <stdlib.h>
#include "validation.h"
/*******************************************************************
*Programa:TP1
*Objetivo: Hacer una calculadora
*Version:2.4 del 06 enero de 2016
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
float getFloat(float *pFloat, int pLimit, char* askMsg, char* failMsg)
{
    float auxFloat=*pFloat;
    int validation, i,fail=-1;

    printf("%s",askMsg);
    fflush(stdin); //__fpurge cambiar para Linux
    validation = scanf("%f",&auxFloat);
    for(i=1; i<pLimit;i++)
    {
       fflush(stdin); //__fpurge para Linux
        if(validation==1)
        {
            fail=0;
            i=pLimit;
            break;
        }
        else
        {
            printf("(%d)%s%s", i, failMsg, askMsg);
            fail=-2;
            validation = scanf("%f",&auxFloat);
        }
    }
    *pFloat=auxFloat;
    return fail;
}
