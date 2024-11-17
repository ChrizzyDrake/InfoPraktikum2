/*
 * Parken.h
 *
 *  Created on: 11.11.2024
 *      Author: User
 */

#ifndef PARKEN_H_
#define PARKEN_H_

#include "Verhalten.h"

class Parken: public Verhalten
{
public:
	Parken(Weg& weg, double dStartZeitpunkt);
	virtual ~Parken();
	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;
private:
	double p_dStartZeitpunkt;
};

#endif /* PARKEN_H_ */
