#include "studentas.h"
#include <algorithm>
#include <numeric>

double vidurkis(const std::vector<int>& pazymiai)
{
    if(pazymiai.empty()) return 0.0;
    double suma = std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
    return suma / pazymiai.size();
}
double mediana(std::vector<int> pazymiai)
{
     if(pazymiai.empty()) return 0.0;
     std::sort(pazymiai.begin(), pazymiai.end());
     size_t n = pazymiai.size();
     if (n%2 == 0)
     {
         return (pazymiai[n/2-1]+pazymiai[n/2])/ 2.0;
     }
     return pazymiai[n/2];
}
void galutinis(studentas& a)
{
    double vid = vidurkis(a.pazymys);
    double med = mediana(a.pazymys);
    a.galutinisv = 0.4*vid + 0.6*a.egzaminas;
    a.galutinism = 0.4*med + 0.6*a.egzaminas;
}
