#include "menu.h"

int menu()
{
    int option;
    float operandA, operandB;
    float resultAdd,resultSubs, resultMultiply, resultDivide, resutlFactA, resultFactB;

    printf("\n1. Ingresar 1er operando: \n2. Ingresar 2do operando: \n3. Calcular todas las operaciones.");
    printf("\na) Calcular la suma.\nb) Calcular la resta.\nc) Calcular la division. \nd) Calcular la multiplicacion.\ne) Calcular el factorial.");
    printf("\n4. Informar resultados: ");
    printf("\n5. Salir");

    option = getOption(&operandA,&operandB);
    return 0;
}

int getOption (float *auxOpA,float *auxOpB)
{
    int option;
    float auxOperandA, auxOperandB;

    switch(option)
    {
    case 1:
        //operandA = getNumber();
        printf("operandA");
        break;
    case 2:
        //operandB = getnumber();
        printf("operandB");
        break;
    case 3:
        printf("calcular");
        //getResult(resultAdd,resultSubs, resultMultiply, resultDivide, resutlFactA, resultFactB);
        break;
    case 4:
        printf("\na) El resultado de A+B es: ");
        printf("\nb) El resultado de A-B es: ");
        printf("\nc) El resultado de A/B es: "); //“No es posible dividir por cero”
        printf("\nd) El resultado de A*B es: ");
        printf("\ne) El factorial de A es: y El factorial de B es:");
        break;
    case 5:
        auxOperandA=0,auxOperandB=0;
        break;

        default:
        printf("Opción inválida.");
        return 0;
    }

}
