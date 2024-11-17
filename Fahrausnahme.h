/*
 * Fahrausnahme.h
 *
 *  Created on: 16.11.2024
 *      Author: User
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_

#include <boost/exception/exception.hpp>
#include "Fahrzeug.h"
#include "Weg.h"


class Fahrausnahme: public boost::exception
{
public:
	Fahrausnahme(Fahrzeug& aFzg, Weg& aWeg);
	virtual ~Fahrausnahme();
	virtual void vBearbeiten() = 0;
protected:
	Fahrzeug& fahrzeug;
	Weg& weg;
};

#endif /* FAHRAUSNAHME_H_ */
