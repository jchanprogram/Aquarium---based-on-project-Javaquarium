#ifndef POISSON_H_INCLUDED
#define POISSON_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <string>

#include "EtreVivant.h"

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

/******************************/
/**        Accesseurs        **/
/******************************/

    std::string getNom() const;
    std::string getSexe() const;


protected:

    std::string m_nom;
    std::string m_sexe;



private:


};


#endif // POISSON_H_INCLUDED
