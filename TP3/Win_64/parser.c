/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
////////////////////////////////////////////////////////////////////////////////// PARSER CSV
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    int auxReturn = -1;
    int r= 0;
    char var1[50],var3[50],var2[50],var4[50];
    Employee* pEmployee;

    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
            pEmployee = employee_newParametros(var1,var2,var3,var4);
            if(pEmployee!=NULL)
            {
                ll_add(pArrayListEmployee,pEmployee);
                auxReturn=0;
            }
            else
            {
                auxReturn=-1;
                break;
            }
        }
        else
        {
            auxReturn=-1;
            break;
        }
    }while(!feof(pFile));
    fclose(pFile);
    printf("\n////////////////////////\n");
    if(auxReturn==0)
        printf("CARGA DE DATOS EXITOSA.");
    else
    {
        printf("CARGA DE DATOS FALLIDA.");
    }
    printf("\n////////////////////////\n");
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// PARSER BIN
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    int auxReturn=-1;
    Employee* pEmployee;
    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        do
        {
            pEmployee = employee_new();
            fread(pEmployee,sizeof(Employee),1,pFile);

            if(pEmployee!=NULL)
            {
             ll_add(pArrayListEmployee,pEmployee);
             auxReturn=0;
            }
            else
            {
            auxReturn=-1;
            break;
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
    printf("\n////////////////////////\n");
    if(auxReturn==0)
        printf("CARGA DE DATOS EXITOSA.");
    else
    {
        printf("CARGA DE DATOS FALLIDA.");
    }
    printf("\n////////////////////////\n");
    return auxReturn;
}
