#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

#include "EtreVivant.h"

#include "Aquarium.h"
#include "Algue.h"
#include "Poisson.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Tool_Javaquarium.h"



Aquarium::Aquarium(): m_nbPoisson(0), m_nbAlgue(0)//constructeur
{
}

Aquarium::Aquarium(std::string nom): m_nom(nom), m_nbPoisson(0), m_nbAlgue(0)
{
}

Aquarium::~Aquarium() //destructeur
{
    /*for (unsigned int i=0; i<listOfAlgue.size();i++)
    {
        delete listOfAlgue[i];
    }
    for (unsigned int i=0; i<listOfPoisson.size();i++)
    {
        delete listOfPoisson[i];
    }*/
}


void Aquarium::tourSuivant(unsigned int nbTour)
{
    //unsigned int compt(0);
    do
    {
    std::cout << "********************************************** \n"
              << std::string(19,' ') << "Round " << (nbTour)
              << "\n********************************************** \n" << std::endl;

    Aquarium::afficherEtat();


    std::cout << "Appuyer sur une touche pour continuer ..." << std::endl;
	std::cin.ignore();
	std::cin.get();

	Aquarium::processus();
    nbTour--;
    }while(nbTour!=0);

    if(nbTour==0)
    {
        std::cout << "********************************************** \n"
              << std::string(19,' ') << "Fin du Game "
              << "\n********************************************** \n" << std::endl;
    }
        Aquarium::afficherEtat();
    for (unsigned int i=0; i<listOfAlgue.size();i++)
    {
        delete listOfAlgue[i];
    }
    for (unsigned int i=0; i<listOfPoisson.size();i++)
    {
        delete listOfPoisson[i];
    }

}

void Aquarium::addPoisson()
{
    m_espece = choixEspecePoisson();
    m_sexe=choixSexePoisson();
    m_nomPoisson=choixNomPoisson();

    /*m_type = choixTypePoisson();
    m_nomPoisson=choixNomPoisson();
    m_sexe=choixSexePoisson();
    m_espece = choixEspecePoisson();*/
    /********************************************/
    //m_espece="Merou";
    //listOfPoisson.push_back(new Merou(m_nomPoisson,m_sexe,m_espece));
    /********************************************/

    if(m_espece=="Merou")
    {
        listOfPoisson.push_back(new Merou(m_nomPoisson,m_sexe,"Carnivore",m_espece));
    }
    else if(m_espece=="Thon")
    {
        listOfPoisson.push_back(new Thon(m_nomPoisson,m_sexe,"Carnivore",m_espece));
    }
    else if(m_espece=="Poisson_Clown")
    {
        listOfPoisson.push_back(new Poisson_Clown(m_nomPoisson,m_sexe,"Carnivore",m_espece));
    }
    else if(m_espece=="Sole")
    {
        listOfPoisson.push_back(new Sole(m_nomPoisson,m_sexe,"Herbivore",m_espece));
    }
    else if(m_espece=="Bar")
    {
        listOfPoisson.push_back(new Bar(m_nomPoisson,m_sexe,"Herbivore",m_espece));
    }
    else if(m_espece=="Carpe")
    {
        listOfPoisson.push_back(new Carpe(m_nomPoisson,m_sexe,"Herbivore",m_espece));
    }

    m_nbPoisson++;
}

void Aquarium::addAlgue()
{

    listOfAlgue.push_back(new Algue(true));
    m_nbAlgue++;

}

void Aquarium::afficherEtat()
{
    std::cout << "Dans l'aquarium de " <<m_nom << " , il y a : "<< std::endl;
    std::cout <<"   - "<<  m_nbAlgue << " algue(s)"<< std::endl;
    std::cout <<"   - "<<  m_nbPoisson <<" poisson(s)"<< std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout << "Voici les poissons présents dans l'aquarium :"<<std::endl;
    for (unsigned int i = 0;i < listOfPoisson.size();i++)
    {
        listOfPoisson[i]->afficherEtat(*listOfPoisson[i]);
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout << "Voici l'état des 'Algues' présentes dans l'aquarium :"<<std::endl;
    for (unsigned int i = 0;i < listOfAlgue.size();i++)
    {
        listOfAlgue[i]->afficherEtat(*listOfAlgue[i]);
    }

}

unsigned int Aquarium::getNbPoisson()
{
    return m_nbPoisson;
}

unsigned int Aquarium::getNbAlgue()
{
    return m_nbAlgue;
}

/*bool Aquarium::checkSameSpecies(Poisson const& poisson1,Poisson const& poisson2) const
{
    if(poisson1.getEspece()==poisson2.getEspece())
    {
        return true;
    }
    else
    {
        return false;
    }
}*/


/****************************************************************/
/** Melange du vecteur pour choisir le poisson qui va manger   **/
/** de maniere aléatoire .On prendra le vecteur[0] comme choix **/
/****************************************************************/
void Aquarium::shuffleVectorPoisson(std::vector<Poisson*>  p)
{
    std::random_device randomDevice;
    std::mt19937 g(randomDevice());

    std::shuffle(p.begin(), p.end(), g);
}

/****************************************************************/
/** Melange du vecteur pour choisir l'algue qui va etre manger **/
/** de maniere aléatoire. On prendra le vecteur[0] comme choix **/
/****************************************************************/
void Aquarium::shuffleVectorAlgue(std::vector<Algue*>  p)
{
    std::random_device randomDevice;
    std::mt19937 g(randomDevice());

    std::shuffle(p.begin(), p.end(), g);
}

/****************************************************************/
/** Melange du reste du vecteur pour choisir le poisson qui va **/
/** etre manger de maniere aléatoire .On prendra le vecteur[1] **/
/** comme choix                                                **/
/****************************************************************/

void Aquarium::choixPoissonQuiEstMange(std::vector<Poisson*> p)

{
    std::random_device randomDevice;
    std::mt19937 g(randomDevice());

    std::shuffle(p.begin()+1, p.end(), g);
}

/****************************************************************/
/** Qaund vector[0] a mange on fait une rotation pour faire    **/
/** manger vecteur[1]. Vecteur[1] devient vecteur[0] et on     **/
/** refait un melange du reste du vecteur. En faisant ces      **/
/** rotations, je veux m'assure de parcourir toute les cibles  **/
/** Cependant j'ai des enormes doutes sur la pertinence de cet **/
/** algo, je dois pouvoir faire mieux et plus simple a mon avis**/
/****************************************************************/

void Aquarium::rotateVector(std::vector<Poisson*> etre, unsigned int rotation)
{
    std::rotate(etre.begin(),etre.begin()+rotation,etre.end());
}



void Aquarium::eatingCarnivore(Poisson *pMange, Poisson *pEstMange)
{
    if(!pMange->checkSameSpecies(*pMange,*pEstMange))
    {
        pMange->recevoirPv(5);
        pEstMange->recevoirDegats(4);

        std::cout <<pMange->getNom()<< " a mange une partie de " <<pEstMange->getNom()<<std::endl;
    }

    else
    {
        std::cout <<pMange->getNom()<< " a essayer de manger " <<pEstMange->getNom()<<std::endl;
    }
}

void Aquarium::eatingHerbivore(Poisson *pMange, Algue *aEstMange)
{
    pMange->recevoirPv(3);
    aEstMange->recevoirDegats(2);
    std::cout <<pMange->getNom()<< " a manger Algue" <<std::endl;
}

/****************************************************************/
/** Bouvle d'action : Manger pour tous les poissons            **/
/****************************************************************/

void Aquarium::processus()
{
    //Aquarium::shuffleVectorPoisson(listOfPoisson);
    unsigned int countPoissonAction(0);
    //while(countPoissonAction!=(unsigned int) listOfPoisson.size())
    do
    {
     Aquarium::shuffleVectorPoisson(listOfPoisson);
    //Poisson poissonQuiMange = listOfPoisson[0];
        bool checkEat = listOfPoisson[0]->canIEat();
        if(!checkEat)
        {
            countPoissonAction++;
        }
        else if(checkEat && listOfPoisson[0]->getHaveEat()==true)
        {
             Aquarium::shuffleVectorPoisson(listOfPoisson);
        }

        else if(checkEat && listOfPoisson[0]->getHaveEat()==false)
    //else
        {
            Aquarium::choixPoissonQuiEstMange(listOfPoisson);
            if(listOfPoisson[0]->getType()=="Carnivore")
            {
                if(listOfPoisson.size()==1)
                {
                    std::cout<<"Le poisson 'Carnivore' ne peut pas manger, il n'y a pas d'autre poisson vivant."<<std::endl;
                }
                else
                {
                    Aquarium::choixPoissonQuiEstMange(listOfPoisson);

                    Aquarium::eatingCarnivore(listOfPoisson[0], listOfPoisson[1]);
                    bool estVivant = listOfPoisson[1]->checkEstVivant();
                    if(estVivant==false)
                    {
                        delete listOfPoisson[1];
                        listOfPoisson.erase(listOfPoisson.begin()+1);
                    }
                }
            }
            else if(listOfPoisson[0]->getType()=="Herbivore")
            {
                if(listOfAlgue.size()==0)
                {
                    std::cout<<"Le poisson 'Herbivore' ne peut pas manger, il n'y a pas d''Algue' vivante."<<std::endl;
                    break;
                }
                else
                {
                    Aquarium::shuffleVectorAlgue(listOfAlgue);
                //Herbivore::eatingHerbivore(listOfPoisson[0], listOfAlgue[0]);
                    Aquarium::eatingHerbivore(listOfPoisson[0], listOfAlgue[0]);
                    bool estVivant = listOfAlgue[0]->checkEstVivant();
                    if(estVivant==false)
                    {
                        delete listOfAlgue[0];
                        listOfAlgue.erase(listOfAlgue.begin()+0);
                    }
                }
            }
            else
            {
                std::cout << "Le type de poisson est inconnu, il y a eu une erreur qq part"<< std::endl;
            //return 0;
            }
            countPoissonAction++;
            listOfPoisson[0]->setHaveEat(true);
            /*do
            {
                Aquarium::rotateVector(listOfPoisson,1);

            }while(listOfPoisson[0]->getHaveEat()==true);*/

            std::cout << countPoissonAction<< std::endl;

        }

        /*else
        {
            countPoissonAction++;
            std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaa"<< std::endl;
        }*/

    }while(countPoissonAction!=(unsigned int) listOfPoisson.size());
    if(countPoissonAction==(unsigned int) listOfPoisson.size()){
    for(unsigned int i = 0; i < listOfPoisson.size();i++)
    {
        listOfPoisson[i]->setHaveEat(false);
    }
    }
}
