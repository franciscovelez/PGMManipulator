/**
  * @file permutacion.h
  * @brief Fichero con las cabeceras de los métodos de la clase Permutacion que
  * se utiliza para el tratamiento de permutaciones.
  *      
  **/
#ifndef _PERMUTACION_H_
#define _PERMUTACION_H_

#include <fstream>  //para los flujos de ficheros
using namespace std;
/**
  * @brief Clase Permutacion, con los métodos necesarios para el tratamiento de permutaciones
  *
  **/  
class Permutacion{
	private:
    /**
      * @brief Vector que contiene los elementos de la permutación
      *
      **/  
		int *per;
    /**
      * @brief Nº de elementos de la permutación
      *
      **/  
		int n;
    /**
      * @brief Inicializa la clase reservando espacio en memoria para 
      * almacenar la permutación y estableciendo el número de elementos
      * Nota: Este método reserva memoria para el vector pero no lo rellena
      *
      * @param n_elem Número de elementos de la permutación
      *
      **/	
		void Crear_Vacio(int n_elem);
    /**
      * @brief Inicializa la clase reservando espacio en memoria para 
      * almacenar la permutación, rellenando el vector con los valores
      * ordenados desde 0 hasta n_elem y estableciendo el número de elementos
      *
      * @param n_elem Número de elementos de la permutación
      *
      **/			
		void Crear(int n_elem); 
    /**
      * @brief Libera la memoria usada por la permutación
      *
      **/
		void Destruir();
    /**
      * @brief Lee la cabecera de un fichero para saber si es del tipo
      * adecuado para leer una permutación
      *
      * @param f Flujo de entrada del fichero
      * @param n_elem Parámetro de salida con el número de elementos de la permutación
      * @param tipo Parámetro de salida con el tipo de fichero leido (binario o texto)
      *
      * @return Un código de error
      *
      * @retval true Si se ha leido correctamente la cabecera
      * @retval false Si no ha podido leer la cabecera
      *
      **/		
		bool Leer_Cabecera(ifstream& f, int& n_elem, char& tipo);
	public:		
    /**
      * @brief Constructor por defecto y con parámetro. Crea el objeto
      * Permutacion con n elementos.
      *
      * @param n Número de elementos de la permutación (Por defecto 0)
      *             
      **/
		Permutacion(int n=0);
    /**
      * @brief Constructor con parámetro fichero, crea el objeto Permutacion
      * carga los datos desde el fichero pasado.      
      *
      * @param file[] Ruta y nombre del fichero con la permutación
      *             
      **/		
		Permutacion(const char file[]);
    /**
      * @brief Constructor de copia, crea un objeto Permutacion y copia
      * la Permutacion pasada por parámetro
      *
      * @param otro Objeto Permutacion del que se quiere crear una copia
      *  
      **/      
		Permutacion(const Permutacion & otro);
    /**
      * @brief Operador de asignación, copia la permutación de la derecha en 
      * la permutación de la izquierda
      *
      * @param otro Objeto Permutacion que se va a copiar
      *  
      **/    
		Permutacion & operator = (const Permutacion & otro);
		/**
		  * @brief Libera la memoria usada por la permutacion
		  *
		  **/   
		~Permutacion();
    /**
      * @brief Hace el negativo a una imagen
      *
      * @return Un código de error
      *
      * @retval true Si se ha realizado el negativo de la imagen correctamente
      * @retval false Si no se ha realizado el negativo de la imagen
      *
      **/
		void Desordenar();
    /**
      * @brief Lee una permutación cargada desde un fichero de disco
      *
      * @param file[] Ruta y nombre del fichero a cargar
      *
      * @return Un código de error
      *
      * @retval true Si se ha leido correctamente la permutación desde disco
      * @retval false Si no se ha podido leer la permutación desde disco
      *
      **/
		bool Leer_Permuta(const char file[]);
    /**
      * @brief Graba una permutación en un fichero de disco
      *
      * @param file[] Ruta y nombre del fichero a guardar
      * @param tipo Tipo del fichero (binario o texto)
      *
      * @return Un código de error
      *
      * @retval true Si se ha grabado correctamente la permutación en disco
      * @retval false Si no se ha podido grabar la permutación en disco
      *
      **/		
		bool Grabar_Permuta(const char file[], char tipo) const;
    /**
      * @brief Devuelve el elemento de la permutación en la posición pos
      *
      * @param pos Posición de la permutación a leer
      *
      * @return El valor obtenido
      * 
      * @retval -1 Si la posición que se quiere leer no es válida
      * @retval >=0 Si la posición es válidad (Valor de esa posición)
      * 
      **/				
		int Get_Elem(int pos) const;
    /**
      * @brief Devuelve el número de elementos de la permutación
      *
      * @return Un entero con el número de elementos
      * 
      **/				
		int Get_n() const;
};
#endif
