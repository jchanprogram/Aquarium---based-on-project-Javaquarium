#ifndef CARNIVORE_H_INCLUDED
#define CARNIVORE_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <string>

#include "Poisson.h"
#include "Algue.h"
#include "EtreVivant.h"

class Carnivore : public Poisson
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/

    Carnivore(); //constructeur
    Carnivore(std::string nom, std::string sexe, unsigned int age);
    Carnivore(std::string nom, std::string sexe,unsigned int age, std::string type);
    virtual~Carnivore(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    virtual void sePresenter () const;
    virtual void eating(EtreVivant &etre);

/******************************/
/**        Accesseurs        **/
/******************************/

    virtual std::string getType() const;
    virtual std::string getEspece() const=0;


protected:

    std::string m_type;


private:

};

class Merou : public Carnivore
{

public:

    Merou(); //constructeur
    Merou(std::string nom, std::string sexe,unsigned int age,std::string type ,std::string espece);
    virtual~Merou(); //destructeur

    virtual void sePresenter () const;
    virtual std::string getEspece() const;
    //void hermaWithAge ();

protected:

private:

    std::string m_espece;
};

class Thon : public Carnivore
{

public:

    Thon(); //constructeur
    Thon(std::string nom, std::string sexe, unsigned int age,std::string type ,std::string espece);
    virtual~Thon(); //destructeur

    virtual void sePresenter () const;
    virtual std::string getEspece() const;


protected:

private:

    std::string m_espece;
};

class Poisson_Clown : public Carnivore
{

public:

    Poisson_Clown(); //constructeur
    Poisson_Clown(std::string nom, std::string sexe,unsigned int age, std::string type ,std::string espece);
    virtual~Poisson_Clown(); //destructeur

    virtual void sePresenter () const;
    virtual std::string getEspece() const;
    //void hermaOpportuniste (Poisson &p1);

protected:

private:

    std::string m_espece;
};

#endif // CARNIVORE_H_INCLUDED
