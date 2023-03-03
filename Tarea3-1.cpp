#include <iostream>

using namespace std;

struct Calificacion{
	int asistencia;
	int participacion;
	int tareas;
	int parcial;
	int trabajoFinal;
};

struct Fecha{
	int dia;
	int mes;
	int anio;
};

struct Datos_Personales{
	string nombre;
	string apellido;
	string matricula;
	int cantidadAsignaturas;
	Calificacion notas[5];
	Fecha nacimiento;
};


void Intercambiar(int&, int&);
void MetIntercambio(int [], int);
void MetQuicksort(int [], int, int);
void Punto1();
void Punto2();
void Punto3();

int main(){
	int menu, aux;
	string cadena;
    cout<<"Bienvenido a la Asignacion 3 de la Estudiante Nachely Sanchez"<<endl;
    do{
    	cout<<"Menu: \n 1. Ordenar 20 datos \n 2. Ordenar 100,000 datos \n 3. Trabajar con estructuras\n 4. Salir\n Seleccione una opcion: ";
    	cin>>menu;
    	
    	switch(menu){
    		case 1:
    			Punto1();
				break;
    		case 2:
    			Punto2();
    			break;
    		case 3:
    			Punto3();
    			break;
    		case 4:
    			break;
    		default:
    			cout<<"\nDebe de escoger una opcion dentro del menu...";
    			break;
		}
		system("pause");
		system("cls");
	}while(menu != 4);
	
    
    cout << "Gracias por su uso.\n\nEstudiante: Nachely Sanchez 100046842";
    return 0;
}

//Metodos de Ordenacion usados
void Intercambiar(int& x, int& y){
	int aux = x;
	x = y;
	y = aux;
}

void MetIntercambio(int a[], int n){
	int i, j;
	for(int i = 0; i < n - 1; i++){
		for(int j = i+1; j < n; j++){
			if (a[i] > a[j]){
				Intercambiar(a[i], a[j]);
			}
		}
	}
}

void MetQuicksort(int a[], int primero, int ultimo){
	int i = 0, j = 0, central = 0;
	int pivote = 0;
	
	central = (primero + ultimo) / 2;
	pivote = a[central];
	i = primero;
	j = ultimo;
	
	do{
		while(a[i] < pivote){
			i++;
		}
		while(a[j] > pivote){
			j--;
		}
		if(i <= j){
			Intercambiar(a[i], a[j]);
			i++;
			j--;
		}
	}while(i <= j);
	
	if (primero < j){
		MetQuicksort(a, primero, j);
	}
	if (i < ultimo){
		MetQuicksort(a, i, ultimo);
	}
}

//Punto 1: Elabora un programa que almacene en un vector 20 datos y Ordenar dicho vector
void Punto1(){
	int array[20], total = 20;
	for(int i = 0; i < total; i++){
		cout<<"Ingrese el elemento " << i << ": ";
		cin>>array[i];
	}
	
	cout << "Este es el arreglo antes de ser ordenado" << endl;
	
	for(int i = 0; i < total; i++){
		cout << array[i] << endl;
	}
	system("pause");
	
	MetIntercambio(array, total);
	system("cls");
	
	cout << "Este es el arreglo luego de ser ordenado" << endl;
	for(int i = 0; i < total; i++){
		cout << array[i] << endl;
	}
}

//Punto 2: Elabora un programa que almacene en un vector 100,000 datos  y ordenar dicho vector. Justificar el método de ordenación utilizado.
void Punto2(){
	int array[100000], total = 100000;
	for(int i = 0; i < total; i++){
		cout<<"Ingrese el elemento " << i << ": ";
		cin>>array[i];
	}
	
	cout << "Este es el arreglo antes de ser ordenado" << endl;
	
	for(int i = 0; i < total; i++){
		cout << array[i] << endl;
	}
	system("pause");
	
	MetQuicksort(array, 0, total-1);
	system("cls");
	
	cout << "Este es el arreglo luego de ser ordenado" << endl;
	for(int i = 0; i < total; i++){
		cout << array[i] << endl;
	}
}

//Punto 3: Elboara una estructura llamada datos_personales (Nombre,Apellido,Matricula, Calificacion notas, Fecha Nacimiento), 
//asignar la estructra a estudiante y calcular el promedio obtenido de dicho estudiante.
void Punto3(){
	float promedio;
	
	cout << "Es tiempo de registrar un estudiante" << endl;
	Datos_Personales estudiante;
	cout <<"Nombre: " << endl;
	cin >> estudiante.nombre; 
	cout << "Apellido: " << endl;;
	cin >> estudiante.apellido;
	cout << "Matricula: " <<endl;
	cin >> estudiante.matricula;
	cout << "Fecha de nacimiento" << endl;
	cout << "Dia: ";
	cin >> estudiante.nacimiento.dia;
	cout << "Mes: ";
	cin >> estudiante.nacimiento.mes;
	cout << "Anio: ";
	cin >> estudiante.nacimiento.anio;
	
	cout << "---------------------------------------------"<<endl;
	
	cout << "Calificaciones: "<< endl;
	cout << "Ingrese la cantidad de asignaturas: ";
	cin >> estudiante.cantidadAsignaturas;
	
	float notas[estudiante.cantidadAsignaturas];
	for(int i = 0; i < estudiante.cantidadAsignaturas; i++){
		cout << "Calificacion " << i << ": "<< endl;
		cout << "Asistencia: [0-10] ";
		cin >> estudiante.notas[i].asistencia;
		cout << "Participacion: [0-5]";
		cin >> estudiante.notas[i].participacion;
		cout << "Tareas: [0-40]";
		cin >> estudiante.notas[i].tareas;
		cout << "Parcial: [0-35]";
		cin >> estudiante.notas[i].parcial;
		cout << "Trabajo Final: [0-10]";
		cin >> estudiante.notas[i].trabajoFinal;
		
		
		notas[i] = estudiante.notas[i].asistencia + estudiante.notas[i].participacion + estudiante.notas[i].tareas +	estudiante.notas[i].parcial	+ estudiante.notas[i].trabajoFinal;
		promedio += notas[i];
	}
	
	system("cls");
	
	cout <<"Estudiante registrado: \n\n Nombre: " << estudiante.nombre << " " << estudiante.apellido << endl;
	cout << "Matricula: " << estudiante.matricula << endl;
	cout << "Calificaciones: "<< endl;
	for(int i =0; i < estudiante.cantidadAsignaturas; i++){
		
		cout << i+1 << ": " << notas[i] << endl;
	}
	cout << "Promedio: " << (promedio / estudiante.cantidadAsignaturas);
}



