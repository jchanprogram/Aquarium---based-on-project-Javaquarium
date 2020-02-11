#ifndef ETREVIVANT_H_INCLUDED
#define ETREVIVANT_H_INCLUDED


class EtreVivant
{

public:

/******************************/
/** Constructeur/Destructeur **/
/******************************/

    EtreVivant(); //constructeur
    virtual ~EtreVivant(); //destructeur

/******************************/
/**          Action          **/
/******************************/

    void afficherEtat(EtreVivant const& etre);
    virtual void sePresenter () const;

/******************************/
/**        Accesseurs        **/
/******************************/

    bool checkEstVivant () const;
    void recevoirDegats(unsigned int degats);
    void recevoirPv(unsigned int pv);

    //virtual void isEating(EtreVivant & etre)=0;
    //virtual void eating()=0;
    unsigned int getPv() const;
    //int setPv();
    unsigned int getAge() const;

/******************************/
/**        Autre        **/
/******************************/


protected:

    unsigned int m_pv;
    bool m_estVivant; // peut etre inutile
    unsigned int m_age;

private:


};

#endif // ETREVIVANT_H_INCLUDED
