/*
 * Verhalten.h
 *
 *  Created on: 10.11.2024
 *      Author: User
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_

#include "Weg.h"
#include "Fahrzeug.h"

class Fahrzeug;

class Verhalten
{
public:
	Verhalten(Weg& weg);
	virtual ~Verhalten();
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;
	Weg& getWeg();
protected:
	Weg& p_Weg;
};

#endif /* VERHALTEN_H_ */
