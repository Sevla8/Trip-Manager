/******************************************************************************
                           InerfaceUtilisateur  -  description
                             -------------------
début       : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail      : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//Réalisation de la classe <InerfaceUtilisateur> (fichier InerfaceUtilisateur.cpp)

//--------------------------------------------------------------------- INCLUDE

//------------------------------------------------------------- Include système
using namespace std;
#include "InterfaceUtilisateur.h"
#include <iostream>
#include <cstring>

//----------------------------------------------------------- Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------------ Constantes

//---------------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Méthodes publiques
void InterfaceUtilisateur::Bienvenue()
// Algorithme :
//		Aucun.
{
	cout << "Bienvenue !" << endl;
} //----- Fin de Bienvenue

void InterfaceUtilisateur::EnoncerOptions()
// Algorithme :
//		Aucun.
{
	cout << "<0> Quitter" << endl;
	cout << "<1> Ajouter un trajet dans le catalogue" << endl;
	cout << "<2> Afficher les trajets du catalogue" << endl;
	cout << "<3> Rechercher un parcours" << endl;
	cout << "-> ";
} //----- Fin de EnoncerOptions

void InterfaceUtilisateur::Quitter()
// Algorithme :
//		Aucun.
{
	cout << "Au revoir !" << endl;
} //----- Fin de Quitter

void InterfaceUtilisateur::AjouterTrajet(Catalogue& catalogue)
// Algorithme :
//		Aucun.
{
	cout << "Veuillez renseigner les villes de départ et d'arrivée, le moyen de transport puis ';' pour valider le trajet ou '+' pour ajouter une étape à celui-ci." << endl;
	cout << "Ajout de trajet:" << endl;

	TrajetSimple* simple = lectureTrajetSimple();

	char in[BUFFER_SIZE] = {'\0'};
	cin >> in;
	while (strcmp(in, ";") && strcmp(in, "+")) {
		cout << "Veuillez taper ';' pour valider le trajet ou '+' pour ajouter une étape à celui-ci." << endl;
		cin >> in;
	}
	if (!strcmp(in, ";")) {
		catalogue.Ajouter(simple);
		cout << "Trajet ajouté !" << endl;
		return;
	}

	TrajetCompose* compose = new TrajetCompose();
	compose->Ajouter(simple);
	do {
		if (!strcmp(in, "+")) {
			TrajetSimple* simple = lectureTrajetSimple();
			compose->Ajouter(simple);
		}
		else {
			cout << "Veuillez taper ';' pour valider le trajet ou '+' pour ajouter une étape à celui-ci." << endl;
		}
		cin >> in;
	} while (strcmp(in, ";"));
	catalogue.Ajouter(compose);
	cout << "Trajet ajouté !" << endl;
} //----- Fin de AjouterTrajet

void InterfaceUtilisateur::AfficherCatalogue(const Catalogue& catalogue)
// Algorithme :
//		Aucun.
{
	cout << "Affichage catalogue:" << endl << endl;
	catalogue.Afficher();
	cout << endl << endl;
} //----- Fin de AfficherCatalogue

void InterfaceUtilisateur::RechercherTrajet(const Catalogue& catalogue)
// Algorithme :
//		Aucun.
{
	cout << "Veuillez renseigner les villes de départ et d'arrivée." << endl;
	cout << "Recherche de parcours:" << endl;
	cout << "	Ville de départ: ";
	char depart[BUFFER_SIZE];
	cin >> depart;
	cout << "	Ville d'arrivée: ";
	char arrivee[BUFFER_SIZE];
	cin >> arrivee;
	cout << "<1> Recherche simple" << endl;
	cout << "<2> Recherche avancée" << endl;
	char versionRecherche[BUFFER_SIZE];
	cin >> versionRecherche;
	while (strcmp(versionRecherche, "1") && strcmp(versionRecherche, "2")) {
		cout << "Veuillez choisir entre '1' et '2' svp." << endl;
		cin >> versionRecherche;
	}

	cout << "Affichage catalogue résultat:" << endl << endl;

	Catalogue* resultat = !strcmp(versionRecherche, "1") ? catalogue.TrouverTrajetsVersionSimple(depart, arrivee) : catalogue.TrouverTrajetsVersionAvancee(depart, arrivee);
	resultat->Afficher();
	delete resultat;

	cout << endl << endl;
} //----- Fin de RechercherTrajet

void InterfaceUtilisateur::RepeterOptions()
// Algorithme :
//		Aucun.
{
	cout << "Svp, veuillez choisir une option entre 0, 1, 2, 3." << endl;
} //----- Fin de RepeterOptions

//------------------------------------------------------ Surcharge d'opérateurs

//------------------------------------------------- Constructeurs - destructeur

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------ Méthodes privées
TrajetSimple* InterfaceUtilisateur::lectureTrajetSimple()
// Algorithme :
//		Aucun.
{
	cout << "	Ville de départ: ";
	char depart[BUFFER_SIZE];
	cin >> depart;

	cout << "	Ville d'arrivée: ";
	char arrivee[BUFFER_SIZE];
	cin >> arrivee;

	cout << "	Moyen de transport: ";
	char transport[BUFFER_SIZE];
	cin >> transport;

	return new TrajetSimple(depart, arrivee, transport);
} //----- Fin de lectureTrajetSimple
