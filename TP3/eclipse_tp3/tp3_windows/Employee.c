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
#include "Employee.h"
#include "validations.h"
////////////////////////////////////////////////////////////////////////////////// SET ID
int employee_setId(Employee* this,int id){

    int auxReturn = -1;
    static int idGenerator=-1;

    if( this != NULL && id==-1)
    {
        idGenerator++;
        //id=idGenerator;
        this->id = idGenerator;
        auxReturn = 0;
    }
    else if(id>idGenerator)
    {
        idGenerator=id;
        this->id=idGenerator;
        auxReturn=0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET ID
int employee_getId(Employee* this,int* id){
    int auxReturn = -1;

    if( this != NULL && id != NULL )
    {
        *id = this->id;
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SET Name
int employee_setNombre(Employee* this,char* nombre){
    int auxReturn = -1;

    if( this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        auxReturn = 0;
    }
    return auxReturn;

}
////////////////////////////////////////////////////////////////////////////////// GET Name
int employee_getNombre(Employee* this,char* nombre){
    int auxReturn = -1;

    if( this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SET Hours
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int auxReturn = -1;

    if( this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET Hours
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int auxReturn = -1;

    if( this != NULL && horasTrabajadas != NULL )
    {
        *horasTrabajadas = this->horasTrabajadas;
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SET Salary
int employee_setSueldo(Employee* this,int sueldo){
    int auxReturn = -1;

    if( this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// GET Salary
int employee_getSueldo(Employee* this,int* sueldo){
    int auxReturn = -1;

    if( this != NULL && sueldo != NULL )
    {
        *sueldo = this->sueldo;
        auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// Employee New
Employee* employee_new(){

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}
////////////////////////////////////////////////////////////////////////////////// Employee NewPARAMETROS
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

    Employee* this;
    int flag=-1;
    int auxId,auxHs,auxSalary;
    char auxName[50];

    if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this  = employee_new();
        if(this != NULL)
        {
            if(isNumeric(idStr)==0)
            {
                auxId = atoi(idStr);
                flag = employee_setId(this, auxId);
                //printf("id: %d", auxId);
            }
            if(flag==0)
            {
                if(isLetter(nombreStr)==0)
                {
                    strcpy(auxName, nombreStr);
                    flag = employee_setNombre(this, auxName);
                    //printf("\nNOMBRE: %s", auxName);
                }
            }
            if(flag==0)
            {
                if(isOnlyNumber(horasTrabajadasStr)==0)
                {
                    auxHs = atoi(horasTrabajadasStr);
                    flag = employee_setHorasTrabajadas(this, auxHs);
                    //printf("horas: %d", auxHs);
                }
            }
            if(flag==0)
            {
                if(isOnlyNumber(sueldoStr)==0)
                {
                    auxSalary = atoi(sueldoStr);
                    flag = employee_setSueldo(this, auxSalary);
                    //printf("sueldo: %d", auxSalary);
                }
            }
        }
        else
            printf("sale x This != NULL");
        if(flag!=0)
        {
            free(this);
            this = NULL;
            printf("Datos corruptos.");
        }
    }
    return this;
}
////////////////////////////////////////////////////////////////////////////////// SORT Salary
int employee_sortBySalary(void*arg1, void* arg2){
    int auxReturn=0;
    Employee* p1=NULL;
    Employee* p2=NULL;

    if(arg1!=NULL && arg2!=NULL)
    {
        p1 = (Employee*)arg1;
        p2= (Employee*)arg2;
        if(p1->sueldo > p2->sueldo)
        {
            auxReturn=1;
        }
        else if(p1->sueldo < p2->sueldo)
        {
            auxReturn=-1;
        }
        else
            auxReturn=0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SORT Hours
int employee_sortByWorkedHours(void*arg1, void* arg2){
    int auxReturn=0;
    Employee* p1=NULL;
    Employee* p2=NULL;

    if(arg1!=NULL && arg2!=NULL)
    {
        p1 = (Employee*)arg1;
        p2= (Employee*)arg2;
        if( p1->horasTrabajadas > p2->horasTrabajadas)
        {
            auxReturn = 1;
        }
        else if( p1->horasTrabajadas < p2->horasTrabajadas)
        {
            auxReturn = -1;
        }
        else
            auxReturn = 0;
    }
    return auxReturn;
}
////////////////////////////////////////////////////////////////////////////////// SORT Name
int employee_sortByName(void*arg1, void* arg2){
    int auxReturn=0;
    Employee* p1=NULL;
    Employee* p2=NULL;

    if(arg1!=NULL && arg2!=NULL)
    {
        p1 = (Employee*)arg1;
        p2= (Employee*)arg2;
        if(strcmp(p1->nombre,p2->nombre)>0)
        {
            auxReturn = 1;
        }
        if(strcmp(p1->nombre,p2->nombre)<0)
        {
            auxReturn = -1;
        }
        else
        {
            auxReturn = 0;
        }
    }
    return auxReturn;
}
