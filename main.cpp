#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>
#include "studentas.h"

void nuskaitymas(std::vector<studentas>&grupe, std::ifstream&failas){

    std::string eilute;
    std::getline(failas,eilute);
    while(std::getline(failas, eilute))
    {
        std::istringstream iss(eilute);
        studentas A;
        if (!(iss >> A.vardas >> A.pavarde))
            {
            std::cout << "Klaidinga eilute: " << eilute << "\n";
            continue;
            }
        std::vector<int> skaiciai;
        int skaicius;
        while(iss>>skaicius)
        {
            skaiciai.push_back(skaicius);
        }
        if (skaiciai.size() < 2)
        {
            std::cout<<"Klaidinga eilute: "<< eilute <<"\n";
            continue;
        }
        A.egzaminas=skaiciai.back();
        for(int i=0; i<skaiciai.size()-1;i++)
        {
            A.pazymys.push_back(skaiciai[i]);
        }
        grupe.push_back(A);
    }
}
//void duomenu_generavimas(std::int kiekis, std::vector<studentas>)
//{
//    for(int i=0; i<kiekis; i++)
//    {
//
//    }
//
//}

int main()
{
        std::srand(std::time(nullptr));
        std::vector<studentas> grupe;
        int pasirinkimas;

        std::cout << "\nPasirinkite duomenu ivedimo buda:\n";
        std::cout << "1 Ivesti pazymius ranka\n";
        std::cout << "2 Generuoti pazymius atsitiktinai\n";
        std::cout << "3 Nuskaityti duomenis is failo\n";
        std::cout << "Pasirinkimas: ";
        std::cin >> pasirinkimas;
        while(pasirinkimas<1 || pasirinkimas>3)
        {
            std::cout<<"Neteisingas pasirinkimas\n";
            std::cout << "Naujas pasirinkimas: "; std::cin >> pasirinkimas;

        }

        if(pasirinkimas == 1)
    {
        while(true)
        {
            studentas A;
        std::cout<<"Iveskite per tarpa studento varda ir pavarde: ";
        std::cin>>A.vardas>>A.pavarde;


        while(true){
        int l;
        std::cout<<"Iveskite namu darbu pazymi : ";
        std::cin>>l;

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
        if (klausimas == 't' || klausimas == 'T') break;

        if (klausimas == 'n' || klausimas == 'N') break;
        std::cout << "Neteisingas pasirinkimas. Iveskite t arba n.\n";
        }
        if(klausimas == 'n' || klausimas== 'N') break;
        }


        std::cout<<"Iveskite studento egzamino rezultata: "; std::cin>>A.egzaminas;
        while (std::cin.fail() || A.egzaminas < 1 || A.egzaminas > 10) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10: ";
                std::cin >> A.egzaminas;
} grupe.push_back(A);
    char klausimas;
    while (true) {
    std::cout << "Ar dar yra studentu? (t/n): ";
    std::cin >> klausimas;
    if (klausimas == 't' || klausimas == 'T') break;

    if (klausimas == 'n' || klausimas == 'N') break;
    std::cout << "Neteisingas pasirinkimas. Iveskite t arba n.\n";
    }
    if(klausimas == 'n' || klausimas== 'N') break;
    }
}
    else if(pasirinkimas == 2){
    while(true){
        studentas A;
        std::cout<<"Iveskite per tarpa studento varda ir pavarde: ";
        std::cin>>A.vardas>>A.pavarde;
        int skaicius = std::rand()%8 +3;

        for(int i=0; i<skaicius; i++)
        {
            int pazymys;
            pazymys=std::rand()%10 +1;
            A.pazymys.push_back(pazymys);
        }
        A.egzaminas=std::rand()%10 +1;
        grupe.push_back(A);

        char klausimas;
        while (true) {
        std::cout << "Ar dar yra studentu? (t/n): ";
        std::cin >> klausimas;
        if (klausimas == 't' || klausimas == 'T') break;
        if (klausimas == 'n' || klausimas == 'N') break;
        std::cout << "Neteisingas pasirinkimas. Iveskite t arba n.\n";
    }
        if(klausimas=='n' || klausimas == 'N') break;
    }
}
    else if (pasirinkimas == 3)
    {
        std::string pavadinimas;
        std::cout<<"Iveskite failo pavadinima su .txt: "; std::cin>>pavadinimas;
        std::ifstream failas(pavadinimas);
        if (!failas) {
        std::cout << "Nepavyko atidaryti failo\n";
        return 1;
        }
        nuskaitymas(grupe, failas);
        failas.close();
    }

    std::sort(grupe.begin(), grupe.end(), [] (const studentas&a, const studentas&b){return a.pavarde < b.pavarde;});
    std::cout << std::left<< std::setw(15) << "Pavarde"<< std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << "\n";

    for(int i = 0; i < 70; i++) {
    std::cout << "-";
    }
    std::cout << "\n";

   for(auto B: grupe){
        galutinis(B);
        std::cout << std::left << std::setw(15) << B.pavarde << std::setw(15)
        << B.vardas << std::fixed << std::setprecision(2) << std::setw(20) << B.galutinisv << std::setw(20) << B.galutinism << "\n";
    }
}
