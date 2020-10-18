#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <string>
#include <iterator>
#include <chrono>
#include <random>
#define DYDIS 50//DYDIS YRA 50 ELEMENTU MASYVAS
using namespace std;
#include "struktura.h"
double findMedian(vector<int> v, int n);
void pasirink();
void spausdink(vector<studentas> i, int sk, int pasirinkimas);
string generuoti(vector<studentas>& studinfo, int kiekis);
void nuskaityti(vector<studentas>& studinfo, int kiekis, string failas);
void surusiuok(vector<studentas>& studinfo, int kiekis, int& VargsiukuKiekis, int& GalvociuKiekis, vector<studentas>& vargsiukai, vector<studentas>& galvociai);
void spausdinti(vector<studentas> vektorius, int kiekis, string failoPav);
void dalykai(vector<studentas>& vargsiukai, vector<studentas>& galvociai, vector<studentas>& studinfo, int kiekis);