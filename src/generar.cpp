/**
  * @file generar.cpp
  * @brief Fichero con el programa para generar una permutación aleatoria de n elementos
  *
  **/
#include <iostream>
#include <cstdlib>  //para el atoi 
#include <permutacion.h>

using namespace std;

int main(int argc, char *argv[]){
	int n_elem;
	char tipo;
	
	if(argc!=4){
		cout << "\n ERROR. Número de parámetros incorrecto." << endl;
		cout << " USO: " << argv[0] << " [nº de elementos] [B | T] [fichero_permutado.per]" << endl;
	}else{
		n_elem = atoi(argv[1]);
		tipo   = toupper(argv[2][0]);
		if(n_elem>0){
			if(tipo == 'T' || tipo == 'B'){
				Permutacion perm(n_elem);	//ya hemos verificado los parámetros, creamos permutación
				perm.Desordenar();
        
				if(perm.Grabar_Permuta(argv[3], tipo))
					cout << "\n Permuta grabada en disco con éxito." << endl;
				else
					cout << "\n ERROR: La permuta no se pudo grabar en el disco." << endl;
			}else
				cout << "\n ERROR: El parámetro de codificación no es válido, debe escoger entre B o T." << endl;
		}else
			cout << "\n ERROR: El número de elementos tiene que ser mayor que 0." << endl;
	}
	return 0;
}

/* Fin Fichero: generar.cpp */
