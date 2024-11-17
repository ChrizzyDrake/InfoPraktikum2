/*
 * PKW.h
 *
 *  Created on: 20.10.2024
 *      Author: User
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"

class PKW: public Fahrzeug
{
public:
	PKW(std::string sName, double dMaxGeschwindigkeit, double dVerbrauch);
	PKW(std::string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen);
	virtual ~PKW();
    void vAusgeben(std::ostream& out) override;
    double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;
    void vSimulieren() override;
    double dGeschwindigkeit() override;
    PKW& operator=(const PKW& other);
private:
    double p_dVerbrauch = 0;
    double p_dTankvolumen = 55;
    double p_dTankinhalt = 55/2;
};

#endif /* PKW_H_ */
