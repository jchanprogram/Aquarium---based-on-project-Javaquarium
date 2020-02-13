#ifndef TOOL_JAVAQUARIUM_H_INCLUDED
#define TOOL_JAVAQUARIUM_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "EtreVivant.h"
#include "Algue.h"
#include "Poisson.h"
#include "Aquarium.h"
#include "Carnivore.h"
#include "Herbivore.h"


std::string choixNomPoisson();

std::string choixSexePoisson();

std::string choixTypePoisson();

std::string choixEspecePoisson();

unsigned int choixAge();

void hermaphroditeWithAge(Poisson &p1);
void hermaphroditeOppor(Poisson &p1,Poisson &p2);

//void shuffleVector(std::vector<auto> A);

#endif // TOOL_JAVAQUARIUM_H_INCLUDED
