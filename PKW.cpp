/*
 * PKW.cpp
 *
 *  Created on: 20.10.2024
 *      Author: User
 */

#include "PKW.h"
#include "Verhalten.h"

PKW::PKW(std::string sName, double dMaxGeschwindigkeit, double dVerbrauch)
: Fahrzeug(sName, dMaxGeschwindigkeit),
  p_dVerbrauch(dVerbrauch)
{
	// TODO Auto-generated constructor stub

}

PKW::PKW(std::string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen)
:Fahrzeug(sName,dMaxGeschwindigkeit),
 p_dVerbrauch(dVerbrauch),
 p_dTankvolumen(dTankvolumen),
 p_dTankinhalt(dTankvolumen/2)
{

}

PKW::~PKW()
{
	// TODO Auto-generated destructor stub
}

void PKW::vAusgeben(std::ostream& out)
{
	Fahrzeug::vAusgeben(out);
	out << std::setw(20) << this->p_dGesamtStrecke/100 * this->p_dVerbrauch << this->p_dTankinhalt;
}

double PKW::dTanken(double dMenge)
{
	double dGetankteMenge;
	if(dMenge == std::numeric_limits<double>::infinity() || dMenge + this->p_dTankinhalt > this->p_dTankvolumen)
	{
		dGetankteMenge = this->p_dTankvolumen - this->p_dTankinhalt;
		this->p_dTankinhalt = this->p_dTankvolumen;
		return dGetankteMenge;
	}
	else
	{
		dGetankteMenge = dMenge;
		this->p_dTankinhalt = this->p_dTankinhalt + dMenge;
		return dGetankteMenge;
	}
}

void PKW::vSimulieren()
{
		if(this->p_dZeit != dGlobaleZeit)
		{
			double dVerstricheneZeit = dGlobaleZeit - this->p_dZeit;
			Fahrzeug::vSimulieren();
			this->p_dTankinhalt = this->p_dTankinhalt - this->p_dVerbrauch * (this->dGeschwindigkeit() * dVerstricheneZeit)/100;
			if(this->p_dTankinhalt <= 0)
			{
				this->p_dTankinhalt = 0;
			}
		}
}

double PKW::dGeschwindigkeit()
{
	if(this->p_dTankinhalt <= 0)
	{
		return 0;
	}
	else if (this->p_pVerhalten->getWeg().getTempolimit() >= this->p_dMaxGeschwindigkeit)
	{
		//std::cout << this->p_dMaxGeschwindigkeit << std::endl;
		return this->p_dMaxGeschwindigkeit;
	}
	//std::cout << this->p_pVerhalten->getWeg().getTempolimit() << std::endl;
	return this->p_pVerhalten->getWeg().getTempolimit();
}

PKW& PKW::operator=(const PKW& other)
{
	if(this != &other)
	{
		Fahrzeug::operator=(other);
		this->p_dTankinhalt = other.p_dTankinhalt;
		this->p_dTankvolumen = other.p_dTankvolumen;
		this->p_dVerbrauch = other.p_dVerbrauch;
	}
	return *this;
}



