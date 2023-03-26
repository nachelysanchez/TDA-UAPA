#include <iostream>


using namespace std;
//Declaracion de metodos
void Insertar(int, int[]);
void Borrar();
void Listar(int n[]);
int cima = -1;
int maximo = 5;
//Se realizo directamente con arreglos, ya que trate de entender el tema con Pilas estaticas, pero por mas que investigue
//su implementacion, no pude realizarlo. Disculpe maestro.


int main(){
	int menu = 0, numero = 0;
	//Nuestra pila
	int Pila[maximo];
	do{
		cout<< "Bienvenidos al tercer ejercicio de la practica final"<<endl;
		
		cout<<"1. Insertar numero \n2. Listar \n3. Salir Elija una opcion: ";
		cin >> menu;
		switch(menu){
			case 1://Insertar
				cout << "Ingresa el numero"<<endl;
				cin >> numero;
				Insertar(numero, Pila);
				break;
			case 2://Listar
				Listar(Pila);
				break;
			case 3://Salir
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
//Metodo de insertar elementos a la Pila
void Insertar(int numero, int n[]){
	//Verificamos si la pila se encuentra llena
	if (cima == maximo - 1){
		cout << "La pila esta llena";
		maximo *= 2;//Duplicamos la capacidad cuando se llena
		cout << "Vuelva a intentarlo, ya la pila no esta vacia. Tiene " << maximo << " espacios disponibles";
	}//Agregamos un nuevo elemento
	else{
		cima++;
		n[cima] = numero;
		cout << "El elemento se inserto correctamente"<<endl;
	}
}
//Metodo que nos ayuda a filtrar
void Listar(int n[]){
	if (cima < 0){
		cout << "La pila esta vacia"<< endl;
	}
	else{
		for(int i = 0; i <= cima; i++){
			cout << n[i] << " -> " <<endl;
		}
	}
}
