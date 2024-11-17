/*
 * Verhalten.cpp
 *
 *  Created on: 10.11.2024
 *      Author: User
 */

#include "Verhalten.h"
#include "Fahrzeug.h"

Verhalten::Verhalten(Weg& weg)
: p_Weg(weg)
{
	// TODO Auto-generated constructor stub

}

Verhalten::~Verhalten()
{
	// TODO Auto-generated destructor stub
}

Weg& Verhalten::getWeg()
{
	return this->p_Weg;
}
