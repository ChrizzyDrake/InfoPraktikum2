/*
 * Parken.cpp
 *
 *  Created on: 11.11.2024
 *      Author: User
 */


#include "Parken.h"
#include "Fahren.h"
#include "Losfahren.h"


Parken::Parken(Weg& weg, double dStartZeitpunkt)
: Verhalten(weg), p_dStartZeitpunkt(dStartZeitpunkt)
{
	// TODO Auto-generated constructor stub

}

Parken::~Parken()
{
	// TODO Auto-generated destructor stub
}

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	this->p_dStartZeitpunkt = this->p_dStartZeitpunkt - dZeitIntervall;
	if(this->p_dStartZeitpunkt <= 0.000001)
	{
		this->p_dStartZeitpunkt = 0;
		throw Losfahren(aFzg, this->p_Weg);
	}
	else
	{
		return 0;
	}
}
