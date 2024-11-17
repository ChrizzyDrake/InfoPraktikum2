/*
 * Fahrzeug.h
 *
 *  Created on: 13.10.2024
 *      Author: User
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <memory>

#include "Simulationsobjekt.h"

class Verhalten;
class Weg;

extern double dGlobaleZeit;
extern double dEpsilon;

class Fahrzeug: public Simulationsobjekt
{
public:
	Fahrzeug();
	Fahrzeug(std::string sName);
	Fahrzeug(std::string sName, double dMaxGeschwindigkeit);
	Fahrzeug(Fahrzeug& other) = delete;
	Fahrzeug& operator=(const Fahrzeug& other);
	virtual ~Fahrzeug();
	virtual void vAusgeben(std::ostream& out) override;
	static void vKopf();
	virtual void vSimulieren() override;
	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	bool operator<(const Fahrzeug& fahrzeug) const;
	double getGeschwindigkeit();
	double getAbschnittStrecke();
	void vNeueStrecke(Weg& weg);
	void vNeueStrecke(Weg& weg, double dStartZeit);

protected:
	double p_dMaxGeschwindigkeit = 0;
	double p_dGesamtStrecke = 0;
	virtual double dGeschwindigkeit();
	std::unique_ptr<Verhalten> p_pVerhalten;
	double p_dAbschnittStrecke = 0;
};

#endif /* FAHRZEUG_H_ */
