/*
 * Fahren.cpp
 *
 *  Created on: 11.11.2024
 *      Author: User
 */

#include "Fahren.h"
#include "Streckenende.h"


Fahren::Fahren(Weg& weg)
: Verhalten(weg)
{
	// TODO Auto-generated constructor stub

}

Fahren::~Fahren()
{
	// TODO Auto-generated destructor stub
}

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if(std::abs(this->p_Weg.getLaenge() - aFzg.getAbschnittStrecke()) < 0.000001)
		{
			throw Streckenende(aFzg, this->p_Weg);

		}
		if(this->p_Weg.getLaenge() - aFzg.getAbschnittStrecke() < aFzg.getGeschwindigkeit() * dZeitIntervall) // Fahrzeug fährt bis zum Ende der Straße
		{
			return this->p_Weg.getLaenge() - aFzg.getAbschnittStrecke();
		}
		return aFzg.getGeschwindigkeit() * dZeitIntervall;
}
