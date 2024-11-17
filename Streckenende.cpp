/*
 * Streckenende.cpp
 *
 *  Created on: 16.11.2024
 *      Author: User
 */

#include "Streckenende.h"

Streckenende::Streckenende(Fahrzeug& aFzg, Weg& aWeg)
: Fahrausnahme(aFzg, aWeg)
{
	// TODO Auto-generated constructor stub

}

Streckenende::~Streckenende()
{
	// TODO Auto-generated destructor stub
}

void Streckenende::vBearbeiten()
{
	std::cout << "Es handelt sich um die Ausnahme Streckenende von Fahrzeug " << this->fahrzeug.getName() << " auf dem Weg " << this->weg.getName() << std::endl;
}
