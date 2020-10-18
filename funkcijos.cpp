#include "funkcijos.h"
void pasirink() {
	int pasirinkimas;
	cout << "Pasirinkite: 0 - Skaiciuoja pazymi pagal vidurki, 1 - skaiciuoja pagal mediana: ";
	cin >> pasirinkimas;
	while (pasirinkimas < 0 || pasirinkimas > 1) {
		cout << "Pasirinkite skaiciu 0 arba 1!\n";
		cin.clear();
		cin.ignore();
		cin >> pasirinkimas;
	}
}
double findMedian(vector<int> v, int n) //Medianos ieskojimo algoritmas
{
	// Isrusiuojame masyva:
	sort(v.begin(), v.end());

	// ieskoma ar yra lyginis skaiciu kiekis
	if (v.size() % 2 != 0)
		return v[v.size() / 2];

	return (double)(v[(v.size() - 1) / 2] + v[v.size() / 2]) / 2.0;
}
void spausdink(vector<studentas> i, int sk, int pasirinkimas) {
	cout << endl << endl;
	cout << std::left
		<< std::setw(15) << "Vardas"
		<< std::setw(15) << "Pavarde";
	switch (pasirinkimas) {
	case 0: cout << std::setw(15) << "Galutinis (Vid.)" << endl;
		cout << "------------------------------------------------------------" << endl;
		break;
	case 1: cout << std::setw(15) << "Galutinis (Med.)" << endl;
		cout << "------------------------------------------------------------" << endl;
		break;
	default: cout << std::setw(15) << endl;
	}
	for (int j = 0; j < sk; j++)
	{
		cout << std::left
			<< std::setw(15) << i[j].Vardas
			<< std::setw(15) << i[j].Pavarde;
		switch (pasirinkimas) {
		case 0: cout << std::setw(15) << fixed << setprecision(2) << i[j].vidurkis << endl;
			break;
		case 1: cout << std::setw(15) << fixed << setprecision(2) << i[j].mediana << endl;
			break;
		default: break;
		}
	}

}
string generuoti(vector<studentas>& studinfo, int kiekis)
{
	studinfo = {}; // nunullinam struktura
	studinfo.reserve(kiekis + 1);
	studinfo.resize(kiekis + 1);
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> balai(1.0, 10.0);
	double egzas;
	string outrawfile = "rawfile" + to_string(kiekis) + ".txt";
	ofstream rawfile(outrawfile);
	for (int i = 1; i <= kiekis; i++) {
		studinfo[i].Vardas = "Vardas" + to_string(i);
		studinfo[i].Pavarde = "Pavarde" + to_string(i);
		egzas = balai(mt);
		studinfo[i].Egzaminas = egzas;
		rawfile << left << setw(20) << studinfo[i].Vardas << setw(20) << studinfo[i].Pavarde << setw(20) << setprecision(3) << studinfo[i].Egzaminas << endl;
	}
	return outrawfile;
}
void nuskaityti(vector<studentas>& studinfo, int kiekis, string failas)
{
	ifstream autoIn(failas);
	studinfo = {}; // nunullinam struktura
	studinfo.reserve(kiekis + 1);
	studinfo.resize(kiekis + 1);

	for (int i = 1; i <= kiekis; i++) {
		autoIn >> studinfo[i].Vardas >> studinfo[i].Pavarde >> studinfo[i].Egzaminas;
	}
}
void surusiuok(vector<studentas>& studinfo, int kiekis, int& VargsiukuKiekis, int& GalvociuKiekis, vector<studentas>& vargsiukai, vector<studentas>& galvociai)
{
	for (int i = 1; i <= kiekis; i++) {
		if (studinfo[i].Egzaminas < 5.00) {
			vargsiukai[VargsiukuKiekis].Vardas = studinfo[i].Vardas;
			vargsiukai[VargsiukuKiekis].Pavarde = studinfo[i].Pavarde;
			vargsiukai[VargsiukuKiekis].Egzaminas = studinfo[i].Egzaminas;
			VargsiukuKiekis++;
		}
		else {
			galvociai[GalvociuKiekis].Vardas = studinfo[i].Vardas;
			galvociai[GalvociuKiekis].Pavarde = studinfo[i].Pavarde;
			galvociai[GalvociuKiekis].Egzaminas = studinfo[i].Egzaminas;
			GalvociuKiekis++;
		}
	}
}
void spausdinti(vector<studentas> vektorius, int kiekis, string failoPav = "rezultatai.txt") // iraso sugeneruotus duomenis i faila
{
	ofstream offile(failoPav);
	offile << "Vardas             Pavarde              Galutinis (egz.)\n";
	offile << "--------------------------------------------------------\n";
	for (int i = 0; i < kiekis; i++) {
		offile << left << setw(20) << vektorius[i].Vardas << setw(20) << vektorius[i].Pavarde << setw(20) << setprecision(3) << vektorius[i].Egzaminas << endl;
	}

}
void dalykai(vector<studentas>& vargsiukai, vector<studentas>& galvociai, vector<studentas>& studinfo, int kiekis)
{
	studinfo.reserve(kiekis + 1);
	studinfo.resize(kiekis + 1);
	vargsiukai.reserve(kiekis + 1);
	galvociai.reserve(kiekis + 1);
	vargsiukai.resize(kiekis + 1);
	galvociai.resize(kiekis + 1); //+1, tam, kad spausdintu vardus ir pavardes prirasant ne 0, o 1

	chrono::time_point<chrono::system_clock> start, end;
	chrono::time_point<chrono::system_clock> startEvent, endEvent;
	chrono::duration<double> elapsed_seconds;

	int GalvociuKiekis, VargsiukuKiekis;
	string failas;

	start = chrono::system_clock::now();
	startEvent = chrono::system_clock::now();
	failas = generuoti(studinfo, kiekis); // process
	end = chrono::system_clock::now();
	elapsed_seconds = end - start;
	cout << "Failo su " << kiekis << " duomenu sugeneravimas uztruko: " << elapsed_seconds.count() << "s\n";

	start = chrono::system_clock::now();
	nuskaityti(studinfo, kiekis, failas);
	end = chrono::system_clock::now();
	elapsed_seconds = end - start;
	cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";

	start = chrono::system_clock::now();
	VargsiukuKiekis = 0;
	GalvociuKiekis = 0;
	surusiuok(studinfo, kiekis, VargsiukuKiekis, GalvociuKiekis, vargsiukai, galvociai);
	end = chrono::system_clock::now();
	elapsed_seconds = end - start;
	cout << "Failo su " << kiekis << " duomenu suskirstymas i galvocius ir vargsiukus uztruko: " << elapsed_seconds.count() << "s\n";


	string pavadinimasV = "vargsiukai" + to_string(kiekis) + ".txt";
	string pavadinimasG = "galvociai" + to_string(kiekis) + ".txt";

	start = chrono::system_clock::now();
	spausdinti(vargsiukai, VargsiukuKiekis, pavadinimasV);
	end = chrono::system_clock::now();
	elapsed_seconds = end - start;
	cout << "Failo su " << GalvociuKiekis << " duomenu irasymas i galvociu faila uztruko: " << elapsed_seconds.count() << "s\n";
	start = chrono::system_clock::now();
	spausdinti(galvociai, VargsiukuKiekis, pavadinimasG);
	end = chrono::system_clock::now();
	elapsed_seconds = end - start;
	cout << "Failo su " << VargsiukuKiekis << " duomenu irasymas i vargsiuku faila uztruko: " << elapsed_seconds.count() << "s\n";

	endEvent = chrono::system_clock::now();
	elapsed_seconds = endEvent - startEvent;
	cout << "Failo su " << kiekis << " duomenu testo laikas: " << elapsed_seconds.count() << "s\n\n";
}