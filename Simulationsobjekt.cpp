/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 03.11.2024
 *      Author: User
 */

#include "Simulationsobjekt.h"

Simulationsobjekt::Simulationsobjekt()
:p_iID(++p_iMaxID)
{
	// TODO Auto-generated constructor stub
	std::cout << "Ein neues Simulationsobjekt wurde erstellt, es bitzt die ID " << this->p_iID << std::endl;

}

Simulationsobjekt::Simulationsobjekt(std::string sName)
:p_sName(sName), p_iID(++p_iMaxID)
{
	std::cout << "Ein neues Simulationsobjekt wurde erstellt, es bitzt die ID " << this->p_iID << " und den Namen " << this->p_sName << std::endl;
}

Simulationsobjekt::~Simulationsobjekt()
{
	// TODO Auto-generated destructor stub
	std::cout << "Ein Simulationsobjekt mit der ID " << this->p_iID << " wurde geloescht" << std::endl;
}

void Simulationsobjekt::vAusgeben(std::ostream& out)
{
	out << std::setiosflags(std::ios::fixed)<< std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left) << std::setprecision(2) << std::setw(5) << p_iID << std::setw(20) << p_sName;
}

void Simulationsobjekt::vSimulieren()
{

}

bool Simulationsobjekt::operator==(const Simulationsobjekt& simulationsobjekt) const
{
	return this->p_iID == simulationsobjekt.p_iID;

}

std::string Simulationsobjekt::getName()
{
	return this->p_sName;
}
