#include <iostream>

using namespace std;

//ENLAZADA SIMPLE
class Nodo{
	public:
		int dato;
		Nodo* siguiente;
		Nodo(int dato){
			this->dato = dato;
			this->siguiente = NULL;
		}
		Nodo(int dato, Nodo* siguiente){
			this->dato = dato;
			this->siguiente = siguiente;
		}
};

Nodo *primero = NULL;
Nodo *ultimo = NULL;

class Lista{
	public: 
		Lista(){
			primero = ultimo = NULL;
		}
		
		void InsertarCabeza(int dato){
			Nodo *nuevo = new Nodo(dato);
			if(primero == NULL){
				primero = ultimo = nuevo;
			}
			else{
				nuevo->siguiente = primero;
				primero = nuevo;
			}
		}
		
		void InsertarPosicion(int valor, int posicion){
			Nodo* nuevo = new Nodo(valor);
					
			if(primero==NULL){//Si la lista está vacía
				primero = ultimo = nuevo;
				
			}else{//Si la lista no está vacía
				
				if(posicion<=0){
					InsertarCabeza(valor);
				}else{
								
					Nodo* aux = primero;
					
					for(int pos=0;aux!=NULL;pos++){
						if(pos==posicion-1){//si estoy posicionado en la posición anterior
							break;
						}
						
						aux= aux->siguiente;
					}
				
					if(aux==NULL)//Si la posición deseada no existe, agregamos en la ultima
						aux = ultimo;
						
						
					nuevo->siguiente = aux->siguiente; //El siguiente de nuevo = siguiente de auxiliar				
					aux->siguiente=nuevo; //El Siguiente de auxiliar = nuevo
					
					//Si estoy agregando en la última posición
					if(nuevo->siguiente == NULL)
						ultimo = nuevo;
				}
			}	
		}
		
		void InsertarCola(int dato){
			Nodo *nuevo = new Nodo(dato);
			if(primero == NULL){
				primero = ultimo = nuevo;
			}
			else{
				ultimo->siguiente = nuevo;
			}
		}
		
		void Listar(){
			Nodo *aux = primero;
			while(aux){
				cout << aux->dato << "->";
				aux = aux->siguiente;
			}
		}
		
		void Insertar(int dato){
			Nodo *nuevo = new Nodo(dato);
			Nodo *aux = primero;
			
			if (primero == NULL){
				InsertarCola(dato);
			}
			else{
				while(aux){
					if(aux->siguiente==NULL){
						nuevo->siguiente = aux->siguiente;
						aux->siguiente = nuevo;
						if(nuevo->siguiente==NULL){
							ultimo = nuevo;
							break;
						}
					}
					aux = aux->siguiente;
				}
				
			}
		}
		
		void Buscar(int elemento){
			Nodo *aux;
			bool flag = false;
			aux = primero;
			
			while(aux != NULL){
				if(aux->dato == elemento){
					cout << "El dato " << elemento << " existe..."<< endl;
					flag = true;
					break;
				}
				aux = aux->siguiente;
			}
			if (!flag)
				cout << "El elemento " << elemento << " no existe en la lista" << endl;
		}
		
		void eliminar(int posicion){
			Nodo* aux = primero;
			if(posicion == 0){
				primero = primero->siguiente;
				delete aux;
			}
			else{
				for(int i = 0; aux != NULL; i++){
					if(i == posicion - 1){
						break;
					}
					
					aux = aux->siguiente;
				}
				
				if(aux->siguiente!=NULL){
					Nodo *temp = aux->siguiente;
					aux->siguiente = temp->siguiente;
					
					if(temp->siguiente == NULL){
						ultimo = aux;
					}
					delete temp;
				}
			}
		}
};

//DOBLEMENTE ENLAZADA
class NodoDoble{
	public: 
		int dato;
		NodoDoble *siguiente;
		NodoDoble *anterior;
		
		NodoDoble(int v){
			this->dato = v;
			this->siguiente = NULL;
			this->anterior = NULL;
		}
		
		NodoDoble(int v, NodoDoble *siguiente){
			this->dato = v;
			this->siguiente = siguiente;
			this->anterior = NULL;
		}
};
NodoDoble *primeroD = NULL;
NodoDoble *ultimoD = NULL;
class ListaDoble{
	public:
		ListaDoble(){
			primeroD = ultimoD = NULL;
		}
		
		void Insertar(int v){
			NodoDoble *nuevo = new NodoDoble(v);
			if(primeroD == NULL){
				primeroD = ultimoD = nuevo;
			}
			else{
				ultimoD->siguiente = nuevo;
				nuevo->anterior = ultimoD;
				ultimoD = nuevo;
			}
		}
		
		void Listar(){
			NodoDoble *aux = primeroD;
			while(aux != NULL){
				cout << aux->dato << "->";
				aux = aux->siguiente;
			}
		} 
		
		void Eliminar(int v){
			NodoDoble *ant = primeroD;
			NodoDoble *aux = primeroD->siguiente;
			
			NodoDoble *temp;
			
			while(aux != NULL){
				if(aux->dato > v){
					temp = aux->siguiente;
					ant->siguiente = aux->siguiente;
					aux = temp;
				}
				else{
					ant = ant->siguiente;
					aux = aux->siguiente;
				}
			} 
		}
};

//OPCIONES DEL MENU PRINCIPAL
void ListasimpleMain(Lista*);
void ListaDobleMain(ListaDoble*);

int main(){
	int menu;
	
	
	do{
		Lista* lista;
		ListaDoble* listad;
		cout<<"Bienvenido a la asignacion 4 de Estructuras de datos...\n Nachely Victoria Sanchez Burgos 100046842"<<endl;
		cout<<"1. Lista simplemente enlazada.\n2. Lista doblemente enlazada 3. Salir\nEliga una opcion: ";
		cin>> menu;
		system("cls");
		switch(menu){
			case 1:
				lista = new Lista();
				ListasimpleMain(lista);
				break;
			case 2:
				listad = new ListaDoble();
				ListaDobleMain(listad);
				break;
			case 3: 
				cout << "Gracias por usar este software. \n\n Att: Nachely Sanchez";
				break;
		}
		system("pause");
		system("cls");
	}while(menu != 3);
	
	return 0;
}


void ListasimpleMain(Lista* lista){
	int menu;
	
	
	do{
		cout<<"Lista simplemente enlazada...\n Nachely Victoria Sanchez Burgos 100046842"<<endl;
		cout<<"1. Insertar en frente\n2. Insertar al final\n3. Insertar por posicion\n4. Buscar nodo\n5. Eliminar nodo\n6. Listar\n7. Volver al menu principal\nEliga una opcion: ";
		cin>>menu;
		system("cls");
		switch(menu){
			case 1:
				int elemento;
				cout << "Ingrese el nuevo nodo de la lista: ";
				cin >> elemento;
				lista->InsertarCabeza(elemento);
				break;
			case 2:
				int elemento1;
				cout << "Ingrese el nuevo nodo de la lista: ";
				cin >> elemento1;
				lista->Insertar(elemento1);
				break;
			case 3:
				int elemento2, posicion;
				cout << "Ingrese el nuevo nodo de la lista: ";
				cin >> elemento2;
				cout << "Ingrese la posicion donde quiere agregar: ";
				cin >> posicion;
				lista->InsertarPosicion(elemento2, posicion);
				break;
			case 4:
				int elemento3;
				cout << "Ingrese el dato que quiere buscar en la lista: ";
				cin >> elemento3;
				lista->Buscar(elemento3);
				break;
			case 5:
				int pos;
				cout << "Ingrese la posicion del dato que quiere eliminar: ";
				cin >> pos;
				lista->eliminar(pos);
				break;
			case 6:
				lista->Listar();
				break;
			case 7:
				break;
			default:
				cout << "Esta opcion no se encuentra en el menu";
				break;
		}
		system("pause");
		system("cls");
	}while(menu != 7);
}

void ListaDobleMain(ListaDoble *lista){
	int menu;
	
	
	do{
		cout<<"Lista doblemente enlazada...\n Nachely Victoria Sanchez Burgos 100046842"<<endl;
		cout<<"1. Insertar por el ultimo nodo\n2. Recorrer la lista\n3. Eliminar todos los nodos que superen un valor\n4. Volver al menu principal\nEliga una opcion: ";
		cin>>menu;
		system("cls");
		switch(menu){
			case 1:
				int elemento;
				cout << "Ingrese el nuevo nodo de la lista: ";
				cin >> elemento;
				lista->Insertar(elemento);
				break;
			case 2:
				lista->Listar();
				break;
			case 3:
				int elemento2;
				cout << "Ingrese el valor para eliminar los nodos: ";
				cin >> elemento2;
				lista->Eliminar(elemento2);
				break;
			case 4:
				break;
			default:
				cout << "Esta opcion no se encuentra en el menu";
				break;
		}
		system("pause");
		system("cls");
	}while(menu != 4);
}

