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
    int nb;

/*
    std::random_device randomDevice;
    std::mt19937 g(randomDevice());
    std::cout << g;*/

	// Creation de l'aquarium
	Aquarium aquarium("juju");

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

    aquarium.tourSuivant(5);


	std::cout << "Appuyer sur une touche pour continuer ..." << std::endl;
	std::cin.ignore();
	std::cin.get();


    aquarium.~Aquarium();

	return EXIT_SUCCESS;

}
