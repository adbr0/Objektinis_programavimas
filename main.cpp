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

    std::sort(grupe.begin(), grupe.end(), [] (const studentas&a, const studentas&b){return a.pavarde < b.pavarde;});
    rezultatai(grupe);
}
