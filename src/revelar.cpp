/**
  * @file revelar.cpp
  * @brief Fichero con el programa para revelar un mensaje desde una imagen
  * 
  **/
#include <iostream>
#include <imagen.h>
using namespace std;

int main(int argc, char *argv[]){
	const int MAXMENSAJE = 125000;
	char  mensaje[MAXMENSAJE];	
	Imagen img;
	
	if(argc!=2){
		cerr << "\n ERROR. Número de parámetros incorrecto." << endl;
		cerr << " USO: " << argv[0] << " [imagen_codificada.pgm]" << endl;
	} else {
		if( img.LeerImagen(argv[1]) ){
			if( img.Revelar(mensaje) ){
				cerr << "\n Revelando..." << endl;
				cout << mensaje << endl;
			}else
				cout << "\n No hay ningún mensaje para revelar." << endl;
		}else 
			cout << "\n ERROR: la imagen no se pudo cargar." << endl;
	}
	
	return 0;	
}

/* Fin Fichero: revelar.cpp */
