#include <iostream>
#include <fstream>

using namespace std; 

const int MAX = 80; 

struct tRegistro{
	int codigo; 
	char item[MAX]; 
	double valor; 
};

int SIZE = sizeof(tRegistro); 

void mostrar(tRegistro &aux) {
    cout << aux.codigo << " - " << aux.item << " - " << aux.valor << " euros" << endl;
}



int main(){
	tRegistro registro; 
	fstream archivo; 
	archivo.open("bd.dat", ios::in | ios::out | ios::binary); 
	archivo.seekg(0, ios::end); 
	int pos = archivo.tellg(); 
	int numReg = pos / SIZE ; 
	cout << "Numeros de registros : " << numReg << endl; 
	int num; 
	cout << "Registro numero?: ";
	cin >> num; 
	 
	if((num > 0) && (num <= numReg)){
		archivo.seekg((num - 1) * SIZE, ios::beg); 
		archivo.read((char *) &registro, SIZE); 
		mostrar(registro); 
		cout << endl << "Cambiar nombre [S/N]? ";
		char c; 
		cin.sync(); 
		cin >> c; 
		if((c == 's') || c == 'S'){
			cout << "Nombre: "; 
			cin.sync(); 
			cin.getline(registro.item, 80); 
		}
		cout << endl << "Cambiar precio [S/N] ?";
		cin.sync(); 
		cin >> c; 
		if((c == 's') || (c == 'S')){
			cout << "Precio: "; 
			cin >> registro.valor;
		}
		archivo.seekg((num - 1) * SIZE, ios::beg); 
		archivo.write((char *) &registro, SIZE); 
		cout << endl << "Registro actualizado: "<< endl;
		archivo.read((char *) &registro, SIZE); 
		mostrar(registro); 
	}
	
	
	archivo.close();
	
	
	return 0; 
}