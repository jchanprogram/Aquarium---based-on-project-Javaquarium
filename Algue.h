#ifndef ALGUE_H_INCLUDED
#define ALGUE_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <string>

#include "EtreVivant.h"

class Algue : public EtreVivant
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/
    Algue(); //constructeur
    Algue(bool naissance);
    virtual ~Algue(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    virtual void sePresenter () const;



protected:

private:

    bool m_naissance;


};



#endif // ALGUE_H_INCLUDED
