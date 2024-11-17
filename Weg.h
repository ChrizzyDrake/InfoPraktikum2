/*
 * Weg.h
 *
 *  Created on: 09.11.2024
 *      Author: User
 */

#ifndef WEG_H_
#define WEG_H_

#include <list>
#include <memory>

#include "Simulationsobjekt.h"
#include "Tempolimit.h"

class Fahrzeug;


class Weg: public Simulationsobjekt
{
public:
	Weg();
	Weg(std::string sName, double dLaenge, Tempolimit eTempolimit = Tempolimit::Autobahn);
	virtual ~Weg();
	double getTempolimit();
	void vSimulieren() override;
	void vAusgeben(std::ostream& out) override;
	static void vKopf();
	double getLaenge();
	void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug);
	void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double dStartZeit);
private:
	double p_dLaenge = 0;
	std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit = Tempolimit::Autobahn;
};

#endif /* WEG_H_ */
