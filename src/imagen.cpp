/**
  * @file imagen.cpp
  * @brief Fichero con la representación de la clase Imagen.
  *
  * Esta representación consiste en un vector dinámico de punteros a las
  * filas. El primer puntero apunta a un vector con toda la información
  * de la imagen en filas consecutivas (todas las filas están en un vector
  * una detrás de otra). El resto de punteros apunta al comienzo de
  * cada fila. Se usan dos enteros con el número de filas y columnas.
  *   
  * Además permite realizar operaciones con imágenes PGM. 
  *           
  **/
#include <imagen.h>
#include <imagenES.h>
#include <cstring>
#include <cstdlib>  //para el exit
#include <iostream> //para el cerr
using namespace std;
/***********************************************************/
/******************* Métodos Privados **********************/
void Imagen :: Crear(int f, int c){

	if(f>0 && c>0){
		fil = f;
		col = c;
		
		//reservamos una fila más porque en la primera (la posición 0) va
		//el vector y a partir de la posición 1 empiezan las filas.
		img = new (nothrow) unsigned char * [fil+1];
		if(!img){
			cerr << "\n Error: No hay memoria disponible." << endl;
			exit(1);
		}
	
		img[0] = new (nothrow) unsigned char [fil*col];
		if(!img[0]){
			cerr << "\n Error: No hay memoria disponible." << endl;
			exit(1);		
		}
		//Colocamos cada puntero al inicio de las filas
		for(int i=0; i<fil; i++){
			img[i+1] = &img[0][i*col];
		}
		
	}else{
		fil = 0;
		col = 0;
		img = 0;
	}
}
/***********************************************************/
void Imagen :: Destruir(){
	if(img!=0){
		if(img[0]!=0)
			delete [] img[0];

		delete [] img;
		
	}	
}
/***********************************************************/
/************* Constructores / Destructor ******************/
Imagen :: Imagen(){
	fil = 0;
	col = 0;
	img = 0;
}
/***********************************************************/
Imagen :: Imagen(const char file[]){
	int fil_tmp, col_tmp;
	TipoImagen tipo_img;

	//Comprobamos si el fichero introducido existe y es del tipo correcto
	tipo_img = LeerTipoImagen(file, fil_tmp, col_tmp);
	//Si LeerTipoImagen() falla fil_tmp y col_tmp = 0
	Crear(fil_tmp, col_tmp);
	if(tipo_img == IMG_PGM)
		LeerImagen(file);
	
}
Imagen :: Imagen(const Imagen & otro){
	img = 0;
	int tam = otro.fil*otro.col;

	Crear(otro.fil, otro.col);
	for(int i=0; i<tam; i++)
		img[0][i] = otro.img[0][i];
}
Imagen & Imagen :: operator = (const Imagen & otro){
	int tam = otro.fil*otro.col;
	
	if(this != &otro){
		Destruir();
    Crear(otro.fil, otro.col);
    for(int i=0; i<tam; i++)
      img[0][i] = otro.img[0][i];
  }
  
  return(*this);   
}
/***********************************************************/
Imagen :: ~Imagen(){
		Destruir();
}	
/***********************************************************/
/******************* Métodos Públicos **********************/
int Imagen :: Filas() const{
	return fil;
}
/***********************************************************/
int Imagen :: Columnas() const{
	return col;
}
/***********************************************************/
void Imagen :: Set(int i, int j, unsigned char v){
	//hay que poner i+1 porque la fila 0 contiene el vector completo
	//y los punteros comienzan en la 1
	img[i+1][j] = v; 
}
/***********************************************************/
unsigned char Imagen :: Get(int i, int j) const{
	//hay que poner i+1 porque la fila 0 contiene el vector completo
	//y los punteros comienzan en la 1
	return(img[i+1][j]);
}
/***********************************************************/
bool Imagen :: LeerImagen(const char file[]){
	int fil_tmp, col_tmp;
	bool exito = false;
	TipoImagen tipo_img;
	
	//Comprobamos el tipo de fichero
	tipo_img = LeerTipoImagen(file, fil_tmp, col_tmp);
	if(tipo_img == IMG_PGM){ //es el que queremos
		if(fil_tmp == fil && col_tmp == col && img!=0){ 
			//El objeto Imagen ya está inicializado correctamente
			exito  = LeerImagenPGM(file, fil_tmp, col_tmp, img[0]);
		}else{
			//Algún parámetro del objeto Imagen no coincide con el leído
			//destruimos y creamos el objeto de nuevo
			Destruir();
			Crear(fil_tmp, col_tmp);
			exito  = LeerImagenPGM(file, fil, col, img[0]);
		}
	}		
				
	return exito;
}
/***********************************************************/ 
bool Imagen :: EscribirImagen(const char file[]) const {
	bool exito = true;
	unsigned char *buffer;

	buffer = new (nothrow) unsigned char[fil*col];
	if(!buffer){
		cerr << "\n Error: No hay memoria disponible para completar la operación." << endl;
		exit(1);
	}
	
	//Pasamos la imagen a un vector auxiliar yendo de fila en fila,
	//así si hemos desordenado las filas de la imagen, éstas se guardan
	//en el orden que tienen que seguir
	for(int i=0; i<fil; i++)
		for(int j=0; j<col; j++)
			buffer[i*col+j] = img[i+1][j];
		
	
	exito = EscribirImagenPGM(file, buffer, fil, col);
	
	delete [] buffer;
	
	return exito;
}
/**************************************************************/
bool Imagen :: Ocultar(const char mensaje[]){
	int pos;
  bool exito = false;
	unsigned int  tam;
	unsigned char filtro, letra;

	tam = fil*col;
	if( strlen(mensaje)*BYTE < tam ){
		for(unsigned int i=0; i<=strlen(mensaje); i++){
			filtro = 128;

			for(int j=0; j<BYTE; j++){
				pos = BYTE*i+j;
				letra = mensaje[i] & filtro;
				letra = letra >> (BYTE-1-j);

				img[0][pos] = img[0][pos] >> 1;
				img[0][pos] = img[0][pos] << 1;
				img[0][pos] = img[0][pos] | letra;
				filtro = filtro >> 1;
			}
		}
		exito = true;
	}

	return exito;
}
/********************************************************************/
bool Imagen :: Revelar(char mensaje[]) const{
	int pos,  i=-1; //iniciamos en -1 para que a la primera 
                  //vuelta sea 0 y evitar usar mensaje[i-1]
  bool exito= false; 
	unsigned char filtro = 1, bit;

	do{
		i++;

		for(int j=0; j<BYTE; j++){
			pos = BYTE*i+j;
			bit = img[0][pos] & filtro;
			bit = bit << (7-j);
			mensaje[i] = mensaje[i] | bit;
		}

	}while(mensaje[i]!='\0');

	//Si el mensaje recuperado está vacío, devolvemos false;
	if(strlen(mensaje)>0)
		exito = true;
	
	return exito;

}
/***********************************************************/
bool Imagen :: Desplaza(int n_pos){
	unsigned char pixel;
	bool exito = false;

	if(n_pos >= 0){

		for(int i=0; i<fil; i++){
			for(int j=0; j<col; j++){
				pixel = Get(i,j);
				pixel = pixel << n_pos;
				Set(i,j,pixel);
			}
		}
		
		exito = true;	
	}
		
	return exito;
}
/***********************************************************/
bool Imagen :: Negativo() {
	unsigned char pixel;
	
	for(int i=0; i<fil; i++){
		for(int j=0; j<col; j++){
			pixel = Get(i,j);
			pixel = 255 - pixel;
			Set(i,j,pixel);					
		}
	}
	
	//Se mantiene el bool devuelto por coherencia con el resto
	//de métodos de manipulación de imagen.
	//Cuando se añada algún control, se podrá usar sin problemas
	return true; 
}
/***********************************************************/
bool Imagen :: Asignar_A_Fila(int fil1, int fil2){
	bool exito = false;

	if(fil1>=0 && fil1<fil && fil2>=0 && fil2<fil){
		img[fil2+1] = &img[0][fil1*col];
		exito = true;
	}
	
	return exito;
}

/* Fin Fichero: imagen.cpp */
