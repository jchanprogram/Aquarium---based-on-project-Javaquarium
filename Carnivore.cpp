#include <stdio.h>
#include <iostream>
#include <string>

#include "Carnivore.h"

Carnivore::Carnivore() : Poisson() //constructeur
{
}

Carnivore::Carnivore(std::string nom, std::string sexe) : Poisson(nom,sexe)
{
}

Carnivore::Carnivore(std::string nom, std::string sexe, std::string type) : Poisson(nom,sexe), m_type(type)
{
}

Carnivore::~Carnivore()
{
}

void Carnivore::sePresenter () const
{
    std::cout << "Je suis un 'Poisson Carnivore' "<< std::endl;
    if(m_estVivant)
    {
        std::cout << "Je suis un(e) "<<m_sexe<<" ,j'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis mort(e)" <<std::endl;
    }
}

Merou::Merou() : Carnivore()//constructeur
{
}


Merou::Merou(std::string nom, std::string sexe, std::string espece) : Carnivore(nom,sexe), m_espece(espece)
{
}

Merou::~Merou() //destructeur
{
}

void Merou::sePresenter () const
{
    std::cout << "Je suis un 'Merou' "<< std::endl;
    if(m_estVivant)
    {
        std::cout <<"Je m'appelle "<<m_nom<< ", je suis un(e) "<<m_sexe<<", j'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis mort(e)" <<std::endl;
    }
}

Thon::Thon() : Carnivore()//constructeur
{
}


Thon::Thon(std::string nom, std::string sexe, std::string espece) : Carnivore(nom,sexe), m_espece(espece)
{
}

Thon::~Thon() //destructeur
{
}

void Thon::sePresenter () const
{
    std::cout << "Je suis un 'Thon' "<< std::endl;
    if(m_estVivant)
    {
        std::cout <<"Je m'appelle "<<m_nom<< ", je suis un(e) "<<m_sexe<<", j'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis mort(e)" <<std::endl;
    }
}

Poisson_Clown::Poisson_Clown() : Carnivore()//constructeur
{
}


Poisson_Clown::Poisson_Clown(std::string nom, std::string sexe, std::string espece) : Carnivore(nom,sexe), m_espece(espece)
{
}

Poisson_Clown::~Poisson_Clown() //destructeur
{
}

void Poisson_Clown::sePresenter () const
{
    std::cout << "Je suis un 'Poisson_Clown' "<< std::endl;
    if(m_estVivant)
    {
        std::cout <<"Je m'appelle "<<m_nom<< ", je suis un(e) "<<m_sexe<<", j'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis mort(e)" <<std::endl;
    }
}
