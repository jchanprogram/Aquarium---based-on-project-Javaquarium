#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "EtreVivant.h"

#include "Aquarium.h"
#include "Algue.h"
#include "Poisson.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Tool_Javaquarium.h"



Aquarium::Aquarium(): m_nbPoisson(0), m_nbAlgue(0)//constructeur
{
}

Aquarium::Aquarium(std::string nom): m_nom(nom), m_nbPoisson(0), m_nbAlgue(0)
{
}

Aquarium::~Aquarium() //destructeur
{
}


void Aquarium::tourSuivant(unsigned int nbTour)
{
    do
    {
    Aquarium::afficherEtat();
    nbTour--;

    std::cout << "Appuyer sur une touche pour continuer ..." << std::endl;
	std::cin.ignore();
	std::cin.get();

    }while(nbTour!=0);
}

void Aquarium::addPoisson()
{
    m_espece = choixEspecePoisson();
    m_sexe=choixSexePoisson();
    m_nomPoisson=choixNomPoisson();

    if(m_espece=="Merou")
    {
        listOfPoisson.push_back(new Merou(m_nomPoisson,m_sexe,m_espece));
    }
    else if(m_espece=="Thon")
    {
        listOfPoisson.push_back(new Thon(m_nomPoisson,m_sexe,m_espece));
    }
    else if(m_espece=="Poisson_Clown")
    {
        listOfPoisson.push_back(new Poisson_Clown(m_nomPoisson,m_sexe,m_espece));
    }
    else if(m_espece=="Sole")
    {
        listOfPoisson.push_back(new Sole(m_nomPoisson,m_sexe,m_espece));
    }
    else if(m_espece=="Bar")
    {
        listOfPoisson.push_back(new Bar(m_nomPoisson,m_sexe,m_espece));
    }
    else if(m_espece=="Carpe")
    {
        listOfPoisson.push_back(new Carpe(m_nomPoisson,m_sexe,m_espece));
    }

    m_nbPoisson++;
}

void Aquarium::addAlgue()
{

    listOfAlgue.push_back(new Algue(true));
    m_nbAlgue++;

}

void Aquarium::afficherEtat()
{
    std::cout << "Dans l'aquarium de " <<m_nom << " , il y a : "<< std::endl;
    std::cout <<"   - "<<  m_nbAlgue << " algue(s)"<< std::endl;
    std::cout <<"   - "<<  m_nbPoisson <<" poisson(s)"<< std::endl;
    std::cout<<std::endl;
    std::cout << "Voici les poissons présents dans l'aquarium :"<<std::endl;
    for (int i = 0;i<  listOfPoisson.size();i++)
    {
        listOfPoisson[i]->afficherEtat(*listOfPoisson[i]);
    }

}

unsigned int Aquarium::getNbPoisson()
{
    return m_nbPoisson;
}

unsigned int Aquarium::getNbAlgue()
{
    return m_nbAlgue;
}

