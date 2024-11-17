/*
 * Losfahren.cpp
 *
 *  Created on: 16.11.2024
 *      Author: User
 */

#include "Losfahren.h"

Losfahren::Losfahren(Fahrzeug& aFzg, Weg& aWeg)
: Fahrausnahme(aFzg, aWeg)
{
	// TODO Auto-generated constructor stub

}

Losfahren::~Losfahren()
{
	// TODO Auto-generated destructor stub
}

void Losfahren::vBearbeiten()
{
	std::cout << "Es handelt sich um die Ausnahme Losfahren von Fahrzeug " << this->fahrzeug.getName() << " auf dem Weg " << this->weg.getName() << std::endl;
}
