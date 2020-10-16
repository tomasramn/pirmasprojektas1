#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#define DYDIS 50 //DYDIS YRA 50 ELEMENTU MASYVAS
using namespace std;

struct studentas {
	string Vardas, Pavarde;
	int Pazymiai[DYDIS], num = 0;
	float Egzaminas, mediana = 0, vidurkis = 0, rez = 0;
	vector<float> paz;
};
int pasirinkimas;
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
		case 0: cout << std::setw(15) << fixed << setprecision(2)<< i[j].vidurkis << endl;
			break;
		case 1: cout << std::setw(15) << fixed << setprecision(2) << i[j].mediana << endl;
			break;
		default: break;
		}
	}

}
void pasirink() {
	cout << "Pasirinkite: 0 - Skaiciuoja pazymi pagal vidurki, 1 - skaiciuoja pagal mediana: ";
	cin >> pasirinkimas;
	while (pasirinkimas < 0 || pasirinkimas > 1) {
		cout << "Pasirinkite skaiciu 0 arba 1!\n";
		cin.clear();
		cin.ignore();
		cin >> pasirinkimas;
	}
}
int main()
{
	studentas Eilute; studentas Eilute_mas[8];
	vector <studentas> eil_vect;
	vector <int> nd;
	int rin;
	float paz;
	int rinkis = 1;
	int n = 0;
	int sk = 0; //kiek studentu
	cout << "Pasirinkite: '1' - Nuskaityti duomenis is failo, '0' - Irasyti duomenis paciam: ";
	cin >> rin;
	if (rin == 1) {
		ifstream data;
		data.open("kursiokai.txt"); //Atidarom faila

		if (data.fail()) {
			cout << "Nepavyko atidaryti failo" << endl; //Jei nepavyko atidaryti 
			exit(1);
		}

		for (int i = 0; i < rinkis && !data.eof(); i++) {
			data >> Eilute.Vardas >> Eilute.Pavarde;
			for (int j = 0; j < 5; j++) { // Mažiau už 5, nes max pazymiu yra 5
				data >> paz;
				nd.push_back(paz);
				Eilute.rez = Eilute.rez + paz;
			}
			n = 5;
			Eilute.vidurkis = Eilute.rez / n;
			data >> Eilute.Egzaminas;
			rinkis++;
			Eilute.mediana = findMedian(nd, n);
			Eilute.mediana = Eilute.mediana * 0.4 + Eilute.Egzaminas * 0.6;
			Eilute.vidurkis = Eilute.vidurkis * 0.4 + Eilute.Egzaminas * 0.6;
			eil_vect.push_back(Eilute);
			Eilute.rez = 0;
			nd.clear();
		}
		sk = rinkis - 1;
		pasirink();
		spausdink(eil_vect, sk, pasirinkimas);
	}
	else if (rin == 0) {
		cout << "Iveskite Studentu skaiciu: \n";
		cin >> sk;
		for (int i = 0; i < sk; i++) {
			cout << "Iveskite Varda: ";
			cin >> Eilute.Vardas;
			cout << "Iveskite Pavarde: ";
			cin >> Eilute.Pavarde;

			//EGZAMINO PASIRINKIMAS
			cout << "Noredami sugeneruoti atsitiktini egzamino rezultata, irasykite '-1', Noredami ivesti rezultata paciam, irasykite '0' ";
			int randegz = 0;
			cin >> randegz;
			if (randegz == -1) {
				Eilute.Egzaminas = rand() % 10 + 1;
				cout << "Atsitiktinis sugeneruotas egzamino rezultatas yra: " << Eilute.Egzaminas << "\n";
			}
			else if (randegz == 0) {
				cout << "Iveskite Egzamino rezultata: ";
				cin >> Eilute.Egzaminas;
				while (Eilute.Egzaminas < 1 || Eilute.Egzaminas > 10) {
					cout << "Pazymys turi buti tarp 1 ir 10!\n";
					cin.clear();
					cin.ignore();
					cin >> Eilute.Egzaminas;
				}
			}
			int randpaz;
			int psrnk = 0;
			cout << "Noredami sugeneruoti bet koki namu darbu pazymi, irasykite '-1', Noredami ivesti rezultata paciam, irasykite '0' \n";
			cin >> randpaz;
			if (randpaz == 0) {
				cout << "Iveskite Pazymius (Ivedus '-1' reiskia, jog pazymius jau baigete ivedineti): ";
				for (int i = 0; i <= DYDIS; i++) {
					cin >> Eilute.Pazymiai[i];
					if (Eilute.Pazymiai[i] == -1) {
						break;
					}
					n = Eilute.Pazymiai[i]; //
					while (Eilute.Pazymiai[i] < 1 || Eilute.Pazymiai[i] > 10) {
						cout << "Pazymys turi buti tarp 1 ir 10!\n";
						cin.clear();
						cin.ignore();
						cin >> Eilute.Pazymiai[i];
					}
					Eilute.rez = Eilute.rez + (float)Eilute.Pazymiai[i];
					nd.push_back(Eilute.Pazymiai[i]);
				}
			}
			else if (randpaz == -1) {
				cout << "Iveskite kiek norite, kad butu sugeneruota pazymiu: ";
				cin >> psrnk;
				for (int i = 0; i < psrnk; i++) {
					Eilute.Pazymiai[i] = rand() % 11;
					cout << "Sugeneruotas: " << i + 1 << "-asis pazymys yra: " << Eilute.Pazymiai[i] << endl;
					Eilute.rez = Eilute.rez + (float)Eilute.Pazymiai[i];
					nd.push_back(Eilute.Pazymiai[i]);
				}
				cout << "Suma yra: " << Eilute.rez << "\n";
				n = psrnk;
				Eilute.rez = Eilute.rez / n;
				cout << "Vidurkis: " << Eilute.rez << "\n";
				Eilute.vidurkis = Eilute.rez * 0.4 + Eilute.Egzaminas * 0.6;
				cout << "Galutinis Rezultatas: " << fixed << setprecision(2) << Eilute.vidurkis << "\n";

				cout << "\nMediana = " << fixed << setprecision(2) << findMedian(nd, n);
				Eilute.mediana = findMedian(nd, n) * 0.4 + Eilute.Egzaminas * 0.6;
				cout << "\nGalutinis rezultatas: " << fixed << setprecision(2) << Eilute.mediana << "\n";
				Eilute.rez = 0;
				eil_vect.push_back(Eilute);
				nd.clear();
			}
		}
		pasirink();
		spausdink(eil_vect, sk, pasirinkimas);
		return 0;
	}
}
