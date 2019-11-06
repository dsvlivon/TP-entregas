/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1�E T.N.
********************************************************************/
////////////////////////////////////////////////////////////////////////////////// LOAD CSV
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
////////////////////////////////////////////////////////////////////////////////// LOAD BIN
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
////////////////////////////////////////////////////////////////////////////////// ADD
/** \brief Agrega datos de un empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
////////////////////////////////////////////////////////////////////////////////// EDIT
/** \brief Modificar datos de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
////////////////////////////////////////////////////////////////////////////////// REMOVE
/** \brief Baja de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
////////////////////////////////////////////////////////////////////////////////// LIST
/** \brief Listar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
 int controller_listEmployee(LinkedList* pArrayListEmployee);
////////////////////////////////////////////////////////////////////////////////// SORT
/** \brief Ordenar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
////////////////////////////////////////////////////////////////////////////////// SAVE CSV
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
////////////////////////////////////////////////////////////////////////////////// SAVE BIN
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
////////////////////////////////////////////////////////////////////////////////// FIND ID
/** \brief Busca un id de empleado
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int
 */
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id);

