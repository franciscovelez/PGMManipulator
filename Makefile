BIN = bin/
SRC = src/
INC = include/
OBJ = obj/
LIB = lib/
CXX = g++
CPPFLAGS = -Wall -I$(INC) -c -g

todo: $(BIN)ocultar $(BIN)revelar $(BIN)negativo $(BIN)desplazar $(BIN)generar $(BIN)permutar $(BIN)temp

# ************ Compilación de los programas ************
$(BIN)ocultar: 		$(OBJ)ocultar.o $(LIB)libimagen.a
	$(CXX) -o $@ $(OBJ)ocultar.o -L./$(LIB) -limagen
$(BIN)revelar: 		$(OBJ)revelar.o $(LIB)libimagen.a
	$(CXX) -o $@ $(OBJ)revelar.o -L./$(LIB) -limagen
$(BIN)negativo:		$(OBJ)negativo.o $(LIB)libimagen.a
	$(CXX) -o $@ $(OBJ)negativo.o -L./$(LIB) -limagen 
$(BIN)desplazar: 	$(OBJ)desplazar.o $(LIB)libimagen.a
	$(CXX) -o $@ $(OBJ)desplazar.o -L./$(LIB) -limagen
$(BIN)generar: 	$(OBJ)generar.o $(LIB)libimagen.a
	$(CXX) -o $@ $(OBJ)generar.o -L./$(LIB) -limagen
$(BIN)permutar: 	$(OBJ)permutar.o $(LIB)libimagen.a
	$(CXX) -o $@ $(OBJ)permutar.o -L./$(LIB) -limagen
$(BIN)temp: 	$(OBJ)temp.o $(LIB)libimagen.a
	$(CXX) -o $@ $(OBJ)temp.o -L./$(LIB) -limagen
# ************ Compilación de módulos ************
$(OBJ)imagen.o: $(SRC)imagen.cpp $(INC)imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)imagen.cpp -o $@
$(OBJ)permutacion.o: $(SRC)permutacion.cpp $(INC)permutacion.h
	$(CXX) $(CPPFLAGS) $(SRC)permutacion.cpp -o $@
$(OBJ)ocultar.o:		$(SRC)imagen.cpp $(INC)imagen.h $(SRC)ocultar.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)ocultar.cpp -o $@
$(OBJ)revelar.o:		$(SRC)imagen.cpp $(INC)imagen.h $(SRC)revelar.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)revelar.cpp -o $@	
$(OBJ)negativo.o:		$(SRC)imagen.cpp $(INC)imagen.h $(SRC)negativo.cpp
	$(CXX) $(CPPFLAGS) $(SRC)negativo.cpp -o $@
$(OBJ)desplazar.o: 	$(SRC)imagen.cpp $(INC)imagen.h $(SRC)desplazar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)desplazar.cpp -o $@
$(OBJ)generar.o: 	$(SRC)permutacion.cpp $(INC)permutacion.h $(SRC)generar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)generar.cpp -o $@
$(OBJ)permutar.o: 	$(SRC)permutacion.cpp $(INC)permutacion.h $(SRC)imagen.cpp $(INC)imagen.h $(SRC)permutar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)permutar.cpp -o $@
$(OBJ)temp.o: 	$(SRC)permutacion.cpp $(INC)permutacion.h $(SRC)temp.cpp
	$(CXX) $(CPPFLAGS) $(SRC)temp.cpp -o $@
#$(OBJ)transformar.o:	$(SRC)imagen.cpp $(SRC)transformar.cpp \
#						$(INC)imagen.h   $(INC)transformar.h
#	$(CXX) $(CPPFLAGS) $(SRC)transformar.cpp -o $@

$(OBJ)%.o: $(SRC)%.cpp
	$(CXX) $(CPPFLAGS) $< -o $@
# ************ Generación de biblioteca ******************
$(LIB)libimagen.a: $(OBJ)imagenES.o $(OBJ)imagen.o $(OBJ)permutacion.o
	ar -rvs $@ $^

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile
# ************ Limpieza ************
clean :
	-rm $(OBJ)* $(SRC)*~ $(INC)*~ $(LIB)* ./*~

mrproper : clean
	-rm $(BIN)* doc/html/*
