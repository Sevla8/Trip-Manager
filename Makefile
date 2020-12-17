CC = g++
CFLAGS = -ansi -pedantic -Wall -std=c++11
LDFLAGS =
SOURCE = src/
BINARY = bin/
SRC = $(wildcard $(SOURCE)*.cpp)
HDR = $(wildcard $(SOURCE)*.h)
OBJ = $(patsubst $(SOURCE)%.cpp,$(BINARY)%.o, $(SRC))
EXEC = tp2

all: $(EXEC)

tp2: $(OBJ) # édition des liens
	$(CC) -o $@ $^ $(LDFLAGS)

$(BINARY)%.o: $(SOURCE)%.cpp $(SOURCE)%.h # compilations
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINARY)main.o: $(SOURCE)main.cpp $(SOURCE)Catalogue.h $(SOURCE)InterfaceUtilisateur.h # compilation
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINARY)Catalogue.o: $(SOURCE)Catalogue.cpp $(SOURCE)Catalogue.h $(SOURCE)ListeTrajet.h $(SOURCE)Trajet.h # compilation
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINARY)Cellule.o: $(SOURCE)Cellule.cpp $(SOURCE)Cellule.h $(SOURCE)Trajet.h # compilation
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINARY)InterfaceUtilisateur.o: $(SOURCE)InterfaceUtilisateur.cpp $(SOURCE)InterfaceUtilisateur.h $(SOURCE)TrajetSimple.h $(SOURCE)Catalogue.h $(SOURCE)TrajetCompose.h # compilation
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINARY)ListeTrajet.o: $(SOURCE)ListeTrajet.cpp $(SOURCE)ListeTrajet.h $(SOURCE)Cellule.h $(SOURCE)TrajetCompose.h # compilation
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINARY)TrajetCompose.o: $(SOURCE)TrajetCompose.cpp $(SOURCE)TrajetCompose.h $(SOURCE)ListeTrajet.h # compilation
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm $(BINARY)*

mrproper:
	rm $(BINARY)* $(EXEC)

# https://gl.developpez.com/tutoriel/outil/makefile/
