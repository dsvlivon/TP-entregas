/*******************************************************************
*Programa:TP2
*Objetivo: Sistema para administrar nómina de empleados
*Version: 1.0 del 25 de Septiembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
typedef struct{
    int idEmployee;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;
//////////////////////////
/** initEmployees
*\brief Inicializa todas las posiciones del array con un valor de posicion libre
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
void initEmployees(Employee arrayEmployee[],int size);
/////////////////////////////////////////////////////////////////////////// INIT
/** addEmployee
*\brief Agrego datos a los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int addEmployee(Employee arrayEmployee[], int size);
/////////////////////////////////////////////////////////////////////////// ADD
/** modifEmployee
*\brief modifica los datos de los distintos campos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int modifEmployee(Employee arrayEmployee[], int size);
/////////////////////////////////////////////////////////////////////////// MODIF
/** removeEmployee
*\brief Realiza la baja logica de los datos de la estructura en una posicion del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int removeEmployee(Employee arrayEmployee[], int size);
/////////////////////////////////////////////////////////////////////////// REMOVE
/** findEmployeeById
*\brief Pide un valor para recorrer el array, buscarlo y validar su disponibilidad
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param auxId es el valor a comparar en la busqueda
*\return void
*/
int findEmployeeById(Employee arrayEmployee[], int size, int *auxId);
/////////////////////////////////////////////////////////////////////////// FID
/** searchForEmpty
*\brief Recorre el array buscando el primer valor de posicion libre disponible
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param position devuelve la posicion libre en cuestion
*\return void
*/
int searchForEmpty(Employee arrayEmployee[], int size, int* position);
/////////////////////////////////////////////////////////////////////////// SFE
/** searchForOccurrence
*\brief Recorre el array buscando valores de posicion ocupadas
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int searchForOccurrence(Employee arrayEmployee[], int size);
/////////////////////////////////////////////////////////////////////////// SFO
/** printEmployees
*\brief imprime en pantalla los datos de las posiciones marcadas como ocupado del array
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int printEmployees(Employee arrayEmployee[],int size);
/////////////////////////////////////////////////////////////////////////// PRINT
/** sortEmployeeByName
*\brief Realiza uno o más ordenamientos segun un determinado criterio
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\param pOrder recibe un valor numerico que determina el criterio para ordenar
*\return void
*/
int sortEmployeeByName(Employee arrayEmployee[], int size, int pOrder);
/////////////////////////////////////////////////////////////////////////// SORT
/** informA
*\brief Realiza un informe de datos cruzados especificos.
*\param array es el array a ser inicializado
*\param size indica la longitud del array
*\return void
*/
int informA(Employee arrayEmployee[], int size);
/////////////////////////////////////////////////////////////////////////// INFA
