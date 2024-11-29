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

void mostrar(tRegistro &aux){
	cout<<aux.codigo<<" - "<<aux.item<<"   -    "<< aux.valor << "euros"<< endl;
}

int main(){
	tRegistro registro; 
	fstream archivo; 
	archivo.open("bd.dat", ios::in | ios::binary); 
	archivo.read((char * ) &registro, SIZE); 
	int cuantos = archivo.gcount(); 
	while(cuantos == SIZE){
		mostrar(registro); 
		archivo.read((char * ) &registro, SIZE);
		cuantos = archivo.gcount(); 
	}
	
	archivo.close(); 
	
	return 0; 
}