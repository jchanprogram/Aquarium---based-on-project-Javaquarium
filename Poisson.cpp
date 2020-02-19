#include <stdio.h>
#include <iostream>
#include <string>

#include "Tool_Javaquarium.h"

#include "Poisson.h"
#include "EtreVivant.h"


Poisson::Poisson() : EtreVivant()//,m_pv(10),m_estVivant(true),m_age(0) //constructeur
{
}

Poisson::Poisson(std::string nom, std::string sexe, unsigned int age): EtreVivant(age),m_nom(nom), m_sexe(sexe),m_haveEatReproduceThisTurn(false)
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

bool Poisson::checkSameSpecies(Poisson &p1, Poisson &p2)
{
    if(p1.getEspece()==p2.getEspece())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Poisson::checkSameSexe(Poisson &p1, Poisson &p2)
{
    if(p1.getSexe()==p2.getSexe())
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Poisson::canIEat(Poisson &p1)
{
    if(p1.getPv()<6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Poisson::hermaphroditeWithAge(Poisson &p1)
{
    if(this->getEspece()=="Bar" || this->getEspece()=="Merou")
    {
        if(this->getAge()>10)
        {
            if(this->getSexe()=="Male")
            {
                this->setSexe("Femelle");
            }
            else
            {
                this->setSexe("Male");
            }
        }
    }
}

void Poisson::hermaOpportuniste (Poisson &p1)
{
    if(checkSameSexe(*this, p1))
    {
        if(this->getSexe()=="Male")
        {
            this->setSexe("Femelle");
        }
        else
        {
            this->setSexe("Male");
        }
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

void Poisson::setSexe(std::string sexe)
{
    m_sexe = sexe;
}

std::string Poisson::getType() const
{
    return m_type;
}

std::string Poisson::getEspece() const
{
    return m_espece;
}

bool Poisson::getHaveEatReproduceThisTurn() const
{
    return m_haveEatReproduceThisTurn;
}

void Poisson::setHaveEatReproduceThisTurn(bool haveEatReproduceThisTurn)
{
    m_haveEatReproduceThisTurn=haveEatReproduceThisTurn;
}
