#include "funkcijos.h"
int pasirinkimas;
int main()
{
	studentas Eilute;
	vector <studentas> eil_vect;
	vector <int> nd;
	vector<studentas> studinfo;
	vector<studentas> vargsiukai;
	vector<studentas> galvociai;

	list<studentas> liststudinfo;
	list<studentas> listvargsiukai;
	list<studentas> listgalvociai;
	chrono::time_point<chrono::system_clock> start, end;
	chrono::time_point<chrono::system_clock> startEvent, endEvent;
	float paz;
	int rin, rinkis = 1, n = 0, sk = 0, arGeneruoti;
	//kiek studentu
	cout << "Irasykite '1', jei norite, kad visi duomenys butu generuojami, '0' - Negeneruoti duomenu): ";
	cin >> arGeneruoti;
	if (arGeneruoti == 1) {
		cout << "Vektoriaus konteinerio testavimas: \n\n";
		chrono::duration<double> elapsed_seconds;
		/* 1000 irasu */
		studinfo.push_back(Eilute);
		vargsiukai.push_back(Eilute);
		galvociai.push_back(Eilute);

		vectTesting(vargsiukai, galvociai, studinfo, 1000);

		// 10 000 irasu
		studinfo = {}; vargsiukai = {}; galvociai = {}; // isvalom vektoriu nuo praeitu irasu
		studinfo.clear(); vargsiukai.clear(); galvociai.clear();
		vectTesting(vargsiukai, galvociai, studinfo, 10000);
		// 100 000 irasu
		studinfo = {}; vargsiukai = {}; galvociai = {};
		studinfo.clear(); vargsiukai.clear(); galvociai.clear();
		vectTesting(vargsiukai, galvociai, studinfo, 100000);

		// 1 000 000 irasu
		studinfo = {}; vargsiukai = {}; galvociai = {};
		studinfo.clear(); vargsiukai.clear(); galvociai.clear();
		vectTesting(vargsiukai, galvociai, studinfo, 1000000);

		//10 000 000 irasu
		studinfo = {}; vargsiukai = {}; galvociai = {};
		studinfo.clear(); vargsiukai.clear(); galvociai.clear();
		vectTesting(vargsiukai, galvociai, studinfo, 10000000);

		//Baigiasi duomenu generavimas
		cout << "List konteinerio testavimas : \n\n";
		liststudinfo.push_back(Eilute);
		listvargsiukai.push_back(Eilute);
		listgalvociai.push_back(Eilute);

		containerTesting(listvargsiukai, listgalvociai, liststudinfo, 1000);

		// 10 000 irasu
		liststudinfo = {}; listvargsiukai = {}; listgalvociai = {}; // listu isvalymas nuo praeitu irasu
		liststudinfo.clear(); listvargsiukai.clear(); listgalvociai.clear();
		containerTesting(listvargsiukai, listgalvociai, liststudinfo, 10000);

		// 100 000 irasu
		liststudinfo = {}; listvargsiukai = {}; listgalvociai = {};
		liststudinfo.clear(); listvargsiukai.clear(); listgalvociai.clear();
		containerTesting(listvargsiukai, listgalvociai, liststudinfo, 100000);

		// 1 000 000 irasu
		liststudinfo = {}; listvargsiukai = {}; listgalvociai = {};
		liststudinfo.clear(); listvargsiukai.clear(); listgalvociai.clear();
		containerTesting(listvargsiukai, listgalvociai, liststudinfo, 1000000);

		liststudinfo = {}; listvargsiukai = {}; listgalvociai = {};
		liststudinfo.clear(); listvargsiukai.clear(); listgalvociai.clear();
		// 10 000 000 irasu
		liststudinfo = {}; listvargsiukai = {}; listgalvociai = {};
		liststudinfo.clear(); listvargsiukai.clear(); listgalvociai.clear();
		containerTesting(listvargsiukai, listgalvociai, liststudinfo, 10000000);
		return 0;
	}
	else if (arGeneruoti == 0) {
		cout << "Pasirinkite: '1' - Nuskaityti duomenis is failo, '0' - Irasyti duomenis paciam: ";
	}

	cin >> rin;
	try {
		if (rin == 1) {
			ifstream data;
			data.open("C:\\Users\\daiva\\Desktop\\kursiokai.txt"); //Atidarom faila
			if (data.is_open()) {
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
				chrono::time_point<chrono::system_clock> start, end;
				start = chrono::system_clock::now();
				spausdink(eil_vect, sk, pasirinkimas);
				end = chrono::system_clock::now();
				chrono::duration<double> elapsed_seconds = end - start;
				cout << "Duomenys nuskaityti per: " << elapsed_seconds.count() << "s\n";
			}
			if (data.fail()) {
				cout << "Nepavyko atidaryti failo!" << endl; //Jei nepavyko atidaryti 
				exit(1);
			}
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
			cout << "Pasirinkite: 0 - Skaiciuoja pazymi pagal vidurki, 1 - skaiciuoja pagal mediana: ";
			cin >> pasirinkimas;
			while (pasirinkimas < 0 || pasirinkimas > 1) {
				cout << "Pasirinkite skaiciu 0 arba 1!\n";
				cin.clear();
				cin.ignore();
				cin >> pasirinkimas;
			}
			spausdink(eil_vect, sk, pasirinkimas);
		}
		else {
			throw(rin);
		}
	}
	catch (exception) {
		cout << "Pasirinkite 1 arba 0!\n";
		exit(1);
	}
}