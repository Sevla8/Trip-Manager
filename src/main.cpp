using namespace std;
#include <iostream>
#include "Catalogue.h"
#include "InterfaceUtilisateur.h"

int main(int argc, char const *argv[]) {
	Catalogue catalogue;
	int option;

	InterfaceUtilisateur::Bienvenue();
	while (true) {
		InterfaceUtilisateur::EnoncerOptions();

		cin >> option;

		switch (option) {
			case 0: {
				InterfaceUtilisateur::Quitter();
				return 0;
			}
			case 1: {
				InterfaceUtilisateur::AjouterTrajet(catalogue);
				break;
			}
			case 2: {
				InterfaceUtilisateur::AfficherCatalogue(catalogue);
				break;
			}
			case 3: {
				InterfaceUtilisateur::RechercherTrajet(catalogue);
				break;
			}
			default: {
				InterfaceUtilisateur::RepeterOptions();
			}
		}
	}
}
