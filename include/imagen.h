/**
  * @file imagen.h
  * @brief Fichero con las cabeceras de los métodos de la clase Imagen que
  * se utiliza para el tratamiento de imágenes.
  *     
  **/
#ifndef _IMAGEN_H_
#define _IMAGEN_H_

/**
  * @brief Constante BYTE
  *
  * Es una constante con valor 8, que indica el nº de bits que tiene un Byte
  * para usarla en las funciones
  *
  **/
const int BYTE=8;
/**
  * @brief Clase Imagen, con los métodos necesarios para el tratamiento de imágenes
  *
  **/  
class Imagen{
	private:
    /**
      * @brief Nº de filas de la imagen
      *
      **/  
		int fil;
    /**
      * @brief Nº de columnas de la imagen
      *
      **/      
		int col;
    /**
      * @brief Vector con la información de los pixels de la imagen 
      *
      **/  
		unsigned char **img;
    /**
      * @brief Inicializa la clase reservando espacio en memoria para 
      * almacenar la imagen y estableciendo el valor de las filas y 
      * las columnas
      *
      * @param f Número de filas de la imagen
      * @param c Número de columnas de la imagen
      *
      **/	
		void Crear(int f, int c);
    /**
      * @brief Libera la memoria usada por la imagen
      *
      **/
		void Destruir();    
		
	public:
    /**
      * @brief Constructor por defecto, crea el objeto Imagen con 0 lineas
      *
      **/  
		Imagen();
    /**
      * @brief Constructor con parámetro fichero, crea el objeto Imagen y
      * carga la imagen pasada en el parámetro      
      *
      * @param file[] Ruta y nombre del fichero imagen
      *             
      **/
		Imagen(const char file[]);
     /**
      * @brief Constructor de copia, crea el objeto Imagen y copia la imagen
      * pasada por parámetro
      *
      * @param otro Objeto Imagen del que se quiere crear una copia
      *  
      **/   
		Imagen(const Imagen & otro);
    /**
      * @brief Operador de asignación, copia la imagen de la derecha en 
      * la imagen de la izquierda
      *
      * @param otro Objeto Imagen que se va a copiar
      *  
      **/
		Imagen & operator = (const Imagen & otro);  
    /**
      * @brief Libera la memoria usada por la imagen
      *
      **/
		~Imagen();
    /**
      * @brief Devuelve el número de filas
      *
      * @return Un entero con el número de filas
      *
      **/		
		int Filas() const;
    /**
      * @brief Devuelve el número de columnas
      *
      * @return Un entero con el número de columnas
      *
      **/		
		int Columnas() const;
    /**
      * @brief Almacena en la coordenada (i,j) de la imagen el valor de un pixel
      *
      * @param i Número de fila
      * @param j Número de columna
      * @param v Valor de un pixel
      *
      **/		
		void Set(int i, int j, unsigned char v);
    /**
      * @brief Devuelve el valor del pixel almacenado en la coordenada (i,j)
      *
      * @param i Número de fila
      * @param j Número de columna
      *
      * @return Valor de un pixel
      * 
      **/		
		unsigned char Get(int i, int j) const;
    /**
      * @brief Lee del disco el fichero y lo carga en memoria
      *
      * @param file[] Ruta y nombre del fichero que se va a cargar
      *
      * @return Un código de error
      *
      * @retval true Si se ha cargado correctamente la imagen
      * @retval false Si no se ha podido cargar la imagen
      *
      **/		
		bool LeerImagen(const char file[]);
    /**
      * @brief Guarda en disco la imagen con el nombre de file[]
      *
      * @param file[] Ruta y nombre del fichero que se va a guardar
      *
      * @return Un código de error
      *
      * @retval true Si se ha guardado correctamente la imagen
      * @retval false Si no se ha podido guardar la imagen
      *
      **/		
		bool EscribirImagen(const char file[]) const;		
    /**
      * @brief Oculta el mensaje pasado por parámetro en la imagen
      *
      * @param mensaje[] Cadena con el mensaje que se va a ocultar
      *
      * @return Un código de error
      *
      * @retval true Si se ha ocultado correctamente el mensaje
      * @retval false Si no se ha podido ocultar el mensaje
      *
      **/
		bool Ocultar(const char mensaje[]);
    /**
      * @brief Revela un mensaje oculto en la imagen
      *
      * @param mensaje[] Cadena con el mensaje que se va a ocultar
      *
      * @return Un código de error
      *
      * @retval true Si se ha revelado correctamente el mensaje
      * @retval false Si no se ha podido revelar el mensaje
      *
      **/
		bool Revelar(char mensaje[]) const;
    /**
      * @brief Desplaza el color de los pixeles n posiciones a la izquierda
      *
      * @param n_pos Número de posiciones a desplazar
      *
      * @return Un código de error
      *
      * @retval true Si se ha desplazado correctamente la imagen
      * @retval false Si no se ha podido desplazar la imagen
      *
      **/
		bool Desplaza(int n_pos);
    /**
      * @brief Hace el negativo a una imagen
      *
      * @return Un código de error
      *
      * @retval true Si se ha realizado el negativo de la imagen correctamente
      * @retval false Si no se ha realizado el negativo de la imagen
      *
      **/
		bool Negativo();
    /**
      * @brief Cambia una fila de posición. Nota: No hace intercambio de filas 
      *
      * @param fil1 Número de fila origen
      * @param fil2 Número de fila destino       
      *             
      * @return Un código de error
      *
      * @retval true Si se ha guardado correctamente la imagen
      * @retval false Si no se ha podido guardar la imagen
      *
      **/
		bool Asignar_A_Fila(int fil1, int fil2);
};

#endif

/* Fin Fichero: imagen.h */
