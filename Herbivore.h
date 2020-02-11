#ifndef HERBIVORE_H_INCLUDED
#define HERBIVORE_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <string>

#include "Poisson.h"

class Herbivore : public Poisson
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/
    Herbivore(); //constructeur
    Herbivore(std::string nom, std::string sexe);
    Herbivore(std::string nom, std::string sexe, std::string type);
    virtual~Herbivore(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    virtual void sePresenter () const;

protected:

    std::string m_type;


private:

};

class Sole : public Herbivore
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/

    Sole(); //constructeur
    Sole(std::string nom, std::string sexe, std::string espece);
    virtual~Sole(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    virtual void sePresenter () const;


protected:

private:

    std::string m_espece;
};

class Bar : public Herbivore
{
public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/

    Bar(); //constructeur
    Bar(std::string nom, std::string sexe, std::string espece);
    virtual~Bar(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    virtual void sePresenter () const;

protected:

private:

    std::string m_espece;

};

class Carpe : public Herbivore
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/

    Carpe(); //constructeur
    Carpe(std::string nom, std::string sexe, std::string espece);
    virtual~Carpe(); //destructeur

/******************************/
/**          Action          **/
/******************************/

     virtual void sePresenter () const;

protected:

private:

    std::string m_espece;
};

#endif // HERBIVORE_H_INCLUDED
