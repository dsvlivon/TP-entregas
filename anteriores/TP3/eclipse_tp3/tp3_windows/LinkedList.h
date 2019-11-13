/*******************************************************************
*Programa:ABM aplicacion para administrar nomina de empleados
*Objetivo: Esqueleto para ABM utilizando punteros y linkedList
*Version: 1.0 del 1 de Noviembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;// puntero a un elemento
    struct Node* pNextNode; // puntero de puntero
}typedef Node;

struct LinkedList
{
    Node* pFirstNode; //puntero a primer elemento de la estructura node
    int size; // un tamaño
}typedef LinkedList;
#endif


//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
/////////////////////////////////////////////   BLOQUE CREACION DE LINKED
int ll_add(LinkedList* this, void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
/////////////////////////////////////////////   SET/GET
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
/////////////////////////////////////////////
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
/////////////////////////////////////////////   ORDENAMIENTO
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
/////////////////////////////////////////////
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
