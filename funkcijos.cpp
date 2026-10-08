#include "funkcijos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

void nuskaitymas(std::vector<studentas>&grupe, const std::string&pavadinimas)
{
    std::ifstream failas(pavadinimas);
    if (!failas) {
        std::cout << "Nepavyko atidaryti failo: " << pavadinimas << "\n";
        return;
    }

    std::string eilute;
    std::getline(failas, eilute);

    while (std::getline(failas, eilute)) {
        if (eilute.empty()) continue;
        std::istringstream iss(eilute);
        studentas A;
        if (!(iss >> A.vardas >> A.pavarde)) continue;

        std::vector<int> skaiciai;
        int skaicius;
        while (iss >> skaicius) {
            skaiciai.push_back(skaicius);
        }
        if (skaiciai.size() < 2) continue;

        A.egzaminas = skaiciai.back();
        skaiciai.pop_back();
        A.pazymys = skaiciai;

        galutinis(A);
        grupe.push_back(A);
    }
    failas.close();

}

void ivestis_r(std::vector<studentas>& grupe)
{
    while (true) {
        studentas A;
        std::cout << "Iveskite per tarpa studento varda ir pavarde: ";
        std::cin >> A.vardas >> A.pavarde;

        while (true) {
            int l;
            std::cout << "Iveskite namu darbu pazymi: ";
            std::cin >> l;

            while (std::cin.fail() || l < 1 || l > 10) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10: ";
                std::cin >> l;
            }
            A.pazymys.push_back(l);

            char klausimas;
            while (true) {
                std::cout << "Ar studentas dar turi pazymiu? (t/n): ";
                std::cin >> klausimas;
                if (klausimas == 't' || klausimas == 'T' || klausimas == 'n' || klausimas == 'N') break;
                std::cout << "Neteisingas pasirinkimas. Iveskite t arba n.\n";
            }
            if (klausimas == 'n' || klausimas == 'N') break;
        }

        std::cout << "Iveskite studento egzamino rezultata: ";
        std::cin >> A.egzaminas;
        while (std::cin.fail() || A.egzaminas < 1 || A.egzaminas > 10) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10: ";
            std::cin >> A.egzaminas;
        }

        galutinis(A);
        grupe.push_back(A);

        char klausimas;
        while (true) {
            std::cout << "Ar dar yra studentu? (t/n): ";
            std::cin >> klausimas;
            if (klausimas == 't' || klausimas == 'T' || klausimas == 'n' || klausimas == 'N') break;
            std::cout << "Neteisingas pasirinkimas. Iveskite t arba n.\n";
        }
        if (klausimas == 'n' || klausimas == 'N') break;
    }

}

void generuoti_paz(std::vector<studentas>& grupe)
{
    while (true) {
        studentas A;
        std::cout << "Iveskite per tarpa studento varda ir pavarde: ";
        std::cin >> A.vardas >> A.pavarde;
        int skaicius = std::rand() % 8 + 3;

        for (int i = 0; i < skaicius; i++) {
            A.pazymys.push_back(std::rand() % 10 + 1);
        }
        A.egzaminas = std::rand() % 10 + 1;

        galutinis(A);
        grupe.push_back(A);

        char klausimas;
        while (true) {
            std::cout << "Ar dar yra studentu? (t/n): ";
            std::cin >> klausimas;
            if (klausimas == 't' || klausimas == 'T' || klausimas == 'n' || klausimas == 'N') break;
            std::cout << "Neteisingas pasirinkimas. Iveskite t arba n.\n";
        }
        if (klausimas == 'n' || klausimas == 'N') break;
    }
}

void rezultatai(const std::vector<studentas>& grupe)
{
    std::cout << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas"
              << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << "\n";

    for (int i = 0; i < 70; i++) std::cout << "-";
    std::cout << "\n";

    for (const auto& B : grupe) {
        std::cout << std::left << std::setw(15) << B.pavarde << std::setw(15)
                  << B.vardas << std::fixed << std::setprecision(2)
                  << std::setw(20) << B.galutinisv << std::setw(20) << B.galutinism << "\n";
    }
}
