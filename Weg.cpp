/*
 * Weg.cpp
 *
 *  Created on: 09.11.2024
 *      Author: User
 */

#include "Weg.h"
#include "Fahrzeug.h"
#include "Fahrausnahme.h"

Weg::Weg()
{
	// TODO Auto-generated constructor stub

}

Weg::Weg(std::string sName, double dLaenge, Tempolimit eTempolimit)
: Simulationsobjekt(sName), p_dLaenge(dLaenge), p_eTempolimit(eTempolimit)
{
}

Weg::~Weg()
{
	// TODO Auto-generated destructor stub
}

double Weg::getTempolimit()
{
	return static_cast<double>(this->p_eTempolimit);
}

void Weg::vSimulieren()
{
	for(auto& fahrzeug : p_pFahrzeuge)
	{
		try
		{
		fahrzeug->vSimulieren();
		}
		catch(Fahrausnahme& e) //Ein Catch_Block reicht, weil die Basisklasse alle Ausnhamen die von ihr erben behandedelt
		{
			e.vBearbeiten();
		}
	}
}

void Weg::vAusgeben(std::ostream& out)
{
	Simulationsobjekt::vAusgeben(out);
	out << std::setw(12) << this->p_dLaenge << "(";
	for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it)
	    {
	        out << (*it)->getName();
	        if (it != std::prev(p_pFahrzeuge.end()))
	        {
	            out << ", ";
	        }
	    }
	    out << ")";
}

void Weg::vKopf()
{
	std::cout << std::setiosflags(std::ios::left) << std::setw(5) << "ID" << std::setw(18) << "| Name" << std::setw(12) << "| Laenge" << "| Fahrzeuge" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------------------" << std::endl;
}

double Weg::getLaenge()
{
	return this->p_dLaenge;
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug)
{
	std::cout << "Annahme aufgerufen für " << fahrzeug->getName() << std::endl;
	std::cout.flush();
	if(fahrzeug == nullptr)
	{
		std::cout << "Fehler Nullptr";
		std::cout.flush();
		return;
	}
	fahrzeug->vNeueStrecke(*this);
	this->p_pFahrzeuge.push_back(std::move(fahrzeug));
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double dStartZeit)
{
	if(fahrzeug == nullptr)
		{
			std::cout << "Fehler Nullptr";
			std::cout.flush();
			return;
		}
		fahrzeug->vNeueStrecke(*this, dStartZeit);
		this->p_pFahrzeuge.push_front(std::move(fahrzeug));
}


