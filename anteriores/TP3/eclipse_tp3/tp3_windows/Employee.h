/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
////////////////////////////////////////////////////////////////////////////////// Employee New
/** \brief Reserva un espacio de memoria para un Employee
 * \return this
 */
Employee* employee_new();
////////////////////////////////////////////////////////////////////////////////// Employee NewPARAMETROS
/** \brief Asigna valores a los campos de Employee
* \param idStr recibe un Id
* \param nombreStr recibe un nombre
* \param horasTrabajadasStr recibe un valor de horas
* \param suedloStr recibe un valor de sueldo
* \return this
*/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
////////////////////////////////////////////////////////////////////////////////// SET ID
/** \brief Asigna un valor a un campo de Employee
* \param recibe un Id
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_setId(Employee* this,int id);
////////////////////////////////////////////////////////////////////////////////// GET ID
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_getId(Employee* this ,int* id);
////////////////////////////////////////////////////////////////////////////////// SET Name
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_setNombre(Employee* this,char* nombre);
////////////////////////////////////////////////////////////////////////////////// GET Name
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_getNombre(Employee* this,char* nombre);
////////////////////////////////////////////////////////////////////////////////// SET Hours
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
////////////////////////////////////////////////////////////////////////////////// GET Hours
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
////////////////////////////////////////////////////////////////////////////////// SET Salary
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_setSueldo(Employee* this,int sueldo);
////////////////////////////////////////////////////////////////////////////////// GET Salary
/** \brief Obtiene un valor a un campo de Employee
* \param recibe un puntero para sobre escribir
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_getSueldo(Employee* this,int* sueldo);
////////////////////////////////////////////////////////////////////////////////// SORT Salary
/** \brief Realiza un ordenamiento segun un criterio
* \param recibe un puntero a un elemento
* \param recibe un puntero a un elemento para comparar
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_sortBySalary(void*arg1, void* arg2);
////////////////////////////////////////////////////////////////////////////////// SORT Hours
/** \brief Realiza un ordenamiento segun un criterio
* \param recibe un puntero a un elemento
* \param recibe un puntero a un elemento para comparar
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_sortByWorkedHours(void*arg1, void* arg2);
////////////////////////////////////////////////////////////////////////////////// SORT Name
/** \brief Realiza un ordenamiento segun un criterio
* \param recibe un puntero a un elemento
* \param recibe un puntero a un elemento para comparar
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int employee_sortByName(void*arg1, void* arg2);

#endif // employee_H_INCLUDED