#include <iostream>
#include <cstring>

using namespace std;

string getCadena();
int Longitud(string);
int Compara();
int BuscarSubCadena(string);

int main(){
	int menu, aux;
	string cadena;
    cout<<"Bienvenido a la Asignacion 2 de la Estudiante Nachely Sanchez"<<endl;
    do{
    	cout<<"Menu: \n 1. Longitud Cadena \n 2. Comparar campos \n 3. Buscar texto\n 4. Salir\n Seleccione una opcion: ";
    	cin>>menu;
    	
    	switch(menu){
    		case 1:
    			cadena = getCadena();
				
				aux = Longitud(cadena);
				
    			cout << "\nLa longitud de la cadena " << cadena << " es: " << aux << endl;
				
				break;
    		case 2:
    			aux = Compara();
    			if (aux == 0){
    				cout << "\nSon iguales";
				}
				else{
					cout << "\nNo son iguales";
				}
    			break;
    		case 3:
    			cadena = getCadena();
    			
				aux = BuscarSubCadena(cadena);
    			if (aux > 0){
    				cout << "\nLa subcadena se encuentra dentro de la cadena principal";
				}
				else{
					cout << "\nLa subcadena no se encuentra dentro de la cadena principal";
				}
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

string getCadena(){
	string cadena;
	cout << "Ingrese el texto a analizar: ";
	cin>> cadena;
	return cadena;
}

int Longitud(string cadena){
	return cadena.length();
}

int Compara(){
	string cadena1 ,cadena2;
	cout << "Ingrese el primer texto a comparar: ";
	cin >> cadena1;
	cout << "Ingrese el segundo texto a comparar: ";
	cin >> cadena2;
	
	return cadena1.compare(cadena2);
}

int BuscarSubCadena(string cadena){
	string cbuscar;
	cout << "Ingrese la subcadena que quiere buscar: ";
	cin >> cbuscar;
	cout<< string::npos;
	return cadena.find(cbuscar);
	
}
