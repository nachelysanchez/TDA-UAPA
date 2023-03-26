#include <iostream>
#include <cmath>

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
		
		
		void InsertarPosicion(int valor,int posicion){
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
		
		int RestarNodos(int n1, int n2){
			
			return abs(n1) - abs(n2);
		}
};

int main(){
	Lista* lista = new Lista();
	cout<<"En este programa, se estará dando los dos primeros numeros de la lista, para \nagregar un nuevo numero que correspondera a la diferencia de los primeros dos." << endl;
	int numero1, numero2;
	cout<<"Ingrese el primer numero: "<< endl;
	cin>>numero1;
	cout<<"Ingrese el segundo numero: "<< endl;
	cin>>numero2;
	
	lista->Insertar(numero1);
	lista->Insertar(numero2);
	
	int resultado = lista->RestarNodos(numero1, numero2);
	
	lista->InsertarPosicion(resultado, 1);
	
	lista->Listar();
	return 0;
}
