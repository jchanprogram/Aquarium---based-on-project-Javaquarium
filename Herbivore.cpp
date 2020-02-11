#include <stdio.h>
#include <iostream>
#include <string>

#include "Herbivore.h"
#include "Algue.h"

Herbivore::Herbivore() : Poisson() //constructeur
{
}

Herbivore::Herbivore(std::string nom, std::string sexe) : Poisson(nom,sexe)
{
}

Herbivore::Herbivore(std::string nom, std::string sexe, std::string type) : Poisson(nom,sexe),m_type("Herbivore")
{
}

Herbivore::~Herbivore()
{
}

void Herbivore::sePresenter () const
{
    std::cout << "Je suis un 'Poisson Herbivore' "<< std::endl;
     if(m_estVivant)
    {
        std::cout << "Je suis un(e) "<<m_sexe<<" ,j'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis mort(e)" <<std::endl;
    }
}

void Herbivore::eating(EtreVivant &etre)
{
    etre.recevoirDegats(2);
    this->recevoirPv(3);
}



std::string Herbivore::getType() const
{
    return m_type;
}

Sole::Sole() : Herbivore()//constructeur
{
}


Sole::Sole(std::string nom, std::string sexe, std::string type, std::string espece) : Herbivore(nom,sexe,type), m_espece(espece)
{
}

Sole::~Sole() //destructeur
{
}

void Sole::sePresenter () const
{
    std::cout << "Je suis une 'Sole' "<< std::endl;
     if(m_estVivant)
    {
        std::cout <<"Je m'appelle "<<m_nom<< ", je suis un(e) "<<m_sexe<<", j'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis mort(e)" <<std::endl;
    }
}

std::string Sole::getEspece() const
{
    return m_espece;
}

Bar::Bar() : Herbivore()//constructeur
{
}


Bar::Bar(std::string nom, std::string sexe, std::string type, std::string espece) : Herbivore(nom,sexe,type), m_espece(espece)
{
}

Bar::~Bar() //destructeur
{
}

void Bar::sePresenter () const
{
    std::cout << "Je suis un 'Bar' "<< std::endl;
     if(m_estVivant)
    {
        std::cout <<"Je m'appelle "<<m_nom<< ", je suis un(e) "<<m_sexe<<", j'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis mort(e)" <<std::endl;
    }
}

std::string Bar::getEspece() const
{
    return m_espece;
}

Carpe::Carpe() : Herbivore()//constructeur
{
}


Carpe::Carpe(std::string nom, std::string sexe, std::string type, std::string espece) : Herbivore(nom,sexe,type), m_espece(espece)
{
}

Carpe::~Carpe() //destructeur
{
}

void Carpe::sePresenter () const
{
    std::cout << "Je suis une 'Carpe' "<< std::endl;
     if(m_estVivant)
    {
        std::cout <<"Je m'appelle "<<m_nom<< ", je suis un(e) "<<m_sexe<<", j'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis mort(e)" <<std::endl;
    }
}

std::string Carpe::getEspece() const
{
    return m_espece;
}


