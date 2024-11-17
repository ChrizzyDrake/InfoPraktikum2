/*
 * Fahrrad.h
 *
 *  Created on: 20.10.2024
 *      Author: User
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"

class Fahrrad: public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(std::string sName, double dMaxGeschwindigkeit);
	virtual ~Fahrrad();
	double dGeschwindigkeit() override;
};

#endif /* FAHRRAD_H_ */
