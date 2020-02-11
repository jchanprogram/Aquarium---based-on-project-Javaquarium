#ifndef HERBIVORE_H_INCLUDED
#define HERBIVORE_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <string>

#include "Poisson.h"
#include "Algue.h"

class Herbivore : public Poisson
{

public:

    Herbivore(); //constructeur
    Herbivore(std::string nom, std::string sexe);
    Herbivore(std::string nom, std::string sexe, std::string type);
    virtual~Herbivore(); //destructeur

    virtual void sePresenter () const;
    //virtual void eating(EtreVivant & etre);
    virtual std::string getType() const;
    virtual std::string getEspece() const=0;

    //std::string getType() const;

    //virtual void eatingHerbivore(Poisson *pMange, Algue *aEstMange);
    //virtual void eatingCarnivore(Poisson *pMange, Poisson *pEstMange);
    //virtual void eating(Poisson *pMange, Algue *aEstMange);


protected:

    std::string m_type;
    //std::string m_espece;

private:

};

class Sole : public Herbivore
{

public:

    Sole(); //constructeur
    //Sole(std::string nom, std::string sexe, std::string type);
    Sole(std::string nom, std::string sexe, std::string type ,std::string espece);
    virtual~Sole(); //destructeur

    virtual void sePresenter () const;
    virtual std::string getEspece() const;


protected:

private:

    std::string m_espece;
};

class Bar : public Herbivore
{
public:

    Bar(); //constructeur
    //Bar(std::string nom, std::string sexe, std::string type);
    Bar(std::string nom, std::string sexe, std::string type ,std::string espece);
    virtual~Bar(); //destructeur

    virtual void sePresenter () const;
    virtual std::string getEspece() const;

protected:

private:

    std::string m_espece;

};

class Carpe : public Herbivore
{

public:

    Carpe(); //constructeur
    //Carpe(std::string nom, std::string sexe, std::string type);
    Carpe(std::string nom, std::string sexe, std::string type ,std::string espece);
    virtual~Carpe(); //destructeur

     virtual void sePresenter () const;
     virtual std::string getEspece() const;

protected:

private:

    std::string m_espece;
};

#endif // HERBIVORE_H_INCLUDED
