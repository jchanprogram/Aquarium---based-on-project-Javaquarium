#ifndef CARNIVORE_H_INCLUDED
#define CARNIVORE_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <string>

#include "Poisson.h"

class Carnivore : public Poisson
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/

    Carnivore(); //constructeur
    Carnivore(std::string nom, std::string sexe);
    Carnivore(std::string nom, std::string sexe, std::string type);
    virtual~Carnivore(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    virtual void sePresenter () const;

protected:
    std::string m_type;


private:

};

class Merou : public Carnivore
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/
    Merou(); //constructeur
    Merou(std::string nom, std::string sexe, std::string espece);
    virtual~Merou(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    virtual void sePresenter () const;

protected:

private:

    std::string m_espece;
};

class Thon : public Carnivore
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/
    Thon(); //constructeur
    Thon(std::string nom, std::string sexe, std::string espece);
    virtual~Thon(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    virtual void sePresenter () const;


protected:

private:

    std::string m_espece;
};

class Poisson_Clown : public Carnivore
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/
    Poisson_Clown(); //constructeur
    Poisson_Clown(std::string nom, std::string sexe, std::string espece);
    virtual~Poisson_Clown(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    virtual void sePresenter () const;

protected:

private:

    std::string m_espece;
};

#endif // CARNIVORE_H_INCLUDED
