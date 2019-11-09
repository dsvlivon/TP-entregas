/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1�E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h  >
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Employee.h"
#include "validations.h"
#define FAIL_INIT "\n\nNO HAY DATOS HABILITADOS. \n"
#define FAIL_ADD "\n\nNO SE PUEDE CREAR EL EMPLEADO CON DATOS ERRONES. \n"

////////////////////////////////////////////////////////////////////////////////// LOAD CSV
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    int auxReturn =0;
    FILE* pFileTxt=NULL;
    pFileTxt = fopen(path, "r");

    if(pFileTxt != NULL)
    {
        parser_EmployeeFromText(pFileTxt , pArrayListEmployee);
    }
    else
    {
        auxReturn= -1;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// LOAD BIN
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    int auxReturn=-1;
    FILE* pFileBin= NULL;

    if(path!= NULL && pArrayListEmployee!=NULL)
    {
        pFileBin = fopen(path, "rb");
        auxReturn = parser_EmployeeFromBinary(pFileBin, pArrayListEmployee);
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// ADD
int controller_addEmployee(LinkedList* pArrayListEmployee){
        int auxReturn=-1;
        Employee* pxEmployee=NULL;
        //char aux[50];
        //int var1="-1";
        char var2[50],var3[50],var4[50];

        if(pArrayListEmployee!=NULL)
        {
            //printf("\nMENU ORDENAMIENTO: \n1) Ordenar por Nombre. \n2) Ordenar por sueldo. \n3) Ordenar por Horas trabajadas.");
            printf("\nALTA DE EMPLEADO.");
            printf("\n/////////////////////////////////////\n");
            if(getInput(var2, "\nIngrese el nombre: ","\nIngreso invalido!",0,50,2,3) == 0)
            {
                //strcpy(var2, aux);
                //var1 = atoi(aux);
                auxReturn = 0;
            }
            else
                printf(FAIL_ADD);
            if(auxReturn==0)
            {
               auxReturn = getInput(var3, "\nIngrese las Horas Trabajadas: ","\nIngreso invalido!",0,1100,2,1);
            }
             else
                printf(FAIL_ADD);
            if(auxReturn==0)
            {
                auxReturn= getInput(var4, "\nIngrese el sueldo: ","\nIngreso invalido!",0,999999,2,1);
                //strcpy(var4, aux);
            }
             else
                printf(FAIL_ADD);
            printf("\n/////////////////////////////////////\n");
            if(auxReturn==0)
            {
                //printf("Nombre: %s\n", var2);
                //printf("Horas: %s\n", var3);
                //jonprintf("Sueldo: %s\n", var4);
                pxEmployee = employee_newParametros("-1",var2,var3,var4);
                if(pxEmployee!=NULL)
                {
                   ll_add(pArrayListEmployee, pxEmployee);
                }
            }
            else
                printf(FAIL_ADD);
        }
   return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// EDIT
int controller_editEmployee(LinkedList* pArrayListEmployee){
    int auxReturn=-1;
    Employee* pxEmployee=NULL;
    char aux[50];
    char auxNombre[50];
    int auxSueldo,auxHoras;
    int pIndex,auxId;
    int flag=0;
    int option=0;

    if(pArrayListEmployee!=NULL)
    {
        printf("\nMENU MODIFICACION DE EMPLEADO.");
        printf("\n/////////////////////////////////////\n");
        if(getInput(aux, "\n\nIngrese el ID: ","\nIngreso invalido!",0,9999,2,1) == 0)
        {
            auxId=atoi(aux);
            pIndex = controller_findEmployeeById(pArrayListEmployee,auxId);
            if(pIndex>=0)
            {
                pxEmployee = (Employee*)ll_get(pArrayListEmployee,pIndex);

                if(pxEmployee != NULL)
                {
                    flag = 1;
                }
            }
            else
            {
                printf("\nID no disponible.\n");
            }
        }
        if(flag==1)
        {
            employee_getNombre(pxEmployee,auxNombre);
            employee_getHorasTrabajadas(pxEmployee,&auxHoras);
            employee_getSueldo(pxEmployee,&auxSueldo);
            printf("\n1) Modificar Nombre: %s\n2) Modificar Sueldo: %d\n3) Modificar Horas Trabajadas: %d", auxNombre, auxSueldo, auxHoras);
            auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",1,3,2,1);
            if(auxReturn == 0)
            {
                option = atoi(aux);
                if(option==1)
                {
                    if(getInput(aux, "\n\nIngrese el nombre: ","\nIngreso invalido!",0,50,2,3) == 0)
                    {
                        strcpy(auxNombre, aux);
                        employee_setNombre(pxEmployee, auxNombre);
                    }
                }
                if(option==2)
                {
                    if(getInput(aux, "\n\nIngrese el sueldo: ","\nIngreso invalido!",0,999999,2,1) == 0)
                    {
                        auxSueldo = atoi(aux);
                        employee_setSueldo(pxEmployee,auxSueldo);
                    }
                }
                 if(option==3)
                {
                    if(getInput(aux, "\n\nIngrese las Horas Trabajadas: ","\nIngreso invalido!",0,1100,2,1) == 0)
                    {
                        auxHoras  = atoi(aux);
                        employee_setHorasTrabajadas(pxEmployee, auxHoras);
                    }
                }
            }
            else
                printf("No se pudo modificar el campo.\n");
            printf("\n/////////////////////////////////////\n");
        }
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// REMOVE
int controller_removeEmployee(LinkedList* pArrayListEmployee){
    int auxReturn=-1;
    int pIndex,auxId;
    char aux[50];
    char auxNombre[50];
    Employee* pxEmployee=NULL;

    if(pArrayListEmployee!=NULL)
    {
        printf("\nMENU BAJA DE EMPLEADO: \n");
        if(getInput(aux, "\n\nIngrese el ID: ","\nIngreso invalido!",0,9999,2,1) == 0)
        {
            auxId=atoi(aux);
            pIndex = controller_findEmployeeById(pArrayListEmployee,auxId);
            if(pIndex>=0)
            {
                pxEmployee=(Employee*)ll_get(pArrayListEmployee,pIndex);
                employee_getNombre(pxEmployee,auxNombre);
                printf("\n////////////////////////////////////\n");
                printf("\nEmpleado ID Nro.: %d", auxId);
                printf("\nEmpleado Nombre: %s\n", auxNombre);
                //printf("\nEmpleado: %s\n", *(pArrayListEmployee+pIndex);
                if(getInput(aux, "\nConfirma la baja? Y/N: ","\nLa Baja no se realizo.",0,2,1,5)==0)
                {
                    printf("Baja en curso ...\n");
                    if(ll_remove(pArrayListEmployee, pIndex)==0)
                    {
                        auxReturn=0;
                        printf("Se realizo la baja con exito.");
                    }
                }
                else
                {
                    printf("No se pudo realizar la baja.");
                }
                printf("\n////////////////////////////////////\n");
            }
        }
    }

    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// DELETE LL
int controller_deleteLinkedList(LinkedList* pArrayListEmployee){
    int auxReturn=-1;
    //Employee* pxEmployee=NULL;

    if(pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        printf("\n////////SE ELIMINO LA BASE DE DATOS///////////\n");
        auxReturn=0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// LIST
int controller_listEmployee(LinkedList* pArrayListEmployee){
    int auxReturn=-1;
    int len,i;
    int auxHoras, auxId, auxSueldo;
    char auxNombre[50];
    Employee* auxEmployee=NULL;

    if(pArrayListEmployee != NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getNombre(auxEmployee,auxNombre);
            employee_getId(auxEmployee,&auxId);
            employee_getSueldo(auxEmployee,&auxSueldo);
            employee_getHorasTrabajadas(auxEmployee,&auxHoras);

            printf("Id: %d      Nombre: %s      Horas:%d        Sueldo: %d\n",auxId,auxNombre,auxHoras,auxSueldo);

        }
        auxReturn = 0;
    }
    else
        printf(FAIL_INIT);
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SORT
int controller_sortEmployee(LinkedList* pArrayListEmployee){

    int auxReturn = -1;
    int optionB = 0;
    char aux[50];
    //Employee* p1, p2;

    if(pArrayListEmployee!= NULL)
    {
        printf("\nMENU ORDENAMIENTO: \n1) Ordenar por Nombre. \n2) Ordenar por sueldo. \n3) Ordenar por Horas trabajadas.");
        auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",1,3,2,1);
        if(auxReturn == 0)
        {
            optionB = atoi(aux);
            printf("\n/////////////////////////////////////\n");
            if(optionB==1)
            {
                ll_sort(pArrayListEmployee, employee_sortByName,1);
                printf("Ordenamiento por NOMBRE: COMPLETADO.");
            }
            if(optionB==2)
            {
                ll_sort(pArrayListEmployee, employee_sortBySalary,1);
                printf("Ordenamiento por SUELDO: COMPLETADO.");
            }
             if(optionB==3)
            {
                ll_sort(pArrayListEmployee, employee_sortByWorkedHours,1);
                printf("Ordenamiento por HORAS TRABAJADAS: COMPLETADO.");
            }
        }
        else
            printf("NO SE PUDO REALIZAR EL ORDENAMIENTO.");
        printf("\n/////////////////////////////////////\n");
    }
    else
        printf(FAIL_INIT);
  return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SAVE CSV
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    int auxReturn =0;
    int i,xLen=0;
    int auxHoras, auxId, auxSueldo;
    char auxNombre[50];
    FILE* pFileTxt=NULL;
    pFileTxt = fopen(path, "w");
    Employee* pxEmployee=NULL;

    if(pArrayListEmployee!=NULL)
    {
        if(pFileTxt != NULL)
        {
            xLen = ll_len(pArrayListEmployee);
            for(i=0; i<xLen;i++)
            {
                pxEmployee = ll_get(pArrayListEmployee,i);
                //fwrite(pe, sizeof(Employee),1,pFileTxt);
                employee_getNombre(pxEmployee,auxNombre);
                employee_getId(pxEmployee,&auxId);
                employee_getSueldo(pxEmployee,&auxSueldo);
                employee_getHorasTrabajadas(pxEmployee,&auxHoras);
                fprintf(pFileTxt,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
            }
        }
        else
            auxReturn = -1;
        fclose(pFileTxt);
        printf("\n/////////////////////////////////////\n");
        if(auxReturn==0)
        {
            printf("EL ARCHIVO SE GUARDO CON EXITO.");
            printf("\nSe guardaron : %d empleados.", xLen);
        }
        else
        {
            printf("EL ARCHIVO NO SE PUDO GUARDAR.");
        }
        printf("\n/////////////////////////////////////\n");
    }
    else
        printf(FAIL_INIT);
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SAVE BIN
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
    int auxReturn =-1;
    int i,xLen=0;
    /*int auxHoras, auxId, auxSueldo;
    char auxNombre[50];*/
    FILE* pFileBin=NULL;
    Employee* pxEmployee=NULL;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        pFileBin = fopen(path, "wb");
        xLen = ll_len(pArrayListEmployee);
        //printf("OK 1");
        if(pFileBin != NULL)
        {
            //printf("OK 2");
            for(i=0; i<xLen;i++)
            {
                pxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
                /*employee_getNombre(pxEmployee,auxNombre);
                employee_getId(pxEmployee,&auxId);
                employee_getSueldo(pxEmployee,&auxSueldo);
                employee_getHorasTrabajadas(pxEmployee,&auxHoras);
                //printf("OK 3");
                printf("Id: %d      Nombre: %s      Horas:%d        Sueldo: %d\n",auxId,auxNombre,auxHoras,auxSueldo);*/
                if(pxEmployee!=NULL)
                {
                    fwrite(pxEmployee,sizeof(Employee),1,pFileBin);
                    auxReturn=0;
                }
            }
            fclose(pFileBin);
        }
        else
            auxReturn=-1;
        printf("\n/////////////////////////////////////\n");
        if(auxReturn==0)
        {
            printf("EL ARCHIVO SE GUARDO CON EXITO.");
            //printf("\nSe guardaron : %d empleados.", xLen);
        }
        else
        {
            printf("EL ARCHIVO NO SE PUDO GUARDAR.");
        }
        printf("\n/////////////////////////////////////\n");
    }
    else
        printf(FAIL_INIT);
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// FIND ID
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id){
    int auxReturn = -1;
    int i,auxId,len;
    Employee* pxEmployee=NULL;

    if( pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        auxReturn = -2;
        for(i=0; i<len; i++)
        {
            pxEmployee= (Employee*)ll_get(pArrayListEmployee,i);

            if(pxEmployee != NULL)
            {
                if(employee_getId(pxEmployee,&auxId) == 0)
                {
                    if(auxId == id)
                    {
                        auxReturn = i;
                        break;
                    }
                }
            }
        }
    }
    return auxReturn;
}
