#include <stdio.h>
#include <iostream>
#include <string>

#include "Poisson.h"

Poisson::Poisson() : EtreVivant()
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

