#include <iostream>

using namespace std;

//PILA
class Nodo{
	public:
		char dato;
		Nodo* siguiente;
		Nodo(char dato){
			this->dato = dato;
			this->siguiente = NULL;
		}
		Nodo(char dato, Nodo* siguiente){
			this->dato = dato;
			this->siguiente = siguiente;
		}
};



Nodo *_head = NULL;
Nodo *_tail = NULL;

class Pila{
	public: 
		Pila(){
			_head = _tail = NULL;
		}
		
		void Push(char dato){
			Nodo *nuevo = new Nodo(dato);
			if(_head == NULL){
				_head = _tail = nuevo;
			}
			else{
				nuevo->siguiente = _head;
				_head = nuevo;
			}
		}
		
		Nodo* Pop(){
			Nodo* aux = _head;
			
			_head = _head->siguiente;
			aux->siguiente = NULL;
			
			return aux;
		}
		
		
		void Listar(){
			Nodo *aux = _head;
			while(aux){
				cout << aux->dato << "->";
				aux = aux->siguiente;
			}
		}
		
		bool esVacia(){
			if(_head == NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		
};

//OPCIONES DEL MENU PRINCIPAL
void PilaMain(Pila*);
void Parentesis(Pila*);

int main(){
	int menu;
	
	
	do{
		Pila* pila;
		string palabra;
		cout<<"Bienvenido a la asignacion 5 de Estructuras de datos...\n Nachely Victoria Sanchez Burgos 100046842"<<endl;
		cout<<"1. Pila con A, B, C, D, E.\n2. Balanceo de parentesis \n3. Palabra palindromas \n4. Insertar elemento F\n5. Elimina un elemento de la pila \n6. Salir\nEliga una opcion: ";
		cin>> menu;
		system("cls");
		switch(menu){
			case 1:
				pila = new Pila();
				PilaMain(pila);
				break;
			case 2:
				pila = new Pila();
				Parentesis(pila);
				break;
			case 3:
				cout << "Escriba la palabra a analizar: ";
				cin>> palabra;
				
				for(int i = 0; i < palabra.length(); i++){
					for(int j = palabra.length()-1; j >=0; j--){
						if (palabra[i]==palabra[j]){
							cout << "La palabra es palindroma";
						}
						else{
							cout << "La palabra no es palindroma";
						}
					}
				}
				
				break; 
			case 4:
				cout << "Lo encontrara en la primera opcion";
				break;
			case 5:
				cout << "Lo encontrara en la primera opcion";
				break;
			case 6:
				cout << "Gracias por usar este software. \n\n Att: Nachely Sanchez";
				break;
		}
		system("pause");
		system("cls");
	}while(menu != 6);
	
	return 0;
}


void Parentesis(Pila* pila){
	string expresion;
	cout<<"Ingrese la expresion: ";
	cin >> expresion;
	int i =0;
	int tam = expresion.length();
	
	while(i < tam){
		if(expresion[i] == '('){
			pila->Push('(');
		}
		else{
			if(pila->esVacia()){
				break;
			}
			else{
				pila->Pop();
			}
		}
		i++;
	}
	
	if(pila->esVacia() == true && i == tam){
		cout << "Parentesis balanceados";
	}
	else{
		cout << "Parentesis no balanceados";
	}
}
void PilaMain(Pila* pila){
	int menu;
	
	
	do{
		cout<<"PILA...\n Nachely Victoria Sanchez Burgos 100046842"<<endl;
		cout<<"1. Push letras A, B, C, D, E\n2. Pop\n3. Listar\n4. Push letra F \n5. Volver al menu principal\nEliga una opcion: ";
		cin>>menu;
		system("cls");
		switch(menu){
			case 1:
				pila->Push('E');
				pila->Push('D');
				pila->Push('C');
				pila->Push('B');
				pila->Push('A');
				cout<<"Lista llena"<<endl;
				break;
			case 2:
				pila->Pop();
				break;
			case 3:
				pila->Listar();
				break;
			case 4:
				pila->Push('F');
				break;
			case 5: 
				break;
			default:
				cout << "Esta opcion no se encuentra en el menu";
				break;
		}
		system("pause");
		system("cls");
	}while(menu != 5);
}



