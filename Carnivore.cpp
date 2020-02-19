#include <stdio.h>
#include <iostream>
#include <string>

#include "Carnivore.h"

Carnivore::Carnivore() : Poisson() //constructeur
{
}

Carnivore::Carnivore(std::string nom, std::string sexe,unsigned int age) : Poisson(nom,sexe,age)
{
}

Carnivore::Carnivore(std::string nom, std::string sexe,unsigned int age, std::string type) : Poisson(nom,sexe,age),m_type("Carnivore")
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

void Carnivore::eating(EtreVivant &etre)
{
    etre.recevoirDegats(4);
    this->recevoirPv(5);
}

std::string Carnivore::getType() const
{
    return m_type;
}



Merou::Merou() : Carnivore()//constructeur
{

}


Merou::Merou(std::string nom, std::string sexe,unsigned int age,std::string type, std::string espece) : Carnivore(nom,sexe,age,type), m_espece(espece)
{
    //m_type="Carnivore";
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

std::string Merou::getEspece() const
{
    return m_espece;
}

Thon::Thon() : Carnivore()//constructeur
{
}

/*void Merou::hermaWithAge()
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
}*/


Thon::Thon(std::string nom, std::string sexe,unsigned int age, std::string type, std::string espece) : Carnivore(nom,sexe,age,type), m_espece(espece)
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

std::string Thon::getEspece() const
{
    return m_espece;
}

Poisson_Clown::Poisson_Clown() : Carnivore()//constructeur
{
}


Poisson_Clown::Poisson_Clown(std::string nom, std::string sexe, unsigned int age,std::string type, std::string espece) : Carnivore(nom,sexe,age,type), m_espece(espece)
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

std::string Poisson_Clown::getEspece() const
{
    return m_espece;
}

/*void Poisson_Clown::hermaOpportuniste (Poisson &p1)
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
}*/
