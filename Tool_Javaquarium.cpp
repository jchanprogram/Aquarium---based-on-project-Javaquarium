#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>

#include "Tool_Javaquarium.h"
#include "EtreVivant.h"
#include "Algue.h"
#include "Poisson.h"
#include "Aquarium.h"
#include "Carnivore.h"
#include "Herbivore.h"


std::string choixNomPoisson()
{
    std::string nomPoisson;
    std::cout<<"Comment voulez-vous nommez le poisson ?"<<std::endl;
    std::cin>>nomPoisson;
    std::cout<<std::endl;
    while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
        {
            std::cout << "Erreur, il faut ecrire un nombre" << std::endl; //On signale l'erreur avec un cout
            std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
            std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
            std::cin >> nomPoisson; //On redemande l'entrée
        }
    return nomPoisson;
}

std::string choixSexePoisson()
{

    std::string sexe;
    int choixSexe(0);
    while(choixSexe<1 || choixSexe>2)
    {
        std::cout<<"Quel est son sexe ?"<<std::endl;
        std::cout<<"1. Male"<<std::endl;
        std::cout<<"2. Femelle"<<std::endl;
        std::cin>>choixSexe;
        std::cout<<std::endl;
        if(choixSexe<1 || choixSexe>2)
        {
            std::cout << "Le choix fait n'est pas valide, recommencez." << std::endl;
        }
        while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
        {
            std::cout << "Erreur, il faut ecrire un nombre" << std::endl; //On signale l'erreur avec un cout
            std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
            std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
            std::cin >> sexe; //On redemande l'entrée
        }
    }
    switch(choixSexe)
    {
        case 1:
            sexe="Male";
            return sexe;
            break;

        case 2:
            sexe="Femelle";
            return sexe;
            break;
        default:
            std::cout << "You made an illegal choice"<<std::endl;
            return 0;
    }
}

std::string choixTypePoisson()
{
    std::string type;
    std::cout<<"Quel type de poisson voulez-vous ?"<<std::endl;
    std::cout<<"(Poisson disponible : Merou, Thon, Poisson_Clown, Sole, Bar, Carpe)"<<std::endl;
    std::cin>>type;
    std::cout<<std::endl;
     while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
        {
            std::cout << "Erreur, il faut ecrire un nombre" << std::endl; //On signale l'erreur avec un cout
            std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
            std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
            std::cin >> type; //On redemande l'entrée
        }
    return type;
}

std::string choixEspecePoisson()
//int choixEspecePoisson()
{
    std::string espece;
    int choixEspece;
    while(choixEspece<1 || choixEspece>6)
    {
        std::cout<<"Quelle espece de poisson voulez-vous ajouter?"<<std::endl;
        std::cout<<"1. Merou"<<std::endl;
        std::cout<<"2. Thon"<<std::endl;
        std::cout<<"3. Poisson_Clown"<<std::endl;
        std::cout<<"4. Sole"<<std::endl;
        std::cout<<"5. Bar"<<std::endl;
        std::cout<<"6. Carpe"<<std::endl;
        std::cin>>choixEspece;
        std::cout<<std::endl;
        if(choixEspece<1 || choixEspece>6)
        {
            std::cout << "Le choix fait n'est pas valide, recommencez." << std::endl;
        }
        while(std::cin.fail()) //si l'entrée est pas un int, ca fait le while
        {
            std::cout << "Erreur, il faut ecrire un nombre" << std::endl; //On signale l'erreur avec un cout
            std::cin.clear(); //On vide le flag qui indique qu'il y a une erreur
            std::cin.ignore(256,'\n'); //ignorer les prochains 256 caractère jusqu'a trouver le retour chariot
            std::cin >> choixEspece; //On redemande l'entrée
        }
    }
    //return choixEspece;
    switch(choixEspece)
    {
        case 1:
            espece="Merou";
            return espece;
            break;

        case 2:
            espece="Thon";
            return espece;
            break;

        case 3:
            espece="Poisson_Clown";
            return espece;
            break;

        case 4:
            espece="Sole";
            return espece;
            break;

        case 5:
            espece="Bar";
            return espece;
            break;

        case 6:
            espece="Carpe";
            return espece;
            break;
        default:
            std::cout << "You made an illegal choice"<<std::endl;
            return 0;
    }

}


/*void shuffleVector(std::vector<auto> A)
{
    std::random_device randomDevice;
    std::mt19937 g(randomDevice());

    std::shuffle(A.begin(), A.end(), g);
}*/
