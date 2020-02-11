#include <stdio.h>
#include <iostream>
#include <string>

#include "EtreVivant.h"

EtreVivant::EtreVivant() : m_pv(5), m_estVivant(true), m_age(0)
{
}

EtreVivant::~EtreVivant()
{
}

void EtreVivant::afficherEtat(EtreVivant const& etre)
{
    etre.sePresenter();
}

void EtreVivant::sePresenter () const
{
    std::cout << "Je fais partie de la catégorie des 'EtreVivant' "<< std::endl;
    if(m_estVivant)
    {
        std::cout << "J'ai "<< m_age<<" an(s) et "<< m_pv<<" point de vie."<<std::endl;
    }
    else
    {
        std::cout << "Je suis mort" <<std::endl;
    }

}

bool EtreVivant::checkEstVivant () const
{
    if(m_pv > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int EtreVivant::getPv() const
{
    return m_pv;
}

unsigned int EtreVivant::getAge() const
{
    return m_age;
}

void EtreVivant::recevoirDegats(unsigned int degats)
{
    m_pv-=degats;
    if(m_pv < 0)
    {
        m_pv = 0;
    }
}

void EtreVivant::recevoirPv(unsigned int pv)
{
    m_pv+=pv;
}
