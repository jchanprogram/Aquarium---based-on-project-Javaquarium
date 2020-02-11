#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

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
    /*for (unsigned int i=0; i<listOfAlgue.size();i++)
    {
        delete listOfAlgue[i];
    }
    for (unsigned int i=0; i<listOfPoisson.size();i++)
    {
        delete listOfPoisson[i];
    }*/
}


void Aquarium::tourSuivant(unsigned int nbTour)
{
    //unsigned int compt(0);
    do
    {
    std::cout << "********************************************** \n"
              << std::string(19,' ') << "Round " << (nbTour)
              << "\n********************************************** \n" << std::endl;
    Aquarium::debutTour();
    Aquarium::afficherEtat();


    std::cout << "Appuyer sur une touche pour continuer ..." << std::endl;
	std::cin.ignore();
	std::cin.get();
    Aquarium::faireMangerPoisson();

    nbTour--;
    }while(nbTour!=0);

    if(nbTour==0)
    {
        std::cout << "********************************************** \n"
              << std::string(19,' ') << "Fin du Game "
              << "\n********************************************** \n" << std::endl;
    }
        Aquarium::afficherEtat();
    for (unsigned int i=0; i<listOfAlgue.size();i++)
    {
        delete listOfAlgue[i];
    }
    for (unsigned int i=0; i<listOfPoisson.size();i++)
    {
        delete listOfPoisson[i];
    }

}

void Aquarium::addPoisson()
{
    m_espece = choixEspecePoisson();
    m_sexe=choixSexePoisson();
    m_nomPoisson=choixNomPoisson();


    if(m_espece=="Merou")
    {
        listOfPoisson.push_back(new Merou(m_nomPoisson,m_sexe,"Carnivore",m_espece));
    }
    else if(m_espece=="Thon")
    {
        listOfPoisson.push_back(new Thon(m_nomPoisson,m_sexe,"Carnivore",m_espece));
    }
    else if(m_espece=="Poisson_Clown")
    {
        listOfPoisson.push_back(new Poisson_Clown(m_nomPoisson,m_sexe,"Carnivore",m_espece));
    }
    else if(m_espece=="Sole")
    {
        listOfPoisson.push_back(new Sole(m_nomPoisson,m_sexe,"Herbivore",m_espece));
    }
    else if(m_espece=="Bar")
    {
        listOfPoisson.push_back(new Bar(m_nomPoisson,m_sexe,"Herbivore",m_espece));
    }
    else if(m_espece=="Carpe")
    {
        listOfPoisson.push_back(new Carpe(m_nomPoisson,m_sexe,"Herbivore",m_espece));
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
    std::cout<<std::endl;
    std::cout << "Voici les poissons présents dans l'aquarium :"<<std::endl;
    for (unsigned int i = 0;i < listOfPoisson.size();i++)
    {
        listOfPoisson[i]->afficherEtat(*listOfPoisson[i]);
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout << "Voici l'état des 'Algues' présentes dans l'aquarium :"<<std::endl;
    for (unsigned int i = 0;i < listOfAlgue.size();i++)
    {
        listOfAlgue[i]->afficherEtat(*listOfAlgue[i]);
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


void Aquarium::faireMangerPoisson()
{
    unsigned nbAction(0);
    std::random_device randomDevice;
    std::mt19937 g(randomDevice());
    do
    {
        std::shuffle(listOfPoisson.begin(), listOfPoisson.end(), g);
        if(listOfPoisson[0]->getHaveEatThisTurn()==true)
        {
            std::cout<< listOfPoisson[0]->getNom()<<" Ce poisson a deja mange"<<std::endl;
        }
        else if(!listOfPoisson[0]->canIEat(*listOfPoisson[0]))
        {
            std::cout<<listOfPoisson[0]->getNom()<<"Ce poisson a plus de 5pv, il peut aller niquer"<<std::endl;
            listOfPoisson[0]->setHaveEatThisTurn(true);
            nbAction++;
        }
        else if(listOfPoisson[0]->canIEat(*listOfPoisson[0]) && listOfPoisson[0]->getHaveEatThisTurn()==false)
        {
            if(listOfPoisson[0]->getType()=="Carnivore")
            {
                if(!listOfPoisson[0]->checkSameSpecies(*listOfPoisson[0], *listOfPoisson[1]))
                {
                    listOfPoisson[0]->eating(*listOfPoisson[1]);
                    std::cout<<listOfPoisson[0]->getNom()<<" a manger "<<listOfPoisson[1]->getNom()<<std::endl;
                    if(!listOfPoisson[1]->checkEstVivant())
                    {
                        delete listOfPoisson[1];
                        listOfPoisson.erase(listOfPoisson.begin()+1);
                    }
                }
                else
                {
                    std::cout<<listOfPoisson[0]->getNom()<<" a essaye de manger "<<listOfPoisson[1]->getNom()<<std::endl;
                }
            }
            else if(listOfPoisson[0]->getType()=="Herbivore")
            {
                std::shuffle(listOfAlgue.begin(), listOfAlgue.end(), g);
                listOfPoisson[0]->eating(*listOfAlgue[0]);
                std::cout<<listOfPoisson[0]->getNom()<<" a manger Algue"<<std::endl;
                if(!listOfAlgue[0]->checkEstVivant())
                {
                    delete listOfAlgue[0];
                    listOfAlgue.erase(listOfAlgue.begin()+0);
                }
            }
            else
            {
                std::cout<<"Une erreur a lieu qq part"<<std::endl;
            }
            listOfPoisson[0]->setHaveEatThisTurn(true);
            nbAction++;
        }

    }while(nbAction!=listOfPoisson.size());

    for(unsigned int i = 0; i<listOfPoisson.size();i++)
    {
        listOfPoisson[i]->setHaveEatThisTurn(false);
    }
}

void Aquarium::debutTour()
{
    for(unsigned int i = 0; i<listOfAlgue.size();i++)
    {
        listOfAlgue[i]->recevoirPv(1);
    }

    for(unsigned int i = 0; i<listOfPoisson.size();i++)
    {
        listOfPoisson[i]->recevoirDegats(1);
        if(!listOfPoisson[i]->checkEstVivant())
        {
            delete listOfPoisson[i];
            listOfPoisson.erase(listOfPoisson.begin()+i);
        }
    }
}
