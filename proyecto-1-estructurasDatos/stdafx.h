// stdafx.h: archivo de inclusión de los archivos de inclusión estándar del sistema
// o archivos de inclusión específicos de un proyecto utilizados frecuentemente,
// pero rara vez modificados
#pragma once

// TODO: mencionar aquí los encabezados adicionales que el programa necesita
#include <iostream>
using namespace std;

class nodo {

public:
	nodo(int val, nodo *sig)
	{
		dato = val;
		operador = NULL;
		siguiente = sig;
	}
	nodo(System::Char val, nodo *sig)
	{
		operador = val;
		dato = NULL;
		siguiente = sig;
	}
	
private:
	int dato;
	System::Char operador;
	nodo *siguiente;
	
	friend class Pila;
	friend class lista;
	friend class util;

};

class lista{

public:
	lista() { primerNodo = NULL; }
	~lista();

	System::String^ muestraLista();
	bool ListaVacia() { return primerNodo == NULL; } 
	void insertaAlFinal(System::Object^ val);
	System::Char^ getOperadorEnPos(int pos);
	int getOperandoEnPos(int pos);
	
private:
	nodo * primerNodo;
	
	friend class util;
	friend class Pila;

};

class Pila{

public:

	Pila() {top = NULL; };

	bool estaVacia(){ return top == NULL; }
	void push(System::Object^ dato);
	System::Object^ pop();

private:
	nodo * top;

	friend class nodo;
	friend class lista;
	friend class util;


};

class util{

public:
	int operacion(int n1, int n2, char signo);
	int prioridad(System::Char^ oper, char lugar);
	int checkSintaxis(lista &exp);
	void convierteAPostFijo(lista &expresionOrigen, lista &expresionDestino, bool parentesis, bool cornum);
	int evaluaEnPostFijo(lista &expresion);
};


