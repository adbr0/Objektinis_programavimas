#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include "studentas.h"
#include <vector>
#include <string>
#include <list>

void nuskaitymas(std::vector<studentas>&grupe, const std::string&failas);
void ivestis_r(std::vector<studentas>& grupe);
void generuoti_paz(std::vector<studentas>& grupe);
void rezultatai(const std::vector<studentas>& grupe);
void generuoti_failus();
void padalinti_studentai(const std::vector<studentas>& grupe, std::vector<studentas>& vargsiukai, std::vector<studentas>& kietekai);
void failo_isv(const std::string& pavadinimas, const std::vector<studentas>& grupe);
void sparta();
void rusiavimas(std::vector<studentas>& grupe, int r_pasirinkimas);


void nuskaitymas_list(std::list<studentas>& grupe, const std::string& failas);
void padalinti_studentai_list(const std::list<studentas>& grupe, std::list<studentas>& vargsiukai, std::list<studentas>& kietekai);
void failo_isv_list(const std::string& pavadinimas, const std::list<studentas>& grupe);
void sparta_list();

#endif // FUNKCIJOS_H_INCLUDED
