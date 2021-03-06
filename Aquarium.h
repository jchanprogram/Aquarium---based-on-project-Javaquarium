#ifndef AQUARIUM_H_INCLUDED
#define AQUARIUM_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "EtreVivant.h"

#include "Algue.h"
#include "Poisson.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Tool_Javaquarium.h"


class Aquarium
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/

    Aquarium(); //constructeur
    Aquarium(std::string nom);
    virtual ~Aquarium(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    void tourSuivant(unsigned int nbTour);
    void addPoisson();
    void addAlgue();
    void afficherEtat();
    void debutTour();
    void afficherEtatCreation();

    void faireMangerPoisson();
    void manger();
    void reproduce();
    void reproduceAlgue();

/******************************/
/**        Accesseurs        **/
/******************************/

    unsigned int getNbPoisson();
    unsigned int getNbAlgue();


protected: //Privé mais accessible aux éléments enfants

private:

    std::string m_nom;

    Algue *m_algue;
    Poisson *m_poisson;
    std::vector<Poisson*> listOfPoisson; //collection hétérogene contient plusieur 'm_type' de 'Poisson'
    std::vector<Algue*> listOfAlgue;

    unsigned int m_nbPoisson;
    unsigned int m_nbAlgue;

    std::string m_nomPoisson;
    std::string m_sexe;
    std::string m_type;
    std::string m_espece;
    unsigned int m_age;




};


#endif // AQUARIUM_H_INCLUDED
