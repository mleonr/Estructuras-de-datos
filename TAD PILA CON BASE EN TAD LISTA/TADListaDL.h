/*
	IMPLEMENTACIONES DEL TAD LISTA (TADListaDL.h)
	AUTOR: MARCOS LEÓN REYES (C) ABRIL 2018
	VERSIÓN: 1

	EL CODIGO QUE IMPLEMENTA LAS FUNCIONES ES EL ARCHIVO: TADListaDL.c
*/

#define TRUE 1
#define FALSE 0

typedef unsigned char boolean;

typedef struct elemento
{
	/*Aquí se agregan los tipos de datos que
	se desea que almacene el elemento*/
	int n;
	char c;
	double d;
	char p[45]; //Proceso
	char a[200]; //Actividad
	char i[45]; //ID
	int  t; //Tiempo de ejecucion
	int taux;
	int taux1;//Se usa para decir cuanto tiempo lleva en total ejecutandose un proceso(cola de listos+ cola de ejecucion)
	int t_ult;//Este tiempo va decrementando conforme se va ejecutando el proceso(ultimo proceso)
	int t_sig;//Este tiempo va decrementando conforme se va ejecutando el proceso(proceso siguiente)
	
}elemento;

//Estructura de un nodo doblemente ligado
typedef struct nodo
{	
	elemento e;
	
	//Relación con el nodo anterior
	struct nodo *anterior; //Va a guardar la dirección de memoria de un tipo de dato nodo ej. 61ff04 
	//Relación con el siguiente nodo
	struct nodo *siguiente;	

}nodo;
	
//Se define una posicion como un apuntador a nodo
typedef nodo* posicion;
	
typedef struct lista{
	
	int tamanio;
	posicion frente; 
	posicion final;	
	
}lista;

//DECLARACIÓN DE FUNCIONES

//Efecto: Recibe una lista l y la inicializa para su trabajo normal.
void Initialize (lista *l);

//Efecto: Recibe una lista l y la libera completamente
void Destroy (lista *l);

//Efecto: Recibe una lista l y retorna la posición del elemento al final de esta.
posicion Final (lista *l);

//Efecto: Recibe una lista l y devuelve la posición del elemento al inicio de esta.
posicion First (lista *l);

//Efecto: Recibe una lista l, una posición p y devuelve la posición del elemento siguiente de p.
//Requerimientos: La lista l es no vacía y la posición p es una posición valida.
posicion Following (lista *l,posicion p);

//Efecto: Recibe una lista l, una posición p y devuelve la posición del elemento anterior a p.
//Requerimientos: La lista l es no vacía y la posición p es una posición valida.
posicion Previous (lista *l,posicion p);

//Efecto: Recibe una lista l y un elemento e, devuelve la posición del elemento que coincida exactamente con e.
posicion Search (lista *l,elemento e);

//Efecto: Recibe una lista l, una posición p y devuelve el elemento en dicha posición. 
//Requerimientos: La lista l es no vacía y la posición p es una posición valida.
elemento Position (lista *l,posicion p);

//Efecto: Recibe una lista l, una posición p y devuelve TRUE si la posición es una posición p valida en la lista l y FALSE en caso contrario.
boolean ValidatePosition (lista *l,posicion p);

//Efecto: Recibe una lista y un índice (entre 1 y el tamaño de la lista) y devuelve el elemento que se encuentra en la lista en ese índice partiendo del frente de este =1 hacia atrás.
//Excepción: Si la cola esta vacía o el índice se encuentra fuera del tamaño de la lista se produce error.
elemento Element(lista *l, int n);

//Efecto: Recibe una lista y un índice (entre 1 y el tamaño de la lista) y devuelve la posición del elemento que se encuentra en la lista en ese índice partiendo del frente de este =1 hacia atrás.
//Excepción: Si la cola esta vacía o el índice se encuentra fuera del tamaño de la lista se retorna una posición invalida.
posicion ElementPosition(lista *l, int n);

//Efecto: Recibe una lista l y devuelve el tamaño de la lista.
int Size (lista *l);

//Efecto: Recibe una lista l y devuelve TRUE en caso de que la lista este vacía y FALSE en caso contrario.
boolean Empty (lista *l);

//Efecto: Recibe una lista l, una posición p, un elemento e y un valor booleano; el elemento e deberá agregarse al frente de p si b es verdadero y atrás de p en caso contrario.
//Requerimientos: La posición p es una posición válida, si p es no válida o NULL, se insertará a e al frente de la lista.
void Insert (lista * l, posicion p, elemento e, boolean b);

//Efecto: Recibe una lista l y un elemento e , el elemento e deberá agregarse al final de la lista
void Add (lista *l,elemento e);

//Efecto: Recibe una lista l y una posición p, el elemento en la posición p será removido.
//Requerimientos: La lista l es no vacía y la posición p es una posición valida.
void Remove (lista *l,posicion p);

//Efecto: Recibe una lista l, una posición p y un elemento e, el elemento en la posición p será sustituido por e
//Requerimientos: La lista l es no vacía y la posición p es una posición valida.
void Replace (lista *l,posicion p, elemento e);

//Función para usarse en depuración, la cuál imprime las direcciones de 
//memoria de los nodos y su apuntador a siguiente
void VerLigasLista(lista *l);

