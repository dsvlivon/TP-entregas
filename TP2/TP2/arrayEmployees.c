/*******************************************************************
*Programa:TP2
*Objetivo: Sistema para administrar nómina de empleados
*Version: 1.0 del 25 de Septiembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "validations.h"
#include "arrayEmployees.h"

#define QTY_EMPLOYEES 2000
#define ID_FAIL "No se puede completar un legajo con datos erroneos.\n\n"

////////////////////////////////////////////////////////////////////////// IE
void initEmployees(Employee arrayEmployee[],int size){
    int i;

    for(i=1000; i<size; i++)
    {
        arrayEmployee[i].isEmpty=-1;//LIBRE=-1 // OCUPADO=0
    }
    for(i=0; i<999; i++)
    {
        arrayEmployee[i].isEmpty=-2;//LIBRE=-1 // OCUPADO=0
    }
}
/////////////////////////////////////////////////////////////////////////  AE
int addEmployee(Employee arrayEmployee[], int size){
    int auxReturn=0;
    int freeSpotFlag,freeSpot;
    ////////////
    char pName[50];
    char pLname[50];
    float pSalary;
    int pSector;
    ////////////
    char aux[50];

    freeSpotFlag = searchForEmpty(arrayEmployee, size ,&freeSpot);
    if(freeSpotFlag == 0)
    {
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
    }
    else if(freeSpotFlag == -1)
    {
        printf("\nAlta Legajo Nro.%d: \n", freeSpot);
        /////////////////////////////////////
        auxReturn = getInput(aux, "Ingrese el/los Nombre/s: ","\nIngreso invalido!",0,50,2,3);
        if(auxReturn == 0)
        {
            strcpy(pName,aux);
            //printf("El nombre validado es: %s\n", pName);
        }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el/los Apellido/s: ","\nIngreso invalido!",0,50,2,3);
            if(auxReturn == 0)
            {
                strcpy(pLname,aux);
                //printf("El apellido validado es: %s\n", pLname);
            }
        }
        else
            {
                auxReturn=-1;
            }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el Sueldo: ","\nIngreso invalido!",0,1999999,2,2);
            if(auxReturn == 0)
            {
                pSalary = atof(aux);
                //printf("El sueldo validado es: $%.2f \n\n", pSalary);
            }
        }
        else
        {
            auxReturn=-1;
        }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el Sector: ","\nIngreso invalido!",1,5,2,1);
            if(auxReturn == 0)
            {
                pSector = atoi(aux);
                //printf("El sector validado es: %d \n\n", pSector);
            }
        }
         else
        {
            auxReturn=-1;
        }
        if(searchForEmpty(arrayEmployee,size,&freeSpot)== 0)
        {
            printf("\n\nEL LEGAJO YA EXISTE!!!\n");
        } //BUSCA REPETIDOS
        if(auxReturn == 0)
        {
            freeSpotFlag=0;
            arrayEmployee[freeSpot].idEmployee=freeSpot;
            strcpy(arrayEmployee[freeSpot].name,pName);
            strcpy(arrayEmployee[freeSpot].lastName,pLname);
            arrayEmployee[freeSpot].salary = pSalary;
            arrayEmployee[freeSpot].sector = pSector;
            arrayEmployee[freeSpot].isEmpty=0;
        }
        //////////////////////////////////////////// testeo
        /*printf("\nAuxReturn: %d\n\n",  auxReturn);
        printf("freeSpotFlag: %d\n",  freeSpotFlag);
        printf("id empleado: %d\n", arrayEmployee[freeSpot].idEmployee);
        printf("freeSpot: %d  isEmpty: %d\n", freeSpot, arrayEmployee[freeSpot].isEmpty);
        printf("freeSpot: %d  isEmpty: %d\n", freeSpot+1, arrayEmployee[freeSpot+1].isEmpty);*/
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SFE
int searchForEmpty(Employee arrayEmployee[], int size, int* position){
    int flag = 0;
    int i;
    if(arrayEmployee != NULL && size>=0 && position!=NULL)
    {
        for(i=1000;i<size;i++)
        {
            if(arrayEmployee[i].isEmpty == -1)
            {
                flag = arrayEmployee[i].isEmpty;
                *position = i;
                break;
            }
        }
    }
    return flag;
}
/////////////////////////////////////////////////////////////////////////  FEID
int findEmployeeById(Employee arrayEmployee[], int size, int *auxId){
    int auxReturn=0;
    int i, value;
    char aux[6];

    if(arrayEmployee!= NULL && size>=0)
    {
        auxReturn = getInput(aux, "\n\nIngrese el ID: ","\nIngreso invalido!",1000,2000,2,1);
        if(auxReturn == 0)
        {
            value= atoi(aux);
            for(i=1000;i<size-1;i++)
            {
                if(arrayEmployee[i].isEmpty==-1)
                {
                    continue;
                }
                if(arrayEmployee[i].idEmployee==value)
                {
                    *auxId = value;
                    break;
                }
            }
            if(auxReturn==0 && *auxId!=value)
            {
                printf("\nId No disponible.");
                auxReturn=-1;
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  FEBID
int modifEmployee(Employee arrayEmployee[], int size){
    int auxReturn=-1;
    int option, value;
    char aux[6];

    if(arrayEmployee!= NULL && size>=0)
    {
        printEmployees(arrayEmployee, QTY_EMPLOYEES);
        auxReturn=findEmployeeById(arrayEmployee, QTY_EMPLOYEES, &value);
        if(auxReturn==0)
        {

            do{
                system ("cls");
                /////////////////////////////////////
                printf("\nMENU MODIFICACIONES: \n\nLegajo Nro.%d: \n", value);
                printf("\n1)Nombre: %s\n2)Apellido: %s\n3)Sueldo: $%.2f\n4)Sector: %d\n5)VOLVER\n", arrayEmployee[value].name, arrayEmployee[value].lastName, arrayEmployee[value].salary, arrayEmployee[value].sector);
                auxReturn = getInput(aux, "\nIngrese una opcion: ","\nIngreso invalido!",1,5,2,1);
                if(auxReturn == 0){
                    option= atoi(aux);
                }
                fflush(stdin); //__fpurge para Linux
                switch(option)
                {
                    case 1:
                    auxReturn = getInput(aux, "Ingrese el/los Nombre/s: ","\nIngreso invalido!",0,50,2,3);
                    if(auxReturn == 0)
                    {
                        strcpy(arrayEmployee[value].name,aux);
                    }
                    break;
                    case 2:
                    auxReturn = getInput(aux, "Ingrese el/los Apellido/s: ","\nIngreso invalido!",0,50,2,3);
                    if(auxReturn == 0)
                    {
                        strcpy(arrayEmployee[value].lastName,aux);
                    }
                    break;
                    case 3:
                    auxReturn = getInput(aux, "Ingrese el Sueldo: ","\nIngreso invalido!",0,1999999,2,2);
                    if(auxReturn == 0)
                    {
                        arrayEmployee[value].salary = atof(aux);
                    }
                    break;
                    case 4:
                    auxReturn = getInput(aux, "Ingrese el Sector: ","\nIngreso invalido!",1,5,2,1);
                    if(auxReturn == 0)
                    {
                        arrayEmployee[value].sector = atoi(aux);
                    }
                    break;
                    case 5:
                    printf("Volviendo... ");
                    break;
                    default:
                    printf("Opcion invalida\n");
                    break;
                }
                system("pause");
            }while (option !=5);
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  RE
int removeEmployee(Employee arrayEmployee[], int size){
    int auxReturn=0;
    int value;
    char aux[10];
    char empty[50];

    if(arrayEmployee!= NULL && size>=0)
    {
        printEmployees(arrayEmployee, QTY_EMPLOYEES);
        auxReturn=findEmployeeById(arrayEmployee, QTY_EMPLOYEES, &value);
        if(auxReturn==0)
        {
            printf("\nBaja Legajo Nro.%d: \n", value);
            printf("\nNombre: %s\nApellido: %s\nSueldo: $%.2f\nSector: %d", arrayEmployee[value].name, arrayEmployee[value].lastName, arrayEmployee[value].salary, arrayEmployee[value].sector);
            ///////////////////////////////////////////////////////////////////////////////////////
            auxReturn = getInput(aux, "\nConfirma la baja? Y/N: ","\nLa Baja no se realizo.",0,2,1,5);
            if(auxReturn==0)
            {
                printf("Baja en curso ...");
                strcpy(arrayEmployee[value].name, empty);
                strcpy(arrayEmployee[value].lastName, empty);
                arrayEmployee[value].salary = 0;
                arrayEmployee[value].sector = 0;
                arrayEmployee[value].isEmpty = -1;
            }
            else
                auxReturn=-1;
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SFO
int searchForOccurrence(Employee arrayEmployee[], int size){
    int flag = -1;
    int i;

    if(arrayEmployee != NULL && size>=0)
    {
        for(i=1000;i<size;i++)
        {
            if(arrayEmployee[i].isEmpty == -1)
                continue;
            else if(arrayEmployee[i].isEmpty == 0)
            {
                flag = arrayEmployee[i].isEmpty;
            }
        }
    }
    return flag;
}
/////////////////////////////////////////////////////////////////////////  PE
int printEmployees(Employee arrayEmployee[],int size){
    int auxReturn=-1;
    int i;

    if(arrayEmployee!=NULL && size>=0)
    {
        printf("ID\t  APELLIDO\t  NOMBRE\t  SUELDO\t  SECTOR\t\n");
        for(i=1000;i<size-1;i++)
        {
            if(arrayEmployee[i].isEmpty==0)
            {
                auxReturn=0;
                printf("\n%d\t  %s\t  %s\t  %.2f\t  %d\t", arrayEmployee[i].idEmployee, arrayEmployee[i].lastName, arrayEmployee[i].name, arrayEmployee[i].salary, arrayEmployee[i].sector);
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SEN
int sortEmployeeByName(Employee arrayEmployee[], int size, int pOrder){
    int auxReturn=-1;
    int i,j;

    int pId;
    char pName[50];
    char pLname[50];
    int pSector;
    float pSalary;
    int pIsEmpty;
    /////////////////////////////////
    if(arrayEmployee!=NULL && size>=0)
    {
        if(pOrder==1)
        {
            for(i=1000;i<size-1;i++)
            {
                if(arrayEmployee[i].isEmpty!=0)
                    continue;
                else if(strcmp(arrayEmployee[i].lastName,arrayEmployee[i+1].lastName)>0)
                {
                    pId = arrayEmployee[i].idEmployee;
                    strcpy(pName, arrayEmployee[i].name);
                    strcpy(pLname, arrayEmployee[i].lastName);
                    pSalary = arrayEmployee[i].salary;
                    pSector = arrayEmployee[i].sector;
                    pIsEmpty = arrayEmployee[i].isEmpty;
                    ////////////////////////////////// swap X ascendente step 1
                    arrayEmployee[i].idEmployee = arrayEmployee[i+1].idEmployee;
                    strcpy(arrayEmployee[i].name, arrayEmployee[i+1].name);
                    strcpy(arrayEmployee[i].lastName, arrayEmployee[i+1].lastName);
                    arrayEmployee[i].salary = arrayEmployee[i+1].salary;
                    arrayEmployee[i].sector = arrayEmployee[i+1].sector;
                    arrayEmployee[i].isEmpty = arrayEmployee[i+1].isEmpty;
                    ////////////////////////////////// swap X ascendente step 2
                    arrayEmployee[i+1].idEmployee = pId;
                    strcpy(arrayEmployee[i+1].name, pName);
                    strcpy(arrayEmployee[i+1].lastName, pLname);
                    arrayEmployee[i+1].salary = pSalary;
                    arrayEmployee[i+1].sector = pSector;
                    arrayEmployee[i+1].isEmpty = pIsEmpty;
                    ////////////////////////////////// swap X ascendente step 3
                }
                if(arrayEmployee[i].isEmpty!=0)
                    continue;
                else if(strcmp(arrayEmployee[i].lastName, arrayEmployee[i+1].lastName)==0)
                {
                    if(arrayEmployee[i].sector > arrayEmployee[i+1].sector)
                    {
                        pId = arrayEmployee[i].idEmployee;
                        strcpy(pName, arrayEmployee[i].name);
                        strcpy(pLname, arrayEmployee[i].lastName);
                        pSalary = arrayEmployee[i].salary;
                        pSector = arrayEmployee[i].sector;
                        pIsEmpty = arrayEmployee[i].isEmpty;
                        ////////////////////////////////// swap Y ascendente step 1
                        arrayEmployee[i].idEmployee = arrayEmployee[i+1].idEmployee;
                        strcpy(arrayEmployee[i].name, arrayEmployee[i+1].name);
                        strcpy(arrayEmployee[i].lastName, arrayEmployee[i+1].lastName);
                        arrayEmployee[i].salary = arrayEmployee[i+1].salary;
                        arrayEmployee[i].sector = arrayEmployee[i+1].sector;
                        arrayEmployee[i].isEmpty = arrayEmployee[i+1].isEmpty;
                        ////////////////////////////////// swap Y ascendente step 2
                        arrayEmployee[i+1].idEmployee = pId;
                        strcpy(arrayEmployee[i+1].name, pName);
                        strcpy(arrayEmployee[i+1].lastName, pLname);
                        arrayEmployee[i+1].salary = pSalary;
                        arrayEmployee[i+1].sector = pSector;
                        arrayEmployee[i+1].isEmpty = pIsEmpty;
                        ////////////////////////////////// swap Y ascendente step 3
                    }
                }
            }
        }
        if(pOrder==2)
        {
            for(j=1000;j<size-1;j++)
            {
                if(arrayEmployee[j].isEmpty!=0)
                    continue;
                else if(strcmp(arrayEmployee[j].lastName,arrayEmployee[j+1].lastName)<0)
                {
                    pId = arrayEmployee[j].idEmployee;
                    strcpy(pName, arrayEmployee[j].name);
                    strcpy(pLname, arrayEmployee[j].lastName);
                    pSalary = arrayEmployee[j].salary;
                    pSector = arrayEmployee[j].sector;
                    pIsEmpty = arrayEmployee[j].isEmpty;
                    ////////////////////////////////// swap X ascendente step 1
                    arrayEmployee[j].idEmployee = arrayEmployee[j+1].idEmployee;
                    strcpy(arrayEmployee[j].name, arrayEmployee[j+1].name);
                    strcpy(arrayEmployee[j].lastName, arrayEmployee[j+1].lastName);
                    arrayEmployee[j].salary = arrayEmployee[j+1].salary;
                    arrayEmployee[j].sector = arrayEmployee[j+1].sector;
                    arrayEmployee[j].isEmpty = arrayEmployee[j+1].isEmpty;
                    ////////////////////////////////// swap X ascendente step 2
                    arrayEmployee[j+1].idEmployee = pId;
                    strcpy(arrayEmployee[j+1].name, pName);
                    strcpy(arrayEmployee[j+1].lastName, pLname);
                    arrayEmployee[j+1].salary = pSalary;
                    arrayEmployee[j+1].sector = pSector;
                    arrayEmployee[j+1].isEmpty = pIsEmpty;
                    ////////////////////////////////// swap X ascendente step 3
                }
                if(arrayEmployee[j].isEmpty!=0)
                    continue;
                else if(strcmp(arrayEmployee[j].lastName, arrayEmployee[j+1].lastName)==0)
                {
                    if(arrayEmployee[j].sector < arrayEmployee[j+1].sector)
                    {
                        pId = arrayEmployee[j].idEmployee;
                        strcpy(pName, arrayEmployee[j].name);
                        strcpy(pLname, arrayEmployee[j].lastName);
                        pSalary = arrayEmployee[j].salary;
                        pSector = arrayEmployee[j].sector;
                        pIsEmpty = arrayEmployee[j].isEmpty;
                        ////////////////////////////////// swap Y ascendente step 1
                        arrayEmployee[j].idEmployee = arrayEmployee[j+1].idEmployee;
                        strcpy(arrayEmployee[j].name, arrayEmployee[j+1].name);
                        strcpy(arrayEmployee[j].lastName, arrayEmployee[j+1].lastName);
                        arrayEmployee[j].salary = arrayEmployee[j+1].salary;
                        arrayEmployee[j].sector = arrayEmployee[j+1].sector;
                        arrayEmployee[j].isEmpty = arrayEmployee[j+1].isEmpty;
                        ////////////////////////////////// swap Y ascendente step 2
                        arrayEmployee[j+1].idEmployee = pId;
                        strcpy(arrayEmployee[j+1].name, pName);
                        strcpy(arrayEmployee[j+1].lastName, pLname);
                        arrayEmployee[j+1].salary = pSalary;
                        arrayEmployee[j+1].sector = pSector;
                        arrayEmployee[j+1].isEmpty = pIsEmpty;
                        ////////////////////////////////// swap Y ascendente step 3
                    }
                }
            }
        }
        auxReturn=0;
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  Inform A
int informA(Employee arrayEmployee[], int size){
    int auxReturn = -1;
    int i;
    int eToken=0;
    int sToken=0;
    float sBuffer=0;

    if(arrayEmployee != NULL && size>=0)
    {
        for(i=1000;i<size-1;i++)
        {
            if(arrayEmployee[i].isEmpty == -1)
                continue;
            else if(arrayEmployee[i].isEmpty == 0)
            {
                eToken++;
                sBuffer = sBuffer + arrayEmployee[i].salary;
            }
        }

        printf("\n\nNOMINA SALARIAL: %.2f", sBuffer);
        printf("\nSUELDO PROMEDIO: %.2f", sBuffer/eToken);

        for(i=1000;i<size-1;i++)
        {
            if(arrayEmployee[i].isEmpty == 0 && arrayEmployee[i].salary > sBuffer/eToken)
            {
                sToken++;
            }
        }
        printf("\n\nEmpleados que superan el salario promedio: %d\n", sToken);
    }
    return auxReturn;
}
