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
    int employeeCount=0;
    char var1[50],var3[50],var2[50],var4[50];
    Employee* pxEmployee =NULL;

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
            pxEmployee = employee_newParametros(var1,var2,var3,var4);
            if(pxEmployee!=NULL)
            {
                ll_add(pArrayListEmployee,pxEmployee);
                employeeCount++;
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
    {
        printf("CARGA DE DATOS EXITOSA.");
        //printf("\nSe cargaron %d empleados.", employeeCount);
    }

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
    Employee* pxEmployee=NULL;
    //int auxSize=0;
    int employeeCount=0;
    int auxHoras, auxId, auxSueldo;
    char auxNombre[50];

    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        do
        {
            pxEmployee = employee_new();
            //auxSize = sizeof(Employee);
            //printf("Sixe : %d", auxSize);
            fread(pxEmployee,sizeof(Employee),1,pFile);
            //printf("empleado nº %d: ", con);

            if(employee_getId(pxEmployee,&auxId)==0)
            {
                if(employee_getNombre(pxEmployee,auxNombre)==0)
                {
                    if(employee_getSueldo(pxEmployee,&auxSueldo)==0)
                    {
                        if(employee_getHorasTrabajadas(pxEmployee,&auxHoras)==0)
                        {
                            ll_add(pArrayListEmployee,pxEmployee);
                            employeeCount++;
                            auxReturn=0;
                        }
                    }
                }
            }
            else
            {
                auxReturn=-1;
                //printf("sale x break;");
                break;
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
    printf("\n////////////////////////\n");
    if(auxReturn==0)
    {
        printf("CARGA DE DATOS EXITOSA.");
        //printf("\nSe cargaron %d empleados.", employeeCount);
    }
    else
    {
        printf("CARGA DE DATOS FALLIDA.");
    }
    printf("\n////////////////////////\n");
    return auxReturn;
}
