/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validations.h"
#define FAIL_DATA "\n\nNO HAY DATOS HABILITADOS. \n"


int menu()
{
    int auxReturn = 1;
    int option = 0;
    char aux[50];
    int flag=0;
    ///////////////////////////////
    LinkedList* pArrayListEmployee = ll_newLinkedList();
    ///////////////////////////////
    do{
    	system ("cls");
        printf("        BIENVENIDOS A  U.T.N. F.R.A. \n\n");
        printf("\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
               "\n2) Cargar los datos de los empleados desde el archivo data.bin (modo binario)."
               "\n3) Alta de empleado."
               "\n4) Modificar datos de empleado."
               "\n5) Baja de empleado."
               "\n6) Listar empleados."
               "\n7) Ordenar empleados."
               "\n8) Guardar los datos de los empleados en el archivo data.csv (modo texto)."
               "\n9) Guardar los datos de los empleados en el archivo data.bin (modo binario)."
               "\n10) SALIR.");
        ///////////////////////////////////////////////
        auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",1,10,2,1);
        if(auxReturn == 0)
        {
            option = atoi(aux);
        }
        fflush(stdin); //para windows
        //__fpurge(stdin); //para Linux
        switch(option)
        {
            case 1://printf("En proceso... ");
                  if(flag==1)
                {
                    printf("\n//////////////////////////////////////////////\n");
                    printf("////////////////    ALERTA     ///////////////");
                    printf("\n//////////////////////////////////////////////\n");
                    printf("\n///////YA SE CARGO UNA BASE DE DATOS//////////\n");
                }
                else
                    controller_loadFromText("data.csv", pArrayListEmployee);
                flag = 1;
            break;
            case 2://printf("En proceso... ");
                if(flag==1)
                {
                    printf("\n//////////////////////////////////////////////\n");
                    printf("////////////////    ALERTA     ///////////////");
                    printf("\n//////////////////////////////////////////////\n");
                    printf("\n///////YA SE CARGO UNA BASE DE DATOS//////////\n");
                    if(getInput(aux, "\n\nDesea borrar la base de datos actual? Y/N: ","\nLa Baja no se realizo.",0,2,1,5)==0)
                    {
                        controller_deleteLinkedList(pArrayListEmployee);
                        if(getInput(aux, "\n\nDesea carga una nueva base de datos? Y/N: ","\nLa Carga no se realizo.",0,2,1,5)==0)
                        {
                            controller_loadFromBinary("data2.bin",pArrayListEmployee);
                        }
                    }
                }
                else
                    controller_loadFromBinary("data2.bin",pArrayListEmployee);
                flag = 1;
            break;
            case 3: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_addEmployee(pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 4: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_editEmployee(pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 5: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_removeEmployee(pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 6: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_listEmployee(pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 7: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_sortEmployee(pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 8: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_saveAsText("data2.csv", pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 9: //printf("En proceso... ");
                if(flag==1)
                {
                    controller_saveAsBinary("data2.bin", pArrayListEmployee);
                }
                else
                    printf(FAIL_DATA);
            break;
            case 10:
                printf("\n///////////////////////\n");
                printf("SALIENDO... ");
                printf("\n///////////////////////\n");
            break;
            default: printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while (option !=10);
    return auxReturn;
}
