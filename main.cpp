#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "studentas.h"
#include "funkcijos.h"

int main()
{
        std::srand(std::time(nullptr));
        std::vector<studentas> grupe;
        int pasirinkimas;
        std::cout << "\nPasirinkite duomenu ivedimo buda:\n";
        std::cout << "1. Ivesti pazymius ranka\n";
        std::cout << "2. Generuoti pazymius atsitiktinai\n";
        std::cout << "3. Nuskaityti duomenis is failo\n";
        std::cout << "4. Sugeneruoti 5 testinius studentu failus\n";
        std::cout << "5. Spartos tyrimas\n";
        std::cout << "Pasirinkimas: ";
        std::cin >> pasirinkimas;
        while(std::cin.fail() || pasirinkimas<1 || pasirinkimas>5)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<"Neteisingas pasirinkimas\n";
            std::cout << "Naujas pasirinkimas: "; std::cin >> pasirinkimas;

        }

        if(pasirinkimas == 1)
    {
        ivestis_r(grupe);
    }
    else if(pasirinkimas == 2){
        generuoti_paz(grupe);
    }
    else if (pasirinkimas == 3)
    {
        std::string pav;
        std::cout<<"Iveskite failo pavadinima su .txt: "; std::cin>>pav;
        nuskaitymas(grupe, pav);
    }
    else if(pasirinkimas==4)
    {
        generuoti_failus();
        std::cout<<"Failai paruosti\n";
        return 0;
    }
    else if(pasirinkimas==5)
    {
        sparta();
        return 0;
    }
    if(!grupe.empty())
    {
       int r_pasirinkimas;
        std::cout << "\nPasirinkite rusiavimo buda:\n";
        std::cout << "1. Pagal pavarde\n";
        std::cout << "2. Pagal varda\n";
        std::cout << "3. Pagal galutini bala\n";
        std::cin >> r_pasirinkimas;
         while(std::cin.fail() || r_pasirinkimas<1 || r_pasirinkimas>3)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<"Neteisingas pasirinkimas\n";
            std::cout << "Naujas pasirinkimas: "; std::cin >> r_pasirinkimas;

        }

        rusiavimas(grupe, r_pasirinkimas);
        if (pasirinkimas == 1 || pasirinkimas==2)
        {
            rezultatai(grupe);
        }
        std::vector<studentas> vargsiukai;
        std::vector<studentas> kietekai;
        padalinti_studentai(grupe, vargsiukai, kietekai);
        failo_isv("vargsiukai.txt", vargsiukai);
        failo_isv("kietekai.txt", kietekai);
        std::cout<<"\n Studentai padalinti ir isvesti i failus:\n";
        std::cout<<"1. 'vargsiukai.txt' "<< vargsiukai.size() <<" studentu\n";
        std::cout<<"2. 'kietekai.txt' "<< kietekai.size() <<" studentu\n";
    }

    return 0;
}
