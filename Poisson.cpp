#include <stdio.h>
#include <iostream>
#include <string>

#include "Tool_Javaquarium.h"

#include "Poisson.h"


Poisson::Poisson() : EtreVivant()//,m_pv(10),m_estVivant(true),m_age(0) //constructeur
{
}

Poisson::Poisson(std::string nom, std::string sexe): EtreVivant(),m_nom(nom), m_sexe(sexe)
{
}

Poisson::~Poisson()
{
}


void Poisson::sePresenter () const
{
    std::cout << "Je suis un 'Poisson' "<< std::endl;
    if(m_estVivant)
    {
        std::cout << "Je suis un(e) "<<m_sexe<<" ,j'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis mort(e)" <<std::endl;
    }
}

std::string Poisson::getNom() const
{
    return m_nom;
}

std::string Poisson::getSexe() const
{
    return m_sexe;
}

bool Poisson::canIEat()
{
    if(m_pv < 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*std::string Poisson::getType() const
{
    return m_type;
}

std::string Poisson::getEspece() const
{
    return m_espece;
}*/

void Poisson::setHaveEat(bool haveEatThisTurn)
{
    m_haveEatThisTurn=haveEatThisTurn;
}

bool Poisson::getHaveEat() const
{
    return m_haveEatThisTurn;
}

/*void Poisson::eatingCarnivore(Poisson pMange, Poisson pEstMange)
{
    if(!Poisson::checkSameSpecies(pMange,pestMange))
    {
        pMange.recevoirPv(5);
        pEstMange.recevoirDegats(4);

        std::cout <<pMange.getNom()<< " a mange une partie de " <<pEstMange.getNom()<<std::endl;

    }

    else
    {
        std::cout <<pMange.getNom()<< " a essayer de manger " <<pEstMange.getNom()<<std::endl;
    }
}*/

/*void Poisson::eatingHerbivore(Poisson pMange, Algue aEstMange)
{
    pMange.recevoirPv(3);
    aEstMange.recevoirDegats(2);
    std::cout <<pMange.getNom()<< " a manger Algue" <<std::endl;
}*/

/*void Poisson::eating(EtreVivant etre1, EtreVivant etre2, std::string type)
{
    if(type =="Carnivore")
    {
        Poisson::eatingCarnivore(EtreVivant etre1, EtreVivant etre2);
    }

    else if(type =="Herbivore")
    {
        Poisson::eatingherbivore(EtreVivant etre1, EtreVivant etre2);
    }
}*/

bool Poisson::checkSameSpecies(Poisson const& poisson1,Poisson const& poisson2) const
{
    if(poisson1.getEspece()==poisson2.getEspece())
    {
        return true;
    }
    else
    {
        return false;
    }
}
