/*
 * Fahrrad.cpp
 *
 *  Created on: 20.10.2024
 *      Author: User
 */

#include "Fahrrad.h"

Fahrrad::Fahrrad()
{
	// TODO Auto-generated constructor stub

}

Fahrrad::Fahrrad(std::string sName, double dMaxGeschwindigkeit)
:Fahrzeug(sName,dMaxGeschwindigkeit)
{
}

Fahrrad::~Fahrrad()
{
	// TODO Auto-generated destructor stub
}

double Fahrrad::dGeschwindigkeit()
{
	int iExponent = floor(this->p_dGesamtStrecke / 20);
	double dAktuelleGeschwindigkeit = this->p_dMaxGeschwindigkeit * pow(0.9, iExponent);
	return dAktuelleGeschwindigkeit;
}
