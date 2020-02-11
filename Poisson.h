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
    Poisson(std::string nom, std::string sexe);
    virtual ~Poisson(); //destructeur

/******************************/
/**          Action          **/
/******************************/
    virtual void sePresenter () const;
    bool canIEat();
    //virtual void eatingHerbivore(Poisson *pMange, Algue *aEstMange)=0;
    //virtual void eatingCarnivore(Poisson *pMange, Poisson *pEstMange)=0;

    //void processus();
/******************************/
/**        Accesseurs        **/
/******************************/

    std::string getNom() const;
    std::string getSexe() const;
    virtual std::string getType() const=0;
    virtual std::string getEspece() const=0;
    void setHaveEat(bool haveEatThisTurn);
    bool getHaveEat() const;

    virtual bool checkSameSpecies(Poisson const& p1,Poisson const& p2) const;
//    virtual bool checkSameSpecies(Poisson p1,Poisson p2) const;
protected: //Privé mais accessible aux éléments enfants

    std::string m_nom;
    std::string m_sexe;
    std::string m_type;
    std::string m_espece;
    bool m_haveEatThisTurn=false;


private:

    /*std::string m_nom;
    std::string m_sexe;*/


};





#endif // POISSON_H_INCLUDED
