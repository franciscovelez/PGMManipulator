/**
  * @file negativo.cpp
  * @brief Fichero con el programa para hacer negativa una imagen
  *
  **/ 
#include <iostream>
#include <imagen.h>

using namespace std;

int main(int argc, char *argv[]){
	Imagen img;
	
	if(argc!=3){
		cout << "\n ERROR. Número de parámetros incorrecto." << endl;
		cout << " USO: " << argv[0] << " [imagen_entrada.pgm] [imagen_invertida.pgm]" << endl;
	}else{
		if( img.LeerImagen(argv[1]) ){
			if( img.Negativo() ){
				if( img.EscribirImagen(argv[2]) ){
					cout << "\n Imagen guardada correctamente." << endl;
				}else
					cout << "\n ERROR: la imagen no se pudo guardar." << endl;
			}else
				cout <<  "\n ERROR: no se pudo obtener el negativo de la imagen." << endl;
		}else 
			cout << "\n ERROR: la imagen no se pudo cargar." << endl;
	}
		
	return 0;
}

/* Fin Fichero: negativo.cpp */
