#include <stdio.h>
#include <iostream>
#include <string>

#include "Algue.h"

Algue::Algue() : EtreVivant()//: m_etat(true)
{
}

Algue::Algue(bool naissance, unsigned int age) : EtreVivant(age),m_naissance(naissance)
{
}

Algue::~Algue()
{
}

void Algue::sePresenter () const
{
    std::cout << "Je suis une 'Algue' "<< std::endl;
    if(m_estVivant)
    {
        std::cout << "J'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis morte" <<std::endl;
    }
}

/*void Algue::recevoirDegats(unsigned int degats)
{
        m_pv-=degats;
}*/
/*void Algue::eating()
{
    std::cout <<"et salut toi merde" << std::endl;
}*/
