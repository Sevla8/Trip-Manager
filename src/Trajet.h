/******************************************************************************
                           Trajet  -  description
                             -------------------
début       : 20.11.2020
copyright   : (C) 2020 par Jade Prévôt & Brandon da Silva Alves
e-mail      : jade.prevot@insa-lyon.fr / brandon.da-silva-alves@insa-lyon.fr
******************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ---------------
#ifndef TRAJET_H
#define TRAJET_H

//-------------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------ Constantes

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//		Permet de gérer un trajet.
//-----------------------------------------------------------------------------

class Trajet {
	//------------------------------------------------------------------ PUBLIC
	public:
		//-------------------------------------------------- Méthodes publiques
		virtual void Afficher() const = 0;
		// Mode d'emploi :
		//		Affiche les villes de départ, les villes d'arrivées et les
		// 		moyens de transport du trajet.
		// Contrat :
		//		Aucun.

		virtual bool EstPostAlpha(const Trajet* unTrajet) const = 0;
		// Mode d'emploi :
		//		Retourne vrai si la ville de départ du trajet arrive après la
		// 		ville de départ de unTrajet dans l'ordre alphabétique.Si les
		// 		villes de départs sont identiques, retourne vrai si la ville
		//		d'arrivée du trajet arrive après la ville d'arrivée de
		//		unTrajet dans l'ordre alphabétique. Retourne faux sinon.
		// Contrat :
		//		Aucun.

		virtual char* GetVilleDepart() const = 0;
		// Mode d'emploi :
		//		Retourne la ville de départ du trajet.
		// Contrat :
		//		Aucun.

		virtual char* GetVilleArrivee() const = 0;
		// Mode d'emploi :
		//		Retourne la ville d'arrivée du trajet.
		// Contrat :
		//		Aucun.

		virtual Trajet* Copier() const = 0;
		// Mode d'emploi :
		//		Retourne une copie du trajet.
		// Contrat :
		//		Aucun.

		//---------------------------------------------- Surcharge d'opérateurs

		//----------------------------------------- Constructeurs - destructeur
		Trajet();
		// Mode d'emploi :
		//		Construit un trajet.
		// Contrat :
		//		Aucun.

		virtual ~Trajet();
		// Mode d'emploi :
		//		Libère la mémoire associée au trajet.
		// Contrat :
		//		Aucun.

	//------------------------------------------------------------------- PRIVE
	protected:
		//-------------------------------------------------- Méthodes protégées

		//-------------------------------------------------- Attributs protégés

};

//---------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
