/*
 * Simulationsobjekt.h
 *
 *  Created on: 03.11.2024
 *      Author: User
 */
#include <string>
#include <iostream>
#include <iomanip>

#ifndef SIMULATIONSOBJEKT_H_
#define SIMULATIONSOBJEKT_H_

class Simulationsobjekt
{
public:
	Simulationsobjekt();
	Simulationsobjekt(std::string sName);
	Simulationsobjekt(Simulationsobjekt& other) = delete;
	Simulationsobjekt& operator=(const Simulationsobjekt& other) = delete;
	virtual ~Simulationsobjekt();
	virtual void vAusgeben(std::ostream& out);
	virtual void vSimulieren() = 0;
	bool operator==(const Simulationsobjekt& simulationsobjekt) const;
	std::string getName();
protected:
	static inline int p_iMaxID = 0;
		std::string p_sName = "";
		const int p_iID = 0;
		double p_dZeit = 0;
};

#endif /* SIMULATIONSOBJEKT_H_ */
