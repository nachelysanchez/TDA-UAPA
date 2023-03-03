#include <iostream>

using namespace std;

struct Marcas{
	int id;
	string dato;
};

int main(){
	Marcas marcas[9];
	
	for(int i = 0; i < 9; i++){
		marcas[i].id = i;
		cin >> marcas[i].dato;
	}
	
	for(int i = 0; i < 9; i++){
		cout << marcas[i].id << " " << marcas[i].dato << endl;
	}
	
	return 0;
}
