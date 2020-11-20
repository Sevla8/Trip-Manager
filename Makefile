CC = g++
CFLAGS = -ansi -pedantic -Wall -std=c++11
LDFLAGS =
SOURCE = src/
BINARY = bin/
SRC = $(wildcard $(SOURCE)*.cpp)
HDR = $(wildcard $(SOURCE)*.h)
OBJ = $(patsubst $(SOURCE)%.cpp,$(BINARY)%.o, $(SRC))
EXEC = $(BINARY)tp2

all: $(EXEC)

$(BINARY)tp2: $(OBJ) # édition des liens
	$(CC) -o $@ $^ $(LDFLAGS)

$(BINARY)%.o: $(SOURCE)%.cpp $(SOURCE)%.h # compilations
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf *.o $(EXEC)

# all : ensemble des executables
# clean : supprime les fichiers intermediaires
# mrproper : supprime tout ce qui peut etre regenere

# cible: dependance
# 	commande

# $@ : nom de la cible
# $< : nom de la premiere dependance
# $^ : liste des dependances
# $? : liste des dependances plus recentes que la cible
# $* : nom du fichier sans suffixe

# https://gl.developpez.com/tutoriel/outil/makefile/
