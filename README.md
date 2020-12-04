# V0.1 V0.2 Versija

# Programos esmė:
1. Leidžia vartotojui pasirinkti: ar duomenis nuskaityti iš failo, ar juos įrašyti pačiam.
1. Programa saugo vartotojo įvestus studentų duomenis: (vardas, pavardė,
egzamino rezultatas, namų darbų rezultatai, vidurkis, mediana, galutinis pažymys).
2. Skaičiuoja vidurkį, medianą.
3. Atspausdina duomenis: Vardas, Pavardė, Galutinis(Vid.)/Galutinis(Med.).
## Programos veikimas:
Jei vartotojas pasirinko, kad duomenis nuskenuotų iš failo:
1. Naudojant for ciklą, pirmiausia yra nuskenuojamas Vardas ir Pavardė, tada jam priskiriami 5 namų darbų pažymiai ir egzaminas.
2. Vartotojas prašomas pasirinkti pagal ką skaičiuoti Galutinį rezultatą: Pagal Medianą arba Pagal Vidurkį.
3. For ciklo viduje suskaičiuojamas vidurkis ir mediana.
4. Spausdinami stulpelių pavadinimai, nuskenuoti studentų vardai ir pavardės bei galutiniai rezultatai.

Jei vartotojas pasirinko, kad duomenis įrašytu pats:
1. Pirmiausia, vartotojas įveda skaičių, kiek studentų bus įrašyta.
2. Vartotojas įveda Vardą.
3. Vartotojas įveda Pavardę.
4. Vartotojo prašoma pasirinkti, generuoti egzamino rezultatą ar jį įvesti pačiam.
5. Vartotojo prašoma pasirinkti, generuoti namų darbų rezultatus ar juos įvesti pačiam.
6. Jei vartotojas pasirenka, kad namų darbų rezultatai būtų sugeneruoti programos,
vartotojas yra paprašomas įvesti norimą pažymių skaičių.
7. Programa atspausdina sugeneruotus studento pažymius.
8. Vartotojas prašomas pasirinkti pagal ką skaičiuoti Galutinį rezultatą: Pagal Medianą arba Pagal Vidurkį.
9. Apskaičiuojama Mediana ir ji atspausdinama ekrane bei apskaičiuojamas galutinis rezultatas.
10. Apskaičiuojamas Vidurkis ir jis atspausdinamas ekrane bei apskaičiuojamas galutinis rezultatas.
11. Pasirinkus įvesti didesnį kiekį studentų, programa yra kartojama iš naujo.
12. Spausdinami stulpeliu pavadinimai bei įvesti studentų duomenys.

# V0.3 ir V0.4 Versijos

# V0.3
## Kas padaryta?
1. Funkcijos ir strŪktūros pridėtos į headerius (struktura.h, funkcijos.h)
2. Daugelis funkcijų pridėtos į funkcijos.cpp failą
3. Panaudotas išimčių valdymas
# V0.4
## Kas padaryta?
1. Vartotojui siūloma pasirinkti: '1' - kad duomenys būtų sugeneruoti automatiškai, '0' - negeneruoti automatiškai.
2. Pasirinkus generuoti failus automatiškai, bus sukuriami studentų sąrašų failai, sudaryt iš: 1000, 10000, 100000, 1000000, 10000000 įrašų.
3. Sugeneruoti įrašai bus nuskaitomi iš duomenų į strūktūras.
4. Studentai bus surūšiuoti pagal pažymius ir išskirstomi: "vargšiukai",  jei (galutinis balas < 5), "galvočiai", (jei galutinis balas >= 5).
5. Programa išves du surūšiuotų studentų tekstinius failus: "vargsiukai.txt" ir "galvociai.txt".
6. Atlikta programos veikimo greičio analizė: išmatuota kiekviena programos sparta
7. Programos veikimo laikas yra įrašytas į V0.3 šaką, pavadinimu "laikas.png"
# V0.5
## Kas padaryta?
1. Dabar duomenys talpinami ne tik Vector bet ir List konteineryje.
2. Išvedama programos vector ir list konteinerių veikimo greičio analizė: duomenų nuskaitymas iš failų bei studentų surūšiavimas į dvi grupes.
3. Gauti rezultatai yra faile "KonteineriuTestavimas.png".
4. Testavimo sistemos parametrai: CPU: Intel Core i7-10510U, 4 cores RAM: 16GB, SSD: 512GB.
5. Programa buvo kurta MS Visual Studio x64. 
6. Galima paleisti V05.exe failą, kuris sukompiliuos programą.
# V1.0
## Kas padaryta?
1. Du būdai: 
a)iš bendro konteinerio išskirstyti į du papildomus
b) Iš bendro "studfile" konteinerio išrenkami vargšiukai, o bendrame konteineryje paliekami galvočiai. 
2. Programų testavimo nuotraukos yra įkeltos į ProgramosTestavimas folderį.
3. Vektoriams padidintas efektyvumas naudojant iteratorius ir find_if funkciją.
3. Makefile skirtas UNIX OS atveju.
# LIST
**Testavimo sistemos parametrai :** <br/>
CPU: i7-10510U 1.80 GHz <br/>
RAM: 16GB <br/>
HDD: 512GB <br/>
## Pirmos ir antros studentų dalijimo strategijų palyginimas :
| Studentų skaičius | Rūšiavimo laikas (1 būdas)  | Rūšiavimo laikas (2 būdas)  |
|-------------------|----------------------------------|----------------------------------|
|1000                |0.0002476 s                       |0.0001152 s                       |
|10000               |0.0031738 s                       |0.0018162 s                       |
|100000              |0.0580081 s                       |0.0473399 s                       |
|1000000             |0.942187 s                        |1.06754 s                         |
|10000000            |14.1784 s                         |16.8178 s                         |
 
**Išvados :** <br/>
Programą, realizuojant su listu, pradžioje (iki 1mln) greičiau rūšiuojama antru būdu, tačiau 1mln ir 10mln greičiau surūšiuoja pirmasis būdas.

# VECTOR
## Pirmo ir antro būdo studentų rūšiavimo palyginimas :
| Studentų skaičius | Rūšiavimo laikas (1 būdas)  | Rūšiavimo laikas (2 būdas)  |
|-------------------|----------------------------------|----------------------------------|
|1000                |0.0092423 s                       |0.0007012 s                       |
|10000               |0.0436779 s                       |0.0092825 s                       |
|100000              |0.309093 s                        |0.0714911 s                       |
|1000000             |3.1015 s                          |0.7924 s                          |
|10000000            |31.7478 s                         |8.21397 s                         |
 
**Išvados :** <br/>
Aiškiai matoma, jog antru būdu, studentai rūšiuojami žymiai greičiau.
