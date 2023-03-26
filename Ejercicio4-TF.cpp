#include <iostream>

using namespace std;

//PILA
class Nodo{
	public:
		int dato;
		Nodo* siguiente;
		//Constructor
		Nodo(int dato){
			this->dato = dato;
			this->siguiente = NULL;
		}
		//Constructor
		Nodo(int dato, Nodo* siguiente){
			this->dato = dato;
			this->siguiente = siguiente;
		}
};

//Nodo cabeza
Nodo *_head = NULL;
//Nodo cola
Nodo *_tail = NULL;

//Clase Pila con sus metodos
class Pila{
	public: 
		//Constructor
		Pila(){
			_head = _tail = NULL;
		}
		//Metodo para ingresar datos a la pila
		void Push(int dato){
			Nodo *nuevo = new Nodo(dato);
			if(_head == NULL){
				_head = _tail = nuevo;
			}
			else{
				nuevo->siguiente = _head;
				_head = nuevo;
			}
		}
		
		//Metodo para listar los datos de la pila
		void Listar(){
			Nodo *aux = _head;
			while(aux){
				cout << aux->dato << "->";
				aux = aux->siguiente;
			}
		}
};

int main(){
	Pila *pila = new Pila();
	int menu = 0;
	int numero = 0;
	do{
		cout<< "Bienvenidos al cuatro ejercicio de la practica final"<<endl;
		cout<<"1. Insertar numero \n2. Listar \n3. Salir Elija una opcion: ";
		cin >> menu;
		//Utilizo un menu para acceder de manera mas organizada a las opciones
		switch(menu){
			case 1://En la primera opcion, registramos un numero par, donde 
			//tenemos la particularidad de evaluar si el mismo es de esa categoria o no
				cout << "Ingresa el numero"<<endl;
				cin >> numero;
				//Evaluamos si el numero es par
				if(numero % 2 == 0){
					pila->Push(numero);	
					cout << "El numero se agrego exitosamente"<< endl;
				}
				else{
					cout << "El numero debe de ser par"<<endl;
				}
				break;
			case 2:
				//La opcion dos sirve para listar los elementos de la pila
				pila->Listar();
				break;
			case 3:
				cout<<"Gracias por usar nuestros servicios\nNachely Sanchez 100046842";
				break;
			default:
				cout << "Escoge una opcion dentro de las del menu";
				break;
		}
		system("pause");
		system("cls");
	}while(menu != 3);
	
	return 0;
}
