/**
  * @file desplazar.cpp
  * @brief Fichero con el programa para desplazar n bits de una imagen hacia la derecha
  *
  **/
#include <imagen.h>
#include <cstdlib>  //para el atoi 
#include <iostream> //para el cerr

using namespace std;

int main(int argc, char *argv[]){
	Imagen img;
	int pos=0;
	
	if(argc!=4){
		cout << "\n ERROR. Número de parámetros incorrecto." << endl;
		cout << " USO: " << argv[0] << " [nº de bits] [imagen_entrada.pgm] [imagen_desplazada.pgm]" << endl;
	}else{
		if( img.LeerImagen(argv[2]) ){
			pos = atoi(argv[1]);
			if( img.Desplaza(pos) ){
				if( img.EscribirImagen(argv[3]) ){
					cout << "\n Imagen desplazada y guardada correctamente." << endl;
				}else
					cout << "\n ERROR: la imagen no se pudo guardar." << endl;
			}else
				cout <<  "\n ERROR: la imagen no se pudo desplazar." << endl;
		}else
			cout << "\n ERROR: la imagen no se pudo cargar." << endl;		
	}
		
	return 0;
}

/* Fin Fichero: desplazar.cpp */
