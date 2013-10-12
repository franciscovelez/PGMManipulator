#include <permutacion.h>
#include <fstream>  //para los flujos de ficheros
#include <cstring>  //para cadenas
#include <cstdlib>  //para el exit, rand
#include <iostream> //para el cerr

using namespace std;
/***********************************************************/
/******************* Métodos Privados **********************/
void Permutacion :: Crear_Vacio(int n_elem){
	if(n_elem>0){
		Destruir(); //Si el objeto ya está creado pero estamos cambiando el nº
								//de elementos, no tenemos piedad, destruimos
		per = new (nothrow) int [n_elem];
		if(!per){
			cerr << "\n Error: No hay memoria disponible." << endl;
			exit(1);
		}
		
		n = n_elem;
	}else{
		n 	= 0;
		per = 0;
	}	
}
/***********************************************************/
void Permutacion :: Crear(int n_elem){
	Crear_Vacio(n_elem);
	for(int i=0; i<n; i++)
		per[i] = i;		
}
/***********************************************************/
void Permutacion :: Destruir(){
	if(per!=0)
		delete [] per;	
}
/***********************************************************/
bool Permutacion :: Leer_Cabecera (ifstream& f, int& n_elem, char& tipo){
	char tmp[9];
	bool exito = false;
	tipo = 'X'; //El valor 'X' es para el tipo desconocido
	n_elem = 0;

	f.getline(tmp, 9, ' ');

	if(strcmp(tmp, "MP-PER-T")==0){
		tipo = 'T';
	}else{
		if(strcmp(tmp, "MP-PER-B")==0)
			tipo = 'B';
	}
	
	if(tipo == 'B' || tipo == 'T'){
		f >> n_elem;
		f.get(); //extraemos el separador que queda tras >>
		exito = true;
	}
	
	return exito;
}
/***********************************************************/
/************* Constructores / Destructor ******************/
Permutacion :: Permutacion(int n_elem){
	per=0;
	Crear(n_elem);
}
/***********************************************************/
Permutacion :: Permutacion(const char file[]){
	per=0;
  Leer_Permuta(file);
}
/***********************************************************/
Permutacion :: Permutacion(const Permutacion & otro){
	per=0;
	
	Crear_Vacio(otro.n);
	//n = y.n;
	for(int i=0; i<otro.n; i++)
		per[i] = otro.per[i];
}
/***********************************************************/
Permutacion :: ~Permutacion(){
	Destruir();
}
/***********************************************************/
Permutacion & Permutacion :: operator = (const Permutacion & otro){
  if(this != &otro){
    Crear_Vacio(otro.n);
    
    for(int i=0; i<otro.n; i++)
      per[i] = otro.per[i];
  }
  
  return(*this);    
}
/***********************************************************/
/******************* Métodos Públicos **********************/
void Permutacion :: Desordenar(){
	int x;
	int tmp;
	
	srand(time(NULL)); //Plantamos semilla

	for(int i=0; i<n; i++){
		x = rand() % n;
		tmp 	 = per[x];
		per[x] = per[i];
		per[i] = tmp;
	}
}
/***********************************************************/
bool Permutacion :: Leer_Permuta(const char file[]){
	bool exito = false;
	int n_elem, x;
	char tipo;
	ifstream f(file);
	
  if(f.good()){		  	
  	exito = Leer_Cabecera(f, n_elem, tipo);
  	if(n_elem!=n && tipo != 'X') 
  		Crear_Vacio(n_elem);
  		
  	switch(tipo){
			case 'T': 
					exito = true;
					for(int i=0; i<n && f >> x; i++){
							per[i] = x;
						f.get(); //extraemos el separador que queda tras >>
					}							
					//Si no puede leer se sale del bucle entonces
					//comprobamos si el último dato es final de fichero o error
					if(f.bad() || f.fail())
						exito = false;

					break;
			case 'B': 
					f.read(reinterpret_cast<char *>(per), n*sizeof(int));
					if(!f.bad() && !f.fail())
						exito = true;
					break;
		}
    
    f.close();
  }
	
	return exito;
	
}
/***********************************************************/
bool Permutacion :: Grabar_Permuta(const char file[], char tipo) const{
	bool exito = false;
	ofstream f;
		
	tipo = toupper(tipo);
	
	switch(tipo){ 
		case 'T': 
				f.open(file);
				if(f.good()){
					f << "MP-PER-T " << n << endl;
					for(int i=0; i<n; i++)
						f << per[i] << endl;
					
					if(!f.bad())
						exito = true;
					
					f.close(); 
				}				
				break;
		case 'B': 
				f.open(file,ios::binary);
				if(f.good()){
					f << "MP-PER-B " << n << endl;
					f.write(reinterpret_cast<char *>(per), n*sizeof(int));
					
					if(!f.bad())
						exito = true;
					
					f.close(); 
				}
				break;
		}
		
	return exito;
}
/***********************************************************/
int Permutacion :: Get_Elem(int pos) const{
	if(pos >=0 && pos <n)
		return per[pos];
	else
		return -1;
}
/***********************************************************/
int Permutacion :: Get_n() const{
	return n;
}
