/******************************************************************************
                           InterfaceUtilisateur  -  description
                             -------------------
début       : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail      : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//Interface de la classe <InterfaceUtilisateur> (fichier InterfaceUtilisateur.h)
#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

//-------------------------------------------------------- Interfaces utilisées

#include "Catalogue.h"
#include "TrajetSimple.h"

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Rôle de la classe <InterfaceUtilisateur>
//		Permet de gérer l'interface utilisateur.
//-----------------------------------------------------------------------------

class InterfaceUtilisateur {
	//------------------------------------------------------------------ PUBLIC
	public:
		//-------------------------------------------------- Méthodes publiques
		static void Bienvenue();
		// Mode d'emploi :
    	//		Affiche un message souhaitant la bienvenue.
    	// Contrat :
    	//		Aucun.

		static void EnoncerOptions();
		// Mode d'emploi :
    	//		Affiche un message énonçant les options.
    	// Contrat :
    	//		Aucun.

		static void Quitter();
		// Mode d'emploi :
    	//		Affiche un message signifiant à l'utilisateur
		//		qu'il a quitté l'interface.
    	// Contrat :
    	//		Aucun.

		static void AjouterTrajet(Catalogue& catalogue);
		// Mode d'emploi :
    	//		Affiche un message pour signifier à l'utilisateur
		//		comment renseigner un trajet.
    	// Contrat :
    	//		Aucun.

		static void AfficherCatalogue(const Catalogue& catalogue);
		// Mode d'emploi :
    	//		Affiche un message signifiant à l'utilisateur que
		//		le catalogue s'affiche et affiche le catalogue.
    	// Contrat :
    	//		Aucun.

		static void RechercherTrajet(const Catalogue& catalogue);
		// Mode d'emploi :
    	//		Affiche un message signifiant à l'utilisateur
		//		comment rechercher un trajet dans le catalogue et
		//		permet de rechercher un trajet dans le catalogue.
    	// Contrat :
    	//		Aucun.

		static void RepeterOptions();
		// Mode d'emploi :
    	//		Affiche un message signifiant à l'utilisateur
		//		qu'il doit choisir une option.
    	// Contrat :
    	//		Aucun.

	//-------------------------------------------------- Surcharge d'opérateurs

	//--------------------------------------------- Constructeurs - destructeur

	//------------------------------------------------------------------- PRIVE
	private:
		//---------------------------------------------------- Méthodes privées
		static TrajetSimple* lectureTrajetSimple();
		// Mode d'emploi :
    	//		Affiche un message demandant à l'utilisateur de renseigner
		//		un trajet simple et retourne l'adresse correspondante au
		//		trajet simple créé.
    	// Contrat :
    	//		Aucun.

		//---------------------------------------------------- Attributs privés
		static const int BUFFER_SIZE = 256;
};

//-------------------- Autres définitions dépendantes de <InterfaceUtilisateur>

#endif
