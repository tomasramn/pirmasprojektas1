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
	cout << left
		<< setw(15) << "Vardas"
		<< setw(15) << "Pavarde";
	switch (pasirinkimas) {
	case 0: cout << setw(15) << "Galutinis (Vid.)" << endl;
		cout << "------------------------------------------------------------" << endl;
		break;
	case 1: cout << setw(15) << "Galutinis (Med.)" << endl;
		cout << "------------------------------------------------------------" << endl;
		break;
	default: cout << setw(15) << endl;
	}
	for (int j = 0; j < sk; j++)
	{
		cout << left
			<< setw(15) << i[j].Vardas
			<< setw(15) << i[j].Pavarde;
		switch (pasirinkimas) {
		case 0: cout << setw(15) << fixed << setprecision(2) << i[j].vidurkis << endl;
			break;
		case 1: cout << setw(15) << fixed << setprecision(2) << i[j].mediana << endl;
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
void dalykai(vector<studentas>& vargsiukai, vector<studentas>& galvociai, vector<studentas>& studinfo, int kiekis) //Skirtas V0.4 Versijai
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
void containerTesting(list<studentas>& vargsiukai, list<studentas>& galvociai, list<studentas>& studinfo, int kiekis)
{

	chrono::time_point<chrono::system_clock> start, end;
	chrono::time_point<chrono::system_clock> startEvent, endEvent;
	chrono::duration<double> elapsed_seconds;

	int GalvociuKiekis, VargsiukuKiekis;
	string failas;

	studinfo.resize(kiekis);

	startEvent = chrono::system_clock::now();
	try {
		failas = generuoti(studinfo, kiekis); // generuoja faila
	}
	catch (exception) {

		cout << "Klaida generuojant faila! \n";
	}
	studinfo.clear();
	try {
		start = chrono::system_clock::now();
		nuskaityti(studinfo, kiekis, failas);
		end = chrono::system_clock::now();
		elapsed_seconds = end - start;
		cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";
	}
	catch (exception) {
		cout << "Ivyko klaida nuskaitant List tipo faila! \n";
	}
	try {
		start = chrono::system_clock::now();
		rusiuoti(studinfo, kiekis);
		VargsiukuKiekis = 0;
		GalvociuKiekis = 0;
		//sortList(studinfo, vargsiukai, galvociai);
		surusiuok2(studinfo, vargsiukai);
		end = chrono::system_clock::now();
		elapsed_seconds = end - start;
		cout << "Failo su " << kiekis << " duomenu suskirstymas i galvocius ir vargsiukus uztruko: " << elapsed_seconds.count() << "s\n";
	}
	catch (exception) {
		cout << "Ivyko klaida nuskaitant ir rusiuojant List tipo faila! \n";
	}
	string pavadinimasV = "vargsiukai" + to_string(kiekis) + ".txt";
	string pavadinimasG = "galvociai" + to_string(kiekis) + ".txt";

	try {
		//1 budas:
		isvedimas(vargsiukai, VargsiukuKiekis, pavadinimasV);
		isvedimas(galvociai, GalvociuKiekis, pavadinimasG);

		//2 budas:
		isvedimas(vargsiukai, VargsiukuKiekis, pavadinimasV);
		isvedimas(studinfo, GalvociuKiekis, pavadinimasG);
	}
	catch (exception) {
		cout << "Ivyko klaida nuskaitant ir rusiuojant List tipo faila! \n";
	}


	endEvent = chrono::system_clock::now();
	elapsed_seconds = endEvent - startEvent;
	cout << "Failo su " << kiekis << " duomenu testo laikas: " << elapsed_seconds.count() << "s\n\n";
}


string generuoti(list<studentas> studinfo, int kiekis)
{
	int ndKiekis = 3;
	studinfo = {}; // nunulinam struktura
	random_device rd;
	mt19937 mt(rd()); //generuojami atsitiktiniai rezultatai
	uniform_real_distribution<double> balai(1.0, 10.0);
	//double egzas;
	string outrawfile = "rawfile" + to_string(kiekis) + ".txt";
	double vidurkis = 0;
	ofstream rawfile(outrawfile);
	list <studentas>::iterator it;
	it = studinfo.begin();
	rawfile << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(5) << "Vidurkis" << endl;
	//rawfile << left << "----------------------------------------------------------" << endl;
	for (int i = 0; i <= kiekis; i++) {
		for (int j = 0; j < ndKiekis; j++) {
			vidurkis += balai(mt);
		}
		vidurkis /= 3.00;
		rawfile << left << setw(20) << "Vardas" + to_string(i) << setw(20) << "Pavarde" + to_string(i) << setw(5) << setprecision(3) << vidurkis << endl;
		vidurkis = 0;
	}
	return outrawfile;
}
void nuskaityti(list<studentas>& studinfo, int kiekis, string failas)
{
	ifstream autoIn(failas);
	string ignore;
	autoIn >> ignore >> ignore >> ignore;

	for (int i = 0; i < kiekis; i++) {
		studentas S;
		autoIn >> S.Vardas >> S.Pavarde >> S.Egzaminas;
		studinfo.push_back(S);
	}

}
void surusiuok(list<studentas>& studinfo, int kiekis, int& VargsiukuKiekis, int& GalvociuKiekis, list<studentas>& vargsiukai, list<studentas>& galvociai)
{
	list <studentas>::iterator it;
	list <studentas>::iterator vit;
	list <studentas>::iterator git;
	it = studinfo.begin();
	vit = vargsiukai.begin();
	git = galvociai.begin();
	while (it != studinfo.end()) {
		if (it->Egzaminas < 5.00) {
			vit->Vardas = it->Vardas;
			vit->Pavarde = it->Pavarde;
			vit->Egzaminas = it->Egzaminas;
			vit++;
		}
		else {
			git->Vardas = it->Vardas;
			git->Pavarde = it->Pavarde;
			git->Egzaminas = it->Egzaminas;
			git++;
		}
		it++;
	}
}
void isvedimas(vector<studentas> vektorius, string failoPav = "rawfile.txt") // atspausdina automatiskai sugeneruotus duomenis
{
	try {
		ofstream offile(failoPav);
		offile << "Vardas             Pavarde              Galutinis (egz.)\n";
		offile << "--------------------------------------------------------\n";
		for (int i = 0; i < vektorius.size(); i++) {
			offile << left << setw(20) << vektorius[i].Vardas << setw(20) << vektorius[i].Pavarde << setw(20) << setprecision(3) << vektorius[i].Egzaminas << endl;
		}
	}
	catch (std::exception& e) {
		cout << "Ivyko klaida vector failo isvedime \n";
	}
}
void isvedimas(list<studentas>& listas, int kiekis, string failoPav = "rezultatai.txt") // isvedimas auto sugeneruotiems
{
	ofstream offile(failoPav);
	offile << "Pavarde             Vardas              Galutinis (egz.)\n";
	offile << "--------------------------------------------------------\n";

	for (studentas l : listas) {
		offile << left << setw(20) << l.Vardas << setw(20) << l.Pavarde << setw(20) << setprecision(3) << l.Egzaminas << endl;
	}
}

void rusiuoti(list<studentas>& studinfo, int kiekis)
{
	studinfo.sort(maziau);
}
void rusiuoti(vector<studentas>& studinfo)
{
	try {
		sort(studinfo.begin(), studinfo.end(), maziau);
	}
	catch (std::exception& e) {
		cout << "Ivyko klaida rusiuojant vector tipo faila! \n";
	}
}
bool maziau(const studentas& a, const studentas& b)
{
	return a.Egzaminas < b.Egzaminas;
}
void sortList(list<studentas>& studinfo, list<studentas>& vargsiukai, list<studentas>& galvociai)
{
	for (studentas l : studinfo) {
		if (l.Egzaminas >= 5.00) {
			galvociai.push_back(l);
		}
		else {
			vargsiukai.push_back(l);
		}
	}
}
void vectTesting(vector<studentas>& vargsiukai, vector<studentas>& galvociai, vector<studentas>& studinfo, int kiekis)
{
	// studentu rusiavimas i dvi grupes
	studinfo.reserve(kiekis);
	vargsiukai.reserve(kiekis);
	galvociai.reserve(kiekis);
	//studinfo.resize(kiekis);
	//vargsiukai.resize(kiekis);
	//galvociai.resize(kiekis);
	chrono::time_point<chrono::system_clock> start, end;
	chrono::time_point<chrono::system_clock> startEvent, endEvent;
	chrono::duration<double> elapsed_seconds;

	int VargsiukuKiekis, GalvociuKiekis;
	string failas;

	startEvent = chrono::system_clock::now();
	try {
		failas = generuoti(studinfo, kiekis);
	}
	catch (exception) {
		cout << "Klaida generuojant Vector faila! \n";
	}

	try {
		start = chrono::system_clock::now();
		nuskaityti(studinfo, kiekis, failas);
		end = chrono::system_clock::now();
		elapsed_seconds = end - start;
		cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";
	}
	catch (exception) {
		cout << "Ivyko klaida nuskaitant Vector faila! \n";
	}

	try {
		start = chrono::system_clock::now();
		rusiuoti(studinfo);
		//GalvociuKiekis = 0;
		//VargsiukuKiekis = 0;
		//surusiuok(studinfo, kiekis, GalvociuKiekis, VargsiukuKiekis, vargsiukai, galvociai);
		//surusiuok2(studinfo, vargsiukai);
		surusiuok3(studinfo, vargsiukai);
		end = chrono::system_clock::now();
		elapsed_seconds = end - start;
		cout << "Failo su " << kiekis << " duomenu suskirstymas i galvocius ir vargsiukus uztruko: " << elapsed_seconds.count() << "s\n";
	}
	catch (exception) {
		cout << "Ivyko klaida nuskaitant ir rusiuojant Vector tipo faila! \n";
	}


	string pavadinimasV = "vargsiukai" + to_string(kiekis) + ".txt";
	string pavadinimasG = "galvociai" + to_string(kiekis) + ".txt";

	try {
		// 1 budas: naudojamas surusiuok() funkcija
		//spausdinti(vargsiukai, GalvociuKiekis, pavadinimasV);
		//spausdinti(galvociai, VargsiukuKiekis, pavadinimasG);
		
		// 2 budas: naudojamas su surusiuok2()
		isvedimas(vargsiukai, pavadinimasV);
		isvedimas(studinfo, pavadinimasG);
	}
	catch (exception) {
		cout << "Ivyko klaida isvedant vector tipo faila! \n";
	}

	endEvent = chrono::system_clock::now();
	elapsed_seconds = endEvent - startEvent;
	cout << "Failo su " << kiekis << " duomenu testo laikas: " << elapsed_seconds.count() << "s\n\n";
}
void surusiuok2(list<studentas>& studinfo, list<studentas>& vargsiukai)
{
	list<studentas>::iterator it = std::find_if(studinfo.begin(), studinfo.end(), arlygu5); // iteratorius, rodantis kurioje vietoje egzaminas lygus 5
	vargsiukai.splice(vargsiukai.begin(), studinfo, studinfo.begin(), it);

}
bool arlygu5(const studentas& v)
{
	return v.Egzaminas == 5.00;
}
void surusiuok2(vector<studentas>& studinfo, vector<studentas>& vargsiukai)
{
	try {
		for (int i = 0; i < studinfo.size(); i++) {
			if (studinfo[i].Egzaminas < 5.00) {
				vargsiukai.push_back(studinfo[i]);
			}
			else {
				studinfo.erase(studinfo.begin(), studinfo.begin() + i);
				break;
			}
		}
	}
	catch (std::exception& e) {
		cout << "Ivyko klaida vector failo skirstyme \n";
	}
}
void surusiuok3(vector<studentas>& studinfo, vector<studentas>& vargsiukai)
{
	try {
		vector<studentas>::iterator it = find_if(studinfo.begin(), studinfo.end(), arlygu5); // iteratorius, rodantis kurioje vietoje perkirsti sarasus

		vargsiukai = vector<studentas>(studinfo.begin(), it); // nukopijuoja
		studinfo.erase(studinfo.begin(), it); // istrina is studinfo vargsiukus ir taip gaunami galvociai
	}
	catch (std::exception& e) {
		cout << "Ivyko klaida vector failo skirstyme \n";
	}
}
void surusiuok(vector<studentas>& studinfo, vector<studentas>& vargsiukai, vector<studentas>& galvociai)
{
	for (int i = 0; i < studinfo.size(); i++) {
		if (studinfo[i].Egzaminas < 5.00) {
			vargsiukai.push_back(studinfo[i]);
		}
		else {
			galvociai.push_back(studinfo[i]);
		}
	}
}