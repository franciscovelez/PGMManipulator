/**
  * @file permutar.cpp
  * @brief Fichero con el programa para permutar una imagen o para restaurarla
  *
  **/ 
#include <iostream>
#include <permutacion.h>
#include <imagen.h>
#include <cstring>  //para cadenas

using namespace std;

int main(int argc, char *argv[]){
	Permutacion perm;
	Imagen img;	
	
	if(argc==4 || argc==5){
		if(argc==4){
			if(perm.Leer_Permuta(argv[2])){
				if(img.LeerImagen(argv[1])){
					if(perm.Get_n() == img.Filas()){
						for(int i=0; i<img.Filas(); i++)			
							img.Asignar_A_Fila(i,perm.Get_Elem(i));
              
						if(img.EscribirImagen(argv[3]))
							cout << "\n Imagen guardada correctamente." << endl;
						else
							cout << "\n ERROR: No se pudo guardar la imagen en disco." << endl;						
					}else
						cout << "\n ERROR: El nº de líneas de la imagen no coincide con el del fichero de permutaciones." << endl;
				}else
					cout << "\n ERROR: No se pudo leer la imagen desde disco." << endl;
			}else
				cout << "\n ERROR: No se pudo leer la permutación desde disco." << endl;
		}
		if(argc==5){
			if(strcmp(argv[1],"-d")==0){
				if(perm.Leer_Permuta(argv[3])){
					if(img.LeerImagen(argv[2])){
						if(perm.Get_n() == img.Filas()){
							for(int i=0; i<img.Filas(); i++)
								img.Asignar_A_Fila(perm.Get_Elem(i),i);

							if(img.EscribirImagen(argv[4]))
								cout << "\n Imagen guardada correctamente." << endl;
							else
								cout << "\n ERROR: No se pudo guardar la imagen en disco." << endl;						
						}else
							cout << "\n ERROR: El nº de líneas de la imagen no coincide con el del fichero de permutaciones." << endl;
					}else
						cout << "\n ERROR: No se pudo leer la imagen desde disco." << endl;
				}else
					cout << "\n ERROR: No se pudo leer la permutación desde disco." << endl;
			}else
				cout << "\n ERROR: No se detectó el parámetro -d." << endl;
		}			

	}else{
		cout << "\n ERROR. Número de parámetros incorrecto." << endl;
		cout << " USO:" << endl;
		cout << " Aplicar permutación: "  << argv[0] << " [imagen.pgm] [permutacion.per] [imagen_permutada.pgm]" << endl;
		cout << " Deshacer permutación: " << argv[0] << " -d [imagen_permutada.pgm] [permutacion.per] [imagen.pgm]" << endl;		
	}
	return 0;
}

/* Fin Fichero: permutar.cpp */
