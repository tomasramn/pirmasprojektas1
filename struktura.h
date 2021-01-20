#pragma once
#include "funkcijos.h"
struct studentas {
	string Vardas, Pavarde;
	int Pazymiai[DYDIS], num = 0;
	float Egzaminas, mediana = 0, vidurkis = 0, rez = 0;
	vector<float> paz;
};