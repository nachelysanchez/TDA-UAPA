#include <iostream>

using namespace std;

struct Alumno{
	int id;
	string nombre;
	int edad;
	string sexo;
};

//ENLAZADA SIMPLE
class Nodo{
	public:
		Alumno* dato;
		Nodo* siguiente;
		//Este es uno de los constructores que utilizo normalmente en las clases
		Nodo(Alumno* dato){
			this->dato = dato;
			this->siguiente = NULL;
		}
		//Este es uno de los constructores que utilizo normalmente en las clases, 
		//donde asigno por parametro el alumno, y el siguiente
		Nodo(Alumno* dato, Nodo* siguiente){
			this->dato = dato;
			this->siguiente = siguiente;
		}
};
//Estos son mis nodos primero y ultimo
Nodo *primero = NULL;
Nodo *ultimo = NULL;

class Lista{
	public: 
		//Constructor de la clase Lista
		Lista(){
			primero = ultimo = NULL;
		}
		//Metodo que ayuda a insertar por el final
		void InsertarCola(Alumno* dato){
			Nodo *nuevo = new Nodo(dato);
			if(primero == NULL){
				primero = ultimo = nuevo;
			}
			else{
				ultimo->siguiente = nuevo;
			}
		}
		//Metodo que ayuda a Listar los elementos de la lista
		void Listar(){
			Nodo *aux = primero;
			cout << "---------------------------------------------------------------------------"<<endl;
			cout << "Id  Nombre\t\t\t\tEdad\t\tSexo"<<endl;
			cout << "---------------------------------------------------------------------------"<<endl;
			while(aux){
				cout << aux->dato->id <<"  " <<aux->dato->nombre << "\t\t\t\t" << aux->dato->edad<<"\t\t"<< aux->dato->sexo<<endl;
				aux = aux->siguiente;
			}
		}
		//Metodo para asignar normalmente
		void Insertar(Alumno* dato){
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
		
		//Metodo que ayuda a organizar los sexos de los alumnos
		bool VerificarSexo(string sexo){
			if(ultimo->dato->sexo == sexo){
				cout << "El sexo que debes de ingresar es el contrario\n\n INGRESE LA INFORMACION DE MANERA CORRECTA";
				return false;
			}
			return true;
		}
		//Metodo que ayuda a verificar si existen elementos en la lista
		bool Existe(){
			if (primero != NULL){
				return true;
			}
			else{
				return false;
			}
		}
};

int main(){
	Lista *lista =new Lista();
	Alumno *alumno;
	int menu = 0;
	
	do{
		
		alumno = new Alumno();
		bool existe;
		cout<< "Bienvenidos al segundo ejercicio de la practica final"<<endl;
		cout<<"1. Insertar alumno \n2. Listar \n3. Salir Elija una opcion: ";
		cin >> menu;
		//Utilizo un menu para acceder de manera mas organizada a las opciones
		switch(menu){
			case 1://En la primera opcion, registramos un alumno, donde 
			//tenemos la particularidad de que evaluamos si la lista esta vacia para poder
			//Verificar el sexo
				cout<<"Registrar alumno"<< endl;
				cout<<"Id";
				cin>>alumno->id;
				cout << "Nombre de alumno: ";
				cin >> alumno->nombre;
				cout << "Edad: ";
				cin >> alumno->edad;
				cout<< "Sexo (Femenino/Masculino): ";
				cin >> alumno->sexo;
				
				existe = lista->Existe();
				
				if(existe == true){
					if(lista->VerificarSexo(alumno->sexo) == true){
						lista->Insertar(alumno);
						cout<<"Su alumno fue guardado con exito";
					}
				}
				else{
					lista->Insertar(alumno);
					cout<<"Su alumno fue guardado con exito";
				}
				
				break;
			case 2:
				//La segunda opcion nos permite listar los elementos
				lista->Listar();
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
