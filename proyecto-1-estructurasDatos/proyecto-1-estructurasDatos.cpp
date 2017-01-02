// proyecto-1-estructurasDatos.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "Form1.h"

using namespace proyecto1estructurasDatos;



int util::operacion(int n1, int n2, char signo){

	switch(signo){
		case '+':
			return n1 + n2;
			break;
		case '-':
			return n1 - n2;
			break;
		case '*':
			return n1 * n2;
			break;
		case '/':
			return n1 / n2;
			break;
		case '^':
			return Math::Pow(n1, n2);
			break;
	}

	return NULL;
			
			
};

void lista::insertaAlFinal(Object^ val){

	//MessageBox::Show(val->GetType()->ToString());

	if (ListaVacia()){
		if (val->GetType()->IsInstanceOfType(Int32())) {
			primerNodo = new nodo(Convert::ToInt32(val), NULL);
		}
		if (val->GetType()->IsInstanceOfType(char()) || val->GetType()->IsInstanceOfType(System::Char()) ) { 
			primerNodo = new nodo(Convert::ToChar(val), NULL);
		}
	}
	else{
		nodo * actual = primerNodo;
		while(actual->siguiente != NULL){ actual = actual->siguiente; };
		if (val->GetType()->IsInstanceOfType(Int32())) {
			actual->siguiente = new nodo(Convert::ToInt32(val), NULL);
		}
		if (val->GetType()->IsInstanceOfType(char()) || val->GetType()->IsInstanceOfType(System::Char()) ) { 
			actual->siguiente = new nodo(Convert::ToChar(val), NULL);
		}
	}

}


System::String^ lista::muestraLista(){


	String^ exp;
	nodo * actual = primerNodo;

	while(actual != NULL){
		if(actual->operador != NULL){
			exp+= actual->operador;
		}
		if(actual->dato != NULL){
			exp+= actual->dato;
		}
		actual = actual->siguiente;
	}

	return exp;

}


int lista::getOperandoEnPos(int pos){

	if (ListaVacia()){
		return NULL;
	}
	else{
		nodo * actual = primerNodo;
		int pac = 1;

		while(pac != pos){
			pac++;
			actual = actual->siguiente;
		}
		if(actual != NULL) { return actual->dato; };
		if(actual == NULL) { return NULL; };
	}

	return NULL;

}
System::Char^ lista::getOperadorEnPos(int pos){

	if (ListaVacia()){
		return System::Char(NULL);
	}
	else{
		nodo * actual = primerNodo;
		int pac = 1;

		while(pac != pos){
			pac++;
			actual = actual->siguiente;
		}
		if(actual != NULL) { return actual->operador; };
		if(actual == NULL) { System::Char(NULL); };
	}

	return System::Char(NULL);
}
int util::checkSintaxis(lista & exp){


	nodo * actual = exp.primerNodo;

	int abrePar = 0;
	int cierraPar = 0;

	while(actual->operador != '#'){
		
		if(actual->operador == '(') { abrePar++; };
		if(actual->operador == ')') { cierraPar++; };

		actual = actual->siguiente;
	}

	return abrePar - cierraPar;


};
int util::evaluaEnPostFijo(lista &expresion){


	util util;
	nodo * actual = expresion.primerNodo;
	int resultado = 0;
	int v1 = 0;
	int v2 = 0;

	Pila ops;

	while(actual != NULL){
		//si es operando
		if (actual->dato != NULL){ ops.push(actual->dato); };
		if ((actual->operador != NULL) && (actual->operador != '(' && actual->operador != ')') && (actual->operador != '[' && actual->operador != ']') ){ 
			v2 = Convert::ToInt32(ops.pop());
			v1 = Convert::ToInt32(ops.pop());
			ops.push(util.operacion(v1, v2, Convert::ToChar(actual->operador)));
		}

		actual = actual->siguiente;
	}

	resultado = Convert::ToInt32(ops.pop());

	return resultado;



};
int util::prioridad(System::Char^ oper, char lugar){

	if(lugar == 'd'){
		if(oper->Equals('^')) { return 3; };
		if(oper->Equals('*') || oper->Equals('/')) { return 2; };
		if(oper->Equals('+') || oper->Equals('-')) { return 1; };
		if(oper->Equals('(')) { return 0; };
	}

	if(lugar == 'f'){
		if(oper->Equals('^')) { return 4; };
		if(oper->Equals('*') || oper->Equals('/')) { return 2; };
		if(oper->Equals('+') || oper->Equals('-')) { return 1; };
		if(oper->Equals('(')) { return 5; };
	}

	return NULL;


};
void util::convierteAPostFijo(lista &expresionOrigen, lista &expresionDestino, bool parentesis, bool cornum){

		util util;
		nodo * actual = expresionOrigen.primerNodo;

		Pila operadores;

		while(actual->operador != '#'){
			
			//si el elemento actual de la expresion es un operador
			if(actual->operador != NULL){
				//si la pila esta vacia meter el operador de una
				if (operadores.estaVacia()){
					operadores.push(actual->operador);
					if (parentesis) { if( actual->operador == '(' ) { expresionDestino.insertaAlFinal('('); };};
				}
				else
				{

					//si no esta vacia pero es un cerrar parentesis ')' entonces meter todos los elementos de la
					//pila hasta encontrarse el parentesis correspondiente 
					if(actual->operador == ')'){
						System::Char^ op = Convert::ToChar(operadores.pop());
						while(!op->Equals('(')){
							expresionDestino.insertaAlFinal(op);
							op = Convert::ToChar(operadores.pop());
						}
						if (parentesis) { expresionDestino.insertaAlFinal(')'); };
					}
					else
					{	//si no es un cerrar parentesois )

						//si no esta vacia entonces meterlo solo si el top es menor prioridad ke el actual operador
						if(util.prioridad(operadores.top->operador, 'd') < util.prioridad(actual->operador, 'f')) {
							operadores.push(actual->operador);
							if (parentesis) { if( actual->operador == '(' ) { expresionDestino.insertaAlFinal('('); };};
						}
						else{
							//si la prioridad del top es mayor que el actual operador se mete en la lista de elementos
							if(util.prioridad(operadores.top->operador, 'd') > util.prioridad(actual->operador, 'f')){
								expresionDestino.insertaAlFinal(actual->operador);
							}
							else{
								//si la prioridad del top es = que el actual operador se saca se pone en la lista de elementos y se mete actual
								if(util.prioridad(operadores.top->operador, 'd') == util.prioridad(actual->operador, 'f')){
									expresionDestino.insertaAlFinal(operadores.pop()); //se mete el top de los operadores en lista elem tmp
									operadores.push(actual->operador); //se mete el operador actual a pila operadores 
								}
							}
						}
					} //endif de actual operador = ")"
				} //endif de operadores esta vacia
			} //fin if elemento es operador

			//si el elemento actual es un operando se mete a la lista tmp asi vulgarmente
			if(actual->dato != NULL){
				if (cornum) { expresionDestino.insertaAlFinal('['); };
				expresionDestino.insertaAlFinal(actual->dato);
				if (cornum) { expresionDestino.insertaAlFinal(']'); };
			}

			actual = actual->siguiente;
		}


		while(operadores.top != NULL){
			System::Char^ op = Convert::ToChar(operadores.pop());
			expresionDestino.insertaAlFinal(op);
		}			


}
lista::~lista()
{
   nodo * aux;
   
   while(primerNodo) {
      aux = primerNodo;
	  primerNodo = primerNodo->siguiente;
      delete aux;
   }
   
}


void Pila::push(System::Object^ val){

	if (estaVacia()){
		if (val->GetType()->IsInstanceOfType(Int32())) {
			top = new nodo(Convert::ToInt32(val), NULL);
		}
		if (val->GetType()->IsInstanceOfType(System::Char())) { 
			top = new nodo(Convert::ToChar(val), NULL);
		}
	}
	else{
		if (val->GetType()->IsInstanceOfType(Int32())) {
			top = new nodo(Convert::ToInt32(val), top);
		}
		if (val->GetType()->IsInstanceOfType(System::Char())) { 
			top = new nodo(Convert::ToChar(val), top);
		}
	}

		

}

System::Object^ Pila::pop(){
	
	System::Object^ val;
	if (top->operador != NULL) { val = top->operador; };
	if (top->dato != NULL) { val = top->dato; };
	
	nodo * aux = top;

	top = top->siguiente;
	delete aux;

	return val;

}



[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Habilitar los efectos visuales de Windows XP antes de crear ningún control
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Crear la ventana principal y ejecutarla
	Application::Run(gcnew Form1());
	return 0;


}

