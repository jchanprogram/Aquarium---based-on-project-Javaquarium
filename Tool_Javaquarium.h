#ifndef TOOL_JAVAQUARIUM_H_INCLUDED
#define TOOL_JAVAQUARIUM_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <string>

#include "EtreVivant.h"


std::string choixNomPoisson();

std::string choixSexePoisson();

std::string choixTypePoisson();

std::string choixEspecePoisson();
//int choixEspecePoisson();

//void afficheEtat(EtreVivant const& etre);

unsigned int randomNumber();
unsigned int choisirCible(unsigned int random, unsigned int nbElement);

#endif // TOOL_JAVAQUARIUM_H_INCLUDED
