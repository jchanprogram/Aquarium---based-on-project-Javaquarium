#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

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

void Aquarium::afficherEtatCreation()
{
    std::cout << "********************************************** \n"
              << std::string(13,' ') << "L'aquarium est cree"
              << "\n********************************************** \n" << std::endl;
    Aquarium::afficherEtat();
    std::cout << "Appuyer sur une touche pour continuer ..." << std::endl;
	std::cin.ignore();
	std::cin.get();
}


void Aquarium::tourSuivant(unsigned int nbTour)
{
    unsigned int compt(0);
    do
    {
        compt++;
        std::cout << "********************************************** \n"
                << std::string(19,' ') << "Round " << (compt)
                << "\n********************************************** \n" << std::endl;

        if(compt!=1)
        {
            Aquarium::debutTour();
        }

        Aquarium::afficherEtat();

        std::cout<<std::endl;
        std::cout << "****        Actions des poissons/des algues          ****"<<std::endl<<std::endl;
        std::cout<<std::endl;
        Aquarium::faireMangerPoisson();

        std::cout << "****       Voici l'etat apres actions     ****"<<std::endl;
        std::cout<<std::endl;
        Aquarium::afficherEtat();

    std::cout << "Appuyer sur une touche pour continuer ..." << std::endl;
	std::cin.ignore();
	std::cin.get();

    //compt++;
    //nbTour--;
    //}while(nbTour!=0);
    }while(compt!=nbTour);

    if(compt==nbTour)
    {
        std::cout << "********************************************** \n"
              << std::string(19,' ') << "Fin du Game "
              << "\n********************************************** \n" << std::endl;

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

}

void Aquarium::addPoisson()
{
    m_espece = choixEspecePoisson();
    m_sexe=choixSexePoisson();
    m_nomPoisson=choixNomPoisson();
    m_age=choixAge();


    if(m_espece=="Merou")
    {
        listOfPoisson.push_back(new Merou(m_nomPoisson,m_sexe,m_age, "Carnivore",m_espece));
    }
    else if(m_espece=="Thon")
    {
        listOfPoisson.push_back(new Thon(m_nomPoisson,m_sexe,m_age, "Carnivore",m_espece));
    }
    else if(m_espece=="Poisson_Clown")
    {
        listOfPoisson.push_back(new Poisson_Clown(m_nomPoisson, m_sexe, m_age,"Carnivore",m_espece));
    }
    else if(m_espece=="Sole")
    {
        listOfPoisson.push_back(new Sole(m_nomPoisson,m_sexe,m_age,"Herbivore",m_espece));
    }
    else if(m_espece=="Bar")
    {
        listOfPoisson.push_back(new Bar(m_nomPoisson,m_sexe,m_age, "Herbivore",m_espece));
    }
    else if(m_espece=="Carpe")
    {
        listOfPoisson.push_back(new Carpe(m_nomPoisson,m_sexe,m_age, "Herbivore",m_espece));
    }

    m_nbPoisson++;
}

void Aquarium::addAlgue()
{
    m_age=choixAge();
    listOfAlgue.push_back(new Algue(true, m_age));
    m_nbAlgue++;

}

void Aquarium::afficherEtat()
{
    std::cout << "Dans l'aquarium de " <<m_nom << " , il y a : "<< std::endl;
    std::cout<<std::endl;
    std::cout <<"   - "<<  listOfAlgue.size() << " algue(s)"<< std::endl;
    std::cout <<"   - "<<  listOfPoisson.size() <<" poisson(s)"<< std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout << "Voici les poissons présents dans l'aquarium :"<<std::endl;
    std::cout<<std::endl;
    for (unsigned int i = 0;i < listOfPoisson.size();i++)
    {
        listOfPoisson[i]->afficherEtat(*listOfPoisson[i]);
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout << "Voici l'état des 'Algues' présentes dans l'aquarium :"<<std::endl;
    std::cout<<std::endl;
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
    if(listOfPoisson.size()>0)
    {
        unsigned nbAction(0);
        std::random_device randomDevice;
        std::mt19937 g(randomDevice());
        do
        {
            std::shuffle(listOfPoisson.begin(), listOfPoisson.end(), g);
            std::shuffle(listOfAlgue.begin(), listOfAlgue.end(), g);
            if(listOfPoisson[0]->getHaveEatReproduceThisTurn()==true)
            {
            //std::cout<< listOfPoisson[0]->getNom()<<" Ce poisson a deja mange"<<std::endl;
            //Aquarium::reproduce();
            }
            else if(!listOfPoisson[0]->canIEat(*listOfPoisson[0]))
            {
                //std::cout<<listOfPoisson[0]->getNom()<<" Ce poisson a plus de 5pv, il peut se reproduire"<<std::endl;
                Aquarium::reproduce();
                listOfPoisson[0]->setHaveEatReproduceThisTurn(true);
                nbAction++;
            }
            else if(listOfPoisson[0]->canIEat(*listOfPoisson[0]) && listOfPoisson[0]->getHaveEatReproduceThisTurn()==false)
            {
                Aquarium::manger();
                nbAction++;
            }

        }while(nbAction!=listOfPoisson.size());

        for(unsigned int i = 0; i<listOfPoisson.size();i++)
        {
            listOfPoisson[i]->setHaveEatReproduceThisTurn(false);
        }
        Aquarium::reproduceAlgue();
    }
}

void Aquarium::manger()
{
    if(listOfPoisson[0]->getType()=="Carnivore")
    {
        if(listOfPoisson.size()==1)
        {
            std::cout << "Le poisson ne peut rien manger il est seul dans l'aquarium"<<std::endl;
        }
        else
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
    }
    else if(listOfPoisson[0]->getType()=="Herbivore")
    {
        if(listOfAlgue.size()==0)
        {
            std::cout << "Le poisson ne peut rien manger il est seul dans l'aquarium"<<std::endl;
        }
        else
        {
            listOfPoisson[0]->eating(*listOfAlgue[0]);
            std::cout<<listOfPoisson[0]->getNom()<<" a manger Algue"<<std::endl;
            if(!listOfAlgue[0]->checkEstVivant())
            {
                delete listOfAlgue[0];
                listOfAlgue.erase(listOfAlgue.begin()+0);
            }
        }
    }
    else
    {
        std::cout<<"Une erreur a lieu qq part"<<std::endl;
    }
    listOfPoisson[0]->setHaveEatReproduceThisTurn(true);
}

void Aquarium::reproduce()
{
    if(listOfPoisson.size()==1)
    {
        std::cout << "Le poisson ne peut pas se reproduire il est seul dans l'aquarium"<<std::endl;
    }
    else if(listOfPoisson[0]->getAge()==0 || listOfPoisson[1]->getAge()==0)
    {
        std::cout << "Je suis un enfant encore, je ne peux pas me reproduire"<<std::endl;
    }
    else
    {
        //if(listOfPoisson[0]->checkSameSpecies(*listOfPoisson[0], *listOfPoisson[1]) && !listOfPoisson[0]->checkSameSexe(*listOfPoisson[0], *listOfPoisson[1]))
        if(listOfPoisson[0]->checkSameSpecies(*listOfPoisson[0], *listOfPoisson[1]))
        {
            std::string espece=listOfPoisson[0]->getEspece();
            if(espece=="Sole" || espece=="Poisson_Clown")
            {
                listOfPoisson[0]->hermaOpportuniste (*listOfPoisson[1]);
            }
            if(!listOfPoisson[0]->checkSameSexe(*listOfPoisson[0], *listOfPoisson[1]))
            {
            //std::string espece=listOfPoisson[0]->getEspece();
            std::cout<<listOfPoisson[0]->getNom()<<" va fourniquer avec "<<listOfPoisson[1]->getNom()<<std::endl;
                m_sexe = choixSexeNouveauNePoisson();
                m_nomPoisson = choixNomNouveauNePoisson(m_sexe);
                if(espece=="Merou")
                {
                    listOfPoisson.push_back(new Merou(m_nomPoisson,m_sexe,0, "Carnivore",espece));
                }
                else if(espece=="Thon")
                {
                    listOfPoisson.push_back(new Thon(m_nomPoisson,m_sexe,0, "Carnivore",espece));
                }
                else if(espece=="Poisson_Clown")
                {
                    listOfPoisson.push_back(new Poisson_Clown(m_nomPoisson, m_sexe, 0,"Carnivore",espece));
                }
                else if(espece=="Sole")
                {
                    listOfPoisson.push_back(new Sole(m_nomPoisson,m_sexe,0,"Herbivore",espece));
                }
                else if(espece=="Bar")
                {
                    listOfPoisson.push_back(new Bar(m_nomPoisson,m_sexe,0, "Herbivore",espece));
                }
                else if(espece=="Carpe")
                {
                    listOfPoisson.push_back(new Carpe(m_nomPoisson,m_sexe,0, "Herbivore",espece));
                }
            }
        }
        else
        {
            std::cout<<listOfPoisson[0]->getNom()<<" a essaye de fourniquer avec "<<listOfPoisson[1]->getNom()<<std::endl;
        }
    }
    listOfPoisson[0]->setHaveEatReproduceThisTurn(true);
}

void Aquarium::reproduceAlgue()
{
    for(unsigned int i = 0; i<listOfAlgue.size();i++)
    {
        if(listOfAlgue[i]->getPv()>=10)
        {
            listOfAlgue.push_back(new Algue(true, 0));
            std::cout<<"Nouvelle Algue cree"<<std::endl;
            listOfAlgue.back()->setPv(listOfAlgue[i]->getPv()/2);
            listOfAlgue[i]->recevoirDegats(listOfAlgue[i]->getPv()/2);
        }
    }
}

void Aquarium::debutTour()
{
    if(listOfAlgue.size()>1)
    {
/*** On en traite pas le cas d'indice 0 dans la boucle pour éviter des pb ***/
        for(unsigned int i = 1; i<listOfAlgue.size();i++)
        {
            listOfAlgue[i]->recevoirPv(1);
            listOfAlgue[i]->ageSup();
            if(!listOfAlgue[i]->checkEstVivant())
            {
                delete listOfAlgue[i];
                listOfAlgue.erase(listOfAlgue.begin()+i);
            }
        }
    }
    else if(listOfAlgue.size()==1)
    {
/*** Gestion de l'indice 0 ***/
        listOfAlgue[0]->recevoirPv(1);
        listOfAlgue[0]->ageSup();
        if(!listOfAlgue[0]->checkEstVivant())
        {
            delete listOfAlgue[0];
            listOfAlgue.erase(listOfAlgue.begin()+0);
        }
    }

    if(listOfPoisson.size()>1)
    {
/*** On en traite pas le cas d'indice 0 dans la boucle pour éviter des pb ***/
        for(unsigned int i = 1; i<listOfPoisson.size();i++)
        {
            listOfPoisson[i]->recevoirDegats(1);
            listOfPoisson[i]->ageSup();
            /******/
            listOfPoisson[i]->hermaphroditeWithAge(*listOfPoisson[i]);
        //}
            if(!listOfPoisson[i]->checkEstVivant())
            {
                delete listOfPoisson[i];
                listOfPoisson.erase(listOfPoisson.begin()+i);
            }

        }
    }
    else if(listOfPoisson.size()==1)
    {
     /*** Gestion de l'indice 0 ***/
        listOfPoisson[0]->recevoirDegats(1);
        listOfPoisson[0]->ageSup();
        /******/
        listOfPoisson[0]->hermaphroditeWithAge(*listOfPoisson[0]);
    //}
        if(!listOfPoisson[0]->checkEstVivant())
        {
            delete listOfPoisson[0];
            listOfPoisson.erase(listOfPoisson.begin()+0);
        }
    }
}
