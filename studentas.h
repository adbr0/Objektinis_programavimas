#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include <vector>
#include <string>

struct studentas {

    std::string vardas, pavarde;
    std::vector<int> pazymys;
    int egzaminas = 0;
    double galutinisv = 0.0;
    double galutinism = 0.0;
};

double vidurkis(const std::vector<int>& pazymiai);
double mediana(std::vector<int> pazymiai);
void galutinis(studentas& a);

#endif // STUDENTAS_H_INCLUDED
