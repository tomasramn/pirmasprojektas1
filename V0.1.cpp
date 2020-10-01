#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#define DYDIS 50 //DYDIS YRA 50 ELEMENTU MASYVAS
using namespace std;

struct studentas {
	string Vardas;
	string Pavarde;
	int Pazymiai[DYDIS];
	int Egzaminas;
	float rez = 0;
	int pasirinkimas;
};
double findMedian(int a[], int n) //Medianos ieskojimo algoritmas
{
	// Isrusiuojame masyva:
	sort(a, a + n);

	// ieskoma ar yra lyginis skaiciu kiekis
	if (n % 2 != 0)
		return (double)a[n / 2];

	return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}
int main()
{
	studentas Eilute; studentas Eilute_mas[8];
	vector <studentas> eil_vect;
	vector <int> ndpaz;
	int sk = 0;
	cout << "Iveskite Studentu skaiciu: \n";
	cin >> sk;
	for (int i = 0; i < sk; i++) {
		cout << "Iveskite Varda: ";
		cin >> Eilute_mas[i].Vardas;
		cout << "Iveskite Pavarde: ";
		cin >> Eilute_mas[i].Pavarde;

		//EGZAMINO PASIRINKIMAS
		cout << "Noredami sugeneruoti atsitiktini egzamino rezultata, irasykite '-1', Noredami ivesti rezultata paciam, irasykite '0' ";
		int randegz = 0;
		cin >> randegz;
		if (randegz == -1) {
			Eilute_mas[i].Egzaminas = rand() % 10 + 1;
			cout << "Atsitiktinis sugeneruotas egzamino rezultatas yra: " << Eilute_mas[i].Egzaminas << "\n";
		}
		else if (randegz == 0) {
			cout << "Iveskite Egzamino rezultata: ";
			cin >> Eilute_mas[i].Egzaminas;
			while (Eilute_mas[i].Egzaminas < 1 || Eilute_mas[i].Egzaminas > 10) {
				cout << "Pazymys turi buti tarp 1 ir 10!\n";
				cin.clear();
				cin.ignore();
				cin >> Eilute_mas[i].Egzaminas;
			}
		}
		int randpaz;
		int n = 0;
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
				Eilute_mas[i].rez = Eilute_mas[i].rez + (float)Eilute.Pazymiai[i];
			}
		}
		else if (randpaz == -1); {
			cout << "Iveskite kiek norite, kad butu sugeneruota pazymiu: ";
			cin >> psrnk;
			for (int i = 0; i < psrnk; i++) {
				Eilute.Pazymiai[i] = rand() % 11;
				Eilute_mas[i].rez = Eilute_mas[i].rez + (float)Eilute.Pazymiai[i];
				cout << "Sugeneruotas: " << i + 1 << "-asis pazymys yra: " << Eilute.Pazymiai[i] << endl;
			}
			n = psrnk;
		}
		cout << "Pasirinkite: 0 - Skaiciuoja pazymi pagal vidurki, 1 - skaiciuoja pagal mediana: ";
		cin >> Eilute.pasirinkimas;
		while (Eilute.pasirinkimas < 0 || Eilute.pasirinkimas > 1) {
			cout << "Pasirinkite skaiciu 0 arba 1!\n";
			cin.clear();
			cin.ignore();
			cin >> Eilute.pasirinkimas;
		}

		//PASIRINKIMAI KAIP SKAICIUOTI VIDURKI
		if (Eilute.pasirinkimas == 0) {
			Eilute_mas[i].rez = Eilute_mas[i].rez / n;
			cout << "Vidurkis: " << Eilute_mas[i].rez << "\n";
			Eilute_mas[i].rez = Eilute_mas[i].rez * 0.4 + Eilute_mas[i].Egzaminas * 0.6;
			cout << "Galutinis Rezultatas: " << fixed << setprecision(2) << Eilute_mas[i].rez << "\n";
		}
		else if (Eilute.pasirinkimas == 1) {
			cout << "Mediana = " << fixed << setprecision(2) << findMedian(Eilute.Pazymiai, n);
			Eilute.rez = findMedian(Eilute.Pazymiai, n) * 0.4 + Eilute_mas[i].Egzaminas * 0.6;
			cout << "Galutinis rezultatas: " << fixed << setprecision(2) << Eilute.rez << "\n";
		}
	}
	if (Eilute.pasirinkimas == 0) {
		cout << endl << endl;
		cout << left
			<< setw(15) << "Vardas"
			<< setw(15) << "Pavarde"
			<< setw(15) << "Galutinis (Vid.)"
			<< setw(15) << endl;
		cout << "----------------------------------------------------------" << endl;
		for (int j = 0; j < sk; j++)
		{
			cout << left
				<< setw(15) << Eilute_mas[j].Vardas
				<< setw(15) << Eilute_mas[j].Pavarde
				<< setw(15) << Eilute_mas[j].rez;
			cout << endl << endl;
		}
	}
	else if (Eilute.pasirinkimas == 1) {
		cout << endl << endl;
		cout << left
			<< setw(15) << "Vardas"
			<< setw(15) << "Pavarde"
			<< setw(15) << "Galutinis (Med.)"
			<< setw(15) << endl;
		cout << "----------------------------------------------------------" << endl;
		for (int j = 0; j < sk; j++)
		{
			cout << left
				<< setw(15) << eil_vect[j].Vardas
				<< setw(15) << eil_vect[j].Pavarde
				<< setw(15) << eil_vect[j].rez << endl;
		}
	}return 0;
}