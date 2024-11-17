/*
 * Streckenende.h
 *
 *  Created on: 16.11.2024
 *      Author: User
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_

#include "Fahrausnahme.h"

class Streckenende: public Fahrausnahme
{
public:
	Streckenende(Fahrzeug& aFzg, Weg& aWeg);
	virtual ~Streckenende();
	void vBearbeiten() override;
};

#endif /* STRECKENENDE_H_ */
