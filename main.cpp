#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "SimuClient.h"
#include <memory>
#include <vector>
#include <algorithm>

double dGlobaleZeit = 0.0;
using namespace std;

std::ostream& operator<<(std::ostream& out, Simulationsobjekt& simulationsobjekt)
{
	simulationsobjekt.vAusgeben(out);
	return out;
}

void vAufgabe_1()
{
	/**
	Fahrzeug* fahrzeug1 = new Fahrzeug("VW Polo");
	Fahrzeug* fahrzeug2 = new Fahrzeug("VW Golf");;
    Fahrzeug fahrzeug3;
    Fahrzeug fahrzeug4;
    delete fahrzeug1;
    delete fahrzeug2;
    **/

	std::unique_ptr<Fahrzeug> fahrzeug1 = std::make_unique<Fahrzeug>();
	std::unique_ptr<Fahrzeug> fahrzeug2 = std::make_unique<Fahrzeug>();
	// std::unique_ptr<Fahrzeug> fahrzeug2_Kopie = fahrzeug2; Unique Pointer lassen sich nicht kopieren!!

	std::shared_ptr<Fahrzeug> fahrzeug3 = std::make_shared<Fahrzeug>();
	std::shared_ptr<Fahrzeug> fahrzeug4 = std::make_shared<Fahrzeug>();
	std::cout << "Aktuell besitzt das Objekt " << fahrzeug4.use_count() << " Referenzen" << std::endl;
	std::shared_ptr<Fahrzeug> fahrzeug4_Kopie = fahrzeug4;
	std::cout << "Aktuell besitzt das Objekt " << fahrzeug4.use_count() << " Referenzen" << std::endl;
	//Nachdem der sharedpointer auf einen weiteren shared pointer kopiert wurde, erhöht sich der Referenzcounter

	std::vector<std::unique_ptr<Fahrzeug>> fahrzeugliste_unique;
	fahrzeugliste_unique.push_back(std::move(fahrzeug1));
	fahrzeugliste_unique.push_back(std::move(fahrzeug2));
	/** std::move für Besitzwechsel
	fahrzeugliste->push_back(fahrzeug3);
	fahrzeugliste->push_back(fahrzeug4); Fahrzeug 3 und 4 sind shared_ptr und können daher nicht in den vector übernommen werden nur **/
	std::vector<std::shared_ptr<Fahrzeug>> fahrzeugliste_shared;
	/**fahrzeugliste_shared.push_back(std::move(fahrzeug1)); unique_ptr können mit move in eine Liste hinzugefügt werden **/
	std::cout << "Aktuell besitzt das Objekt " << fahrzeug4.use_count() << " Referenzen" << std::endl;
    fahrzeugliste_shared.push_back(fahrzeug4);
    std::cout << "Aktuell besitzt das Objekt " << fahrzeug4.use_count() << " Referenzen" << std::endl;
	fahrzeugliste_unique.clear();
	fahrzeugliste_shared.clear();
}

void vAufgabe_1a()
{
	dGlobaleZeit = 0;
	std::string sName;
	double dUserMaxGeschwindigkeit;
	double dZeittakt;
	std::vector<std::unique_ptr<Fahrzeug>> fahrzeugliste;
	std::cout << "Geben Sie den Namen des 1. Fahrzeugs ein: ";
	std::cin >> sName;
	std::cout << "Geben Sie die Maximalgeschwindigkeit des 1. Fahrzeugs ein: ";
	std::cin >> dUserMaxGeschwindigkeit;
	std::unique_ptr<Fahrzeug> fahrzeug1 = std::make_unique<Fahrzeug>(sName,dUserMaxGeschwindigkeit);
	fahrzeugliste.push_back(std::move(fahrzeug1));
	std::cout << "Geben Sie den Namen des 2. Fahrzeugs ein: ";
	std::cin >> sName;
	std::cout << "Geben Sie die Maximalgeschwindigkeit des 2. Fahrzeugs ein: ";
	std::cin >> dUserMaxGeschwindigkeit;
	std::unique_ptr<Fahrzeug> fahrzeug2 = std::make_unique<Fahrzeug>(sName,dUserMaxGeschwindigkeit);
	fahrzeugliste.push_back(std::move(fahrzeug2));
	std::cout << "Geben Sie den Namen des 3. Fahrzeugs ein: ";
	std::cin >> sName;
	std::cout << "Geben Sie die Maximalgeschwindigkeit des 3. Fahrzeugs ein: ";
	std::cin >> dUserMaxGeschwindigkeit;
	std::unique_ptr<Fahrzeug> fahrzeug3 = std::make_unique<Fahrzeug>(sName,dUserMaxGeschwindigkeit);
	fahrzeugliste.push_back(std::move(fahrzeug3));
	std::cout << "Geben Sie einen Zeittakt ein: ";
	std::cin >> dZeittakt;
	while(dGlobaleZeit < 10)
	{
		Fahrzeug::vKopf();
		for (size_t i = 0; i < fahrzeugliste.size(); i++)
		{
			fahrzeugliste[i]->vSimulieren();
			std::cout << (*fahrzeugliste[i]);
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
		dGlobaleZeit = dGlobaleZeit + dZeittakt;
	}

}

void vAufgabe_2()
{
	std::vector<std::unique_ptr<Fahrzeug>> fahrzeugliste;
	dGlobaleZeit = 0;
	std::string sName;
	double dUserMaxGeschwindigkeit;
	double dVerbrauch;
	double dTankvolumen;
	double dZeittakt;
	for(int i= 0; i < 2; i++)
	{
		std::cout << "Geben Sie den Namen des " << (i+1) << ". PKWs ein: ";
		std::cin >> sName;
		std::cout << "Geben Sie die Maximalgeschwindigkeit des " << (i+1) << ". PKWs ein: ";
		std::cin >> dUserMaxGeschwindigkeit;
		std::cout << "Geben Sie den Verbrauch des " << (i+1) << ". PKWs ein: ";
		std::cin >> dVerbrauch;
		std::cout << "Geben Sie das Tankvolumen des " << (i+1) << ". PKWs ein: ";
		std::cin >> dTankvolumen;
		std::unique_ptr<PKW> pkw = std::make_unique<PKW>(sName,dUserMaxGeschwindigkeit, dVerbrauch, dTankvolumen);
		fahrzeugliste.push_back(std::move(pkw));
		std::cout << "Geben Sie den Namen des " << (i+1) << ". Fahrrads ein: ";
		std::cin >> sName;
		std::cout << "Geben Sie die Maximalgeschwindigkeit des " << (i+1) << ". Fahrrads ein: ";
		std::cin >> dUserMaxGeschwindigkeit;
		std::unique_ptr<Fahrrad> fahrrad = std::make_unique<Fahrrad>(sName,dUserMaxGeschwindigkeit);
		fahrzeugliste.push_back(std::move(fahrrad));
	}
	std::cout << "Geben Sie einen Zeittakt ein: ";
	std::cin >> dZeittakt;
	while(dGlobaleZeit < 10)
		{
			Fahrzeug::vKopf();
			for (size_t i = 0; i < fahrzeugliste.size(); i++)
			{
				if(PKW* pkw = dynamic_cast<PKW*>(fahrzeugliste[i].get()))
				{
					if(dGlobaleZeit == 3)
					{
					std::cout << "Der PKW hat" << pkw->dTanken() << " Liter getankt." << std::endl;
					}
				}
				fahrzeugliste[i]->vSimulieren();
				std::cout << (*fahrzeugliste[i]);
				std::cout << std::endl;
			}
			std::cout << std::endl << std::endl;
			dGlobaleZeit = dGlobaleZeit + dZeittakt;
		}
}









double dEpsilon = 0.001;
void vAufgabe_AB1() {

    int l = 0; // Laufindex für gezielte AUsgabe
    vector<int> ausgabe{13};
    double dTakt = 0.4;

    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
    vecFahrzeuge.push_back(make_unique <PKW>("Audi", 231, 11.4));
    vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 19.8));
    for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dTakt)
    {
        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
        if (itL != ausgabe.end()) {
            std::cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
            Fahrzeug::vKopf();
        }

        for (int i = 0; i < vecFahrzeuge.size(); i++)
        {
            vecFahrzeuge[i]->vSimulieren();
            if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
            {
                vecFahrzeuge[i]->dTanken();
            }
            if (itL != ausgabe.end()) {
                std::cout << *vecFahrzeuge[i] << endl;
            }
        }
        l++;
    }
    char c;
    std::cin >> c;
}

void vAufgabe_4()
{
	std::unique_ptr<Weg> weg1 = std::make_unique<Weg>("Bergstraße", 100);
	Weg::vKopf();
	std::cout << std::endl;
	std::cout << *weg1 << std::endl;
}

void vAufgabe_5()
{
	double dTakt = 0.5;
	Weg weg1("Bergstraße", 100, Tempolimit::Landstraße);
	std::unique_ptr<Fahrzeug> pkw1 = std::make_unique<PKW>("Audi", 200, 11.4);
	std::unique_ptr<Fahrzeug> pkw2 = std::make_unique<PKW>("VW Polo", 200, 10);
	std::unique_ptr<Fahrzeug> fahrrad = std::make_unique<Fahrrad>("BMX", 5.8);
	std::cout << "Vor der Übergabe von pkw1 an vAnnahme, pkw1 ist gültig: "
	          << (pkw1 ? "Ja" : "Nein") << std::endl;
	std::cout << "Adresse von weg1 in Aufgabe5: " << &weg1 << std::endl;
	weg1.vAnnahme(std::move(pkw1));
	std::cout << "Nach erster Annahme";
	weg1.vAnnahme(std::move(pkw2));
	weg1.vAnnahme(std::move(fahrrad), 5);
	std::cout << "Hallo";
	Weg::vKopf();
	for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dTakt)
	{
		weg1.vSimulieren();
		std::cout << weg1 << std::endl;
	}

}

void vAufgabe_6()
{
	double dTakt = 0.3;
	Weg weg1("BergstraßeHin", 500, Tempolimit::Autobahn);
	Weg weg2("BergstraßeZurueck", 500, Tempolimit::Autobahn);
	std::unique_ptr<Fahrzeug> pkw1 = std::make_unique<PKW>("Audi", 200, 11.4);
	std::unique_ptr<Fahrzeug> pkw2 = std::make_unique<PKW>("VWPolo", 200, 10);
	std::unique_ptr<Fahrzeug> fahrrad = std::make_unique<Fahrrad>("BMX", 5.8);
	weg2.vAnnahme(std::move(pkw1));
	weg2.vAnnahme(std::move(pkw2), 3);
	weg1.vAnnahme(std::move(fahrrad));
	Weg::vKopf();

	bInitialisiereGrafik(800, 500);
	for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dTakt)
	{
		weg1.vSimulieren();
		weg2.vSimulieren();
		std::cout << weg1 << std::endl;
		std::cout << weg2 << std::endl;
	}
	vBeendeGrafik();
}

int main()
{
    //vAufgabe_1();
    //vAufgabe_1a();
    //vAufgabe_2();
    //vAufgabe_AB1();
    //vAufgabe_4();
	//vAufgabe_5();
	vAufgabe_6();
}
