/*
 * Losfahren.h
 *
 *  Created on: 16.11.2024
 *      Author: User
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_

#include "Fahrausnahme.h"

class Losfahren: public Fahrausnahme
{
public:
	Losfahren(Fahrzeug& aFzg, Weg& aWeg);
	virtual ~Losfahren();
	void vBearbeiten() override;
};

#endif /* LOSFAHREN_H_ */
