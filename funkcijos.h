#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include "studentas.h"
#include <vector>
#include <string>

void nuskaitymas(std::vector<studentas>&grupe, const std::string&failas);
void ivestis_r(std::vector<studentas>& grupe);
void generuoti_paz(std::vector<studentas>& grupe);
void rezultatai(const std::vector<studentas>& grupe);
void generuoti_failus();
void padalinti_studentai(const std::vector<studentas>& grupe, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietekai);
void failo_isv(const std::string& pavadinimas, const std::vector<studentas>& grupe);


#endif // FUNKCIJOS_H_INCLUDED
