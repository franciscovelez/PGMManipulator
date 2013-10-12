/**
  * @file ocultar.cpp
  * @brief Fichero con el programa para ocultar un mensaje en una imagen
  *
  **/ 
#include <iostream>
#include <fstream>   //para usar EOF
#include <imagen.h>

using namespace std;

int main(int argc, char *argv[]){
	const int MAXMENSAJE = 125000;
	char  mensaje[MAXMENSAJE];	
	Imagen img;
	
	if(argc!=3){
		cerr << "\n ERROR. Número de parámetros incorrecto." << endl;
		cerr << " USO: " << argv[0] << " [imagen_entrada.pgm] [imagen_codificada.pgm]" << endl;
	} else {
		if( img.LeerImagen(argv[1]) ){
			cerr << "\n (Ctrl+D para finalizar)" << endl;
			cin.getline(mensaje, MAXMENSAJE, EOF);
			if( img.Ocultar(mensaje) ){
				if( img.EscribirImagen(argv[2]) )
					cerr << "\n Ocultando..." << endl;
				else
					cerr << "\n ERROR: No se pudo guardar la imagen en el disco." << endl;
			}else
				cerr << "\n ERROR: El mensaje es demasiado largo para insertarlo en la imagen." << endl;
		}else 
			cerr << "\n ERROR: la imagen no se pudo cargar." << endl;
	}
	
	return 0;	
}

/* Fin Fichero: ocultar.cpp */
