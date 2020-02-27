#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include <random>


#include "Algue.h"
#include "Poisson.h"
#include "Aquarium.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Tool_Javaquarium.h"

int main()
{

    //std::random_device randomDevice;
    //std::mt19937 g(randomDevice());
       // std::uniform_int_distribution<> dis(0, 1);
    //std::cout << dis(g);*/
    std::string nomProprietaire;
    std::cout << "Entrez le nom du proprietaire de l'aquarium " << std::endl;
    std::cin >> nomProprietaire;
    while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
    {
        std::cout << "Erreur, vous devez écrire un nom" << std::endl; //On signale l'erreur avec un cout
        std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
        std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
        std::cin >> nomProprietaire; //On redemande l'entrée
    }
	// Creation de l'aquarium
	Aquarium aquarium(nomProprietaire);

    int nb;
	std::cout << "Combien de poisson voulez-vous ?"<<std::endl;
	std::cin>> nb;
	while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
    {
        std::cout << "Erreur, il faut ecrire un nombre" << std::endl; //On signale l'erreur avec un cout
        std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
        std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
        std::cin >> nb; //On redemande l'entrée
    }

    for (int i =0;i<nb;i++)
    {
        aquarium.addPoisson();
    }

    std::cout << "combien d'algues voulez-vous ?"<<std::endl;
	std::cin>> nb;
	while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
    {
        std::cout << "Erreur, il faut ecrire un nombre" << std::endl; //On signale l'erreur avec un cout
        std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
        std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
        std::cin >> nb; //On redemande l'entrée
    }

    for (int i =0;i<nb;i++)
    {
        aquarium.addAlgue();
    }
    aquarium.afficherEtatCreation();
    aquarium.tourSuivant(20);


	std::cout << "Appuyer sur une touche pour continuer ..." << std::endl;
	std::cin.ignore();
	std::cin.get();


    aquarium.~Aquarium();

	return EXIT_SUCCESS;

}
