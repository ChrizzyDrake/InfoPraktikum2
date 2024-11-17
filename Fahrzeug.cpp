/*
 * Fahrzeug.cpp
 *
 *  Created on: 13.10.2024
 *      Author: User
 */

#include "Fahrzeug.h"
#include "Weg.h"
#include "Fahren.h"
#include "Parken.h"
//#include "Verhalten.h"

Fahrzeug::Fahrzeug()
: Simulationsobjekt::Simulationsobjekt()
{
	// TODO Auto-generated constructor stub
	std::cout << "Das Simulationsobjekt ist ein Fahrzeug" << std::endl;
}

Fahrzeug::Fahrzeug(std::string sName)
: Simulationsobjekt::Simulationsobjekt(sName)
{
	std::cout << "Das Simulationsobjekt ist ein Fahrzeug" << std::endl;
}

Fahrzeug::Fahrzeug(std::string sName, double dMaxGeschwindigkeit)
: Simulationsobjekt::Simulationsobjekt(sName), p_dMaxGeschwindigkeit((dMaxGeschwindigkeit >= 0) ? dMaxGeschwindigkeit : -dMaxGeschwindigkeit)
{
	std::cout << "Das Simulationsobjekt ist ein Fahrzeug" << std::endl;
}

Fahrzeug::~Fahrzeug()
{
	// TODO Auto-generated destructor stub
	std::cout << "Das geloeschte Simulationsobjekt war ein Fahrzeug" << std::endl;
;
}

void Fahrzeug::vAusgeben(std::ostream& out)
{
	Simulationsobjekt::vAusgeben(out);
	out << std::setw(20) << this->p_dMaxGeschwindigkeit << std::setw(20) << this->dGeschwindigkeit() << std::setw(20) << p_dGesamtStrecke;
}

void Fahrzeug::vKopf()
{
	std::cout << std::setiosflags(std::ios::left) << std::setw(5) << "ID" << std::setw(20) << "Name" << std::setw(20) << "MaxGeschwindigkeit" << std::setw(20) << "Geschwindigkeit" << std::setw(20) << "Gesamtstecke" << std::setw(20) << "Gesamtverbrauch" << "Tankinhalt" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void Fahrzeug::vSimulieren()
{
	if(this->p_dZeit != dGlobaleZeit)
	{
		double dVerstricheneZeit = dGlobaleZeit - this->p_dZeit;
		double dVerstrichenerWeg = this->p_pVerhalten->dStrecke(*this, dVerstricheneZeit);
		this->p_dGesamtStrecke = this->p_dGesamtStrecke + dVerstrichenerWeg;
		this->p_dAbschnittStrecke = this->p_dAbschnittStrecke + dVerstrichenerWeg;
		this->p_dZeit = dGlobaleZeit;
	}

}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit()
{
	return this->p_dMaxGeschwindigkeit;
}

bool Fahrzeug::operator<(const Fahrzeug& fahrzeug) const
{
	return p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke;
}

Fahrzeug& Fahrzeug::operator=(const Fahrzeug& other)
{
	if(this != &other)
	{
		this->p_dMaxGeschwindigkeit = other.p_dMaxGeschwindigkeit;
		this->p_sName = other.p_sName;
		this->p_dGesamtStrecke = other.p_dGesamtStrecke;
		this->p_dZeit = other.p_dZeit;


	}
	return *this;
}

double Fahrzeug::getGeschwindigkeit()
{
	return this->dGeschwindigkeit();
}

double Fahrzeug::getAbschnittStrecke()
{
	return this->p_dAbschnittStrecke;
}

void Fahrzeug::vNeueStrecke(Weg &weg)
{
	this->p_pVerhalten = std::make_unique<Fahren>(weg);
	this->p_dAbschnittStrecke = 0;
}

void Fahrzeug::vNeueStrecke(Weg& weg, double dStartZeit)
{
	this->p_pVerhalten = std::make_unique<Parken>(weg, dStartZeit);
	this->p_dAbschnittStrecke = 0;
}
