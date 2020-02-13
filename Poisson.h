#ifndef POISSON_H_INCLUDED
#define POISSON_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <string>

#include "EtreVivant.h"
#include "Algue.h"

class Poisson : public EtreVivant
{

public:
/******************************/
/** Constructeur/Destructeur **/
/******************************/
    Poisson(); //constructeur
    Poisson(std::string nom, std::string sexe, unsigned int age);
    virtual ~Poisson(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    virtual void sePresenter () const;
    virtual void eating(EtreVivant &etre) = 0;
    virtual bool checkSameSpecies(Poisson &p1, Poisson &p2);
    virtual bool checkSameSexe(Poisson &p1, Poisson &p2);
    virtual bool canIEat(Poisson &p1);

/******************************/
/**        Accesseurs        **/
/******************************/

    std::string getNom() const;
    std::string getSexe() const;
    void setSexe(std::string sexe);
    virtual std::string getType() const=0;
    virtual std::string getEspece() const=0;
    virtual bool getHaveEatThisTurn() const;
    virtual void setHaveEatThisTurn(bool haveEatThisTurn);

protected: //Privé mais accessible aux éléments enfants

    std::string m_nom;
    std::string m_sexe;
    std::string m_type;
    std::string m_espece;
    bool m_haveEatThisTurn;



private:

    /*std::string m_nom;
    std::string m_sexe;*/


};





#endif // POISSON_H_INCLUDED
