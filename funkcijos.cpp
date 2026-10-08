#include "funkcijos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include <chrono>
#include <algorithm>

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
void generuoti_failus()
{
    std::vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000};
    const int nd_kiekis = 5;
    for(int kiekis : dydziai)
    {
        std::string pavadinimas = "studentai_" + std::to_string(kiekis) + ".txt";
        if (std::filesystem::exists(pavadinimas))
        {
            std::cout << "Failas '" << pavadinimas << "' jau egzistuoja \n";
            continue;
        }
        std::cout <<"Generuojamas failas: "<< pavadinimas;

        auto pradzia = std::chrono::high_resolution_clock::now();

        std::ofstream failas(pavadinimas);
        if(!failas)
        {
            std::cout<<"Klaida kuriant faila\n";
            continue;
        }

        failas<<std::left<<std::setw(15)<<"Vardas"<<std::setw(15)<<"Pavarde";
        for(int i=1; i<=nd_kiekis; i++)
        {
            failas<<std::setw(8)<<("nd" + std::to_string(i));
        }
        failas<<std::setw(8)<<"Egz."<<"\n";

        for(int i=1; i<= kiekis; i++)
        {
            failas << std::left<<std::setw(15) <<("Vardas"+std::to_string(i))<< std::setw(15) <<("Pavarde"+std::to_string(i));
            for(int j=0; j<nd_kiekis; j++)
            {
                failas<<std::setw(8)<<(std::rand()%10+1);
            }
            failas<<std::setw(8)<<(std::rand()%10+1)<<"\n";
        }
        failas.close();

        auto pabaiga = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> trukme = pabaiga-pradzia;
        std::cout<<"Generavimas baigtas per: "<<std::fixed<<std::setprecision(4)<<trukme.count()<< " s.\n";

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
void padalinti_studentai(const std::vector<studentas>& grupe, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietekai)
{
    vargsiukai.clear();
    kietekai.clear();
    for(const auto& a:grupe)
    {
        if(a.galutinisv<5.0){vargsiukai.push_back(a);}
        else{kietekai.push_back(a);};
    }
}
void failo_isv(const std::string& pavadinimas, const std::vector<studentas>& grupe)
{
    std::ofstream failas(pavadinimas);
    if (!failas) {
        std::cout << "Nepavyko sukurti failo " << pavadinimas << "\n";
        return;
    }

    failas << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas"
              << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << "\n";
    for (int i = 0; i < 70; i++) failas << "-";
    failas << "\n";

     for (const auto& a : grupe) {
        failas << std::left << std::setw(15) << a.pavarde << std::setw(15)
                  << a.vardas << std::fixed << std::setprecision(2)
                  << std::setw(20) << a.galutinisv << std::setw(20) << a.galutinism << "\n";
    }
    failas.close();
}
void sparta(){
        std::vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000};
        std::cout<<"\n--- Programos sparta ---\n";

        for(int kiekis : dydziai)
    {
        std::string pavadinimas = "studentai_" + std::to_string(kiekis) + ".txt";
        if (!std::filesystem::exists(pavadinimas))
        {
            std::cout << "\nFailas '" << pavadinimas << "' nerastas \n";
            continue;
        }
        std::cout<<"\n Testuojamas failas: " << pavadinimas <<" ("<<kiekis<<") irasu\n";
        std::vector<studentas> grupe;

        auto bendra_pradzia=std::chrono::high_resolution_clock::now();
        auto t1 = std::chrono::high_resolution_clock::now();
        nuskaitymas(grupe, pavadinimas);
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> nuskaitymo_trukme=t2-t1;

        auto tr_1 = std::chrono::high_resolution_clock::now();
        std::sort(grupe.begin(), grupe.end(), [](const studentas& a, const studentas& b) {
            return a.pavarde < b.pavarde;
        });
        auto tr_2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_trukme=tr_2-tr_1;

        std::vector<studentas> vargsiukai;
        std::vector<studentas> kietekai;
        auto t3 = std::chrono::high_resolution_clock::now();
        padalinti_studentai(grupe, vargsiukai, kietekai);

        grupe.clear();
        grupe.shrink_to_fit();

        auto t4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> rusiavimo_trukme=t4-t3;

        auto t5 = std::chrono::high_resolution_clock::now();
        failo_isv("vargsiukai_" + std::to_string(kiekis) + ".txt", vargsiukai);
        failo_isv("kietekai_" + std::to_string(kiekis) + ".txt", kietekai);
        auto t6 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> isvedimo_trukme=t6-t5;

        auto bendra_pabaiga =std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> bendra_trukme=bendra_pabaiga-bendra_pradzia;

        std::cout<<"1. Nuskaitymas is failo: "<<std::fixed<<std::setprecision(4)<<nuskaitymo_trukme.count()<<" s.\n";
        std::cout<<"2. Rusiavimas didejimo tvarka: "<<std::fixed<<std::setprecision(4)<<sort_trukme.count()<<" s.\n";
        std::cout<<"3. Rusiavimas i 2 grupes: "<<std::fixed<<std::setprecision(4)<<rusiavimo_trukme.count()<<" s.\n";
        std::cout<<"4. Isvedimas i 2 failus: "<<std::fixed<<std::setprecision(4)<<isvedimo_trukme.count()<<" s.\n";
        std::cout<<"Bendras apdorojimo laikas: "<<std::fixed<<std::setprecision(4)<<bendra_trukme.count()<<" s.\n";


    }
}
void rusiavimas(std::vector<studentas>& grupe, int r_pasirinkimas)
{
    if (r_pasirinkimas==1)
    {
        std::sort(grupe.begin(), grupe.end(), [](const studentas&a, const studentas&b)
        {
            return a.pavarde<b.pavarde;
        });
    }
     if (r_pasirinkimas==2)
    {
        std::sort(grupe.begin(), grupe.end(), [](const studentas&a, const studentas&b)
        {
            return a.vardas<b.vardas;
        });
    }
     if (r_pasirinkimas==3)
    {
        std::sort(grupe.begin(), grupe.end(), [](const studentas&a, const studentas&b)
        {
            return a.galutinisv<b.galutinisv;
        });
    }

}

