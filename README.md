
---
## Testavimo aplinkos sistemos specifikacijos:
* Procesorius(CPU): 13th Gen Intel(R) Core(TM) i7-1365U
* Operatyvioji atmintis(RAM): 32.0 GB LPDDR5
* Diskas(Storage): SAMSUNG MZVL21T0HDLU-00BLL
* Kompiliatorius: GCC (Code::Blocks aplinkoje)
---
## Versijos
### [v0.1]
* Pradinė realizacija su rankiniu duomenų įvedimu, atsitiktinių pažymių generavimu ir nuskaitymu iš failo.
* Galutinio balo skaičiavimas pagal vidurkį arba medianą.
* Rezultatų pateikimas formatuotoje konsolės lentelėje.

### [v0.2]
* Kodas išskaidytas į `studentas.h/cpp`, `funkcijos.h/cpp` ir `main.cpp`.
* Funkcija, sukurianti 5 testinius failus (nuo 1 000 iki 10 000 000 įrašų).
* Realizuotas rūšiavimas pagal naudotojo pasirinktą parametrą (pavardę, vardą, galutinį balą) bei skaidymas į `vargsiukai.txt` (< 5.0) ir `kietekai.txt` (>= 5.0).
* Atliktas I/O ir apdorojimo laiko tyrimas naudojant `<chrono>`.

## Spartos tyrimo rezultatai:
Tyrimas atliktas paleidus testą 3 kartus su iš anksto sugeneruotais duomenų failais. 
Lentelėse pateikti laikai sekundėmis ir jų aritmetinis vidurkis.

#### 1 000 įrašų
| Operacija | 1 bandymas (s) | 2 bandymas (s) | 3 bandymas (s) | Vidurkis (s) |
| :--- | :---: | :---: | :---: | :---: |
| Duomenų nuskaitymas | 0.0031 | 0.0036 | 0.0039 | 0.0035 |
| Rūšiavimas su `std::sort` | 0.0007 | 0.0008 | 0.0009 | 0.0008 |
| Dalijimas į 2 grupes | 0.0003 | 0.0003 | 0.0004 | 0.0003 |
| Išvedimas į 2 failus | 0.0055 | 0.0032 | 0.0026 | 0.0037 |
| **Bendras laikas** | **0.0097** | **0.0080** | **0.0077** | **0.0084** |

#### 10 000 įrašų
| Operacija | 1 bandymas (s) | 2 bandymas (s) | 3 bandymas (s) | Vidurkis (s) |
| :--- | :---: | :---: | :---: | :---: |
| Duomenų nuskaitymas | 0.0186 | 0.0146 | 0.0147 | 0.0159 |
| Rūšiavimas su `std::sort` | 0.0062 | 0.0064 | 0.0067 | 0.0064 |
| Dalijimas į 2 grupes | 0.0023 | 0.0022 | 0.0023 | 0.0023 |
| Išvedimas į 2 failus | 0.0113 | 0.0115 | 0.0113 | 0.0114 |
| **Bendras laikas** | **0.0384** | **0.0346** | **0.0349** | **0.0360** |

#### 100 000 įrašų
| Operacija | 1 bandymas (s) | 2 bandymas (s) | 3 bandymas (s) | Vidurkis (s) |
| :--- | :---: | :---: | :---: | :---: |
| Duomenų nuskaitymas | 0.1345 | 0.1325 | 0.1307 | 0.1326 |
| Rūšiavimas su `std::sort` | 0.0832 | 0.0830 | 0.0853 | 0.0838 |
| Dalijimas į 2 grupes | 0.0116 | 0.0170 | 0.0168 | 0.0151 |
| Išvedimas į 2 failus | 0.1108 | 0.1116 | 0.1097 | 0.1107 |
| **Bendras laikas** | **0.3459** | **0.3441** | **0.3425** | **0.3442** |

#### 1 000 000 įrašų
| Operacija | 1 bandymas (s) | 2 bandymas (s) | 3 bandymas (s) | Vidurkis (s) |
| :--- | :---: | :---: | :---: | :---: |
| Duomenų nuskaitymas | 1.3810 | 1.3424 | 1.3461 | 1.3565 |
| Rūšiavimas su `std::sort` | 1.1268 | 1.2363 | 1.1371 | 1.1667 |
| Dalijimas į 2 grupes | 0.1849 | 0.1827 | 0.2278 | 0.1985 |
| Išvedimas į 2 failus | 1.1555 | 1.3918 | 1.2040 | 1.2504 |
| **Bendras laikas** | **3.8482** | **4.1533** | **3.9150** | **3.9722** |

#### 10 000 000 įrašų
| Operacija | 1 bandymas (s) | 2 bandymas (s) | 3 bandymas (s) | Vidurkis (s) |
| :--- | :---: | :---: | :---: | :---: |
| Duomenų nuskaitymas | 15.0045 | 16.7690 | 15.8046 | 15.8594 |
| Rūšiavimas su `std::sort` | 16.6471 | 15.8417 | 17.1216 | 16.5368 |
| Dalijimas į 2 grupes | 2.0311 | 2.3545 | 2.3327 | 2.2394 |
| Išvedimas į 2 failus | 14.1676 | 14.7781 | 15.8722 | 14.9393 |
| **Bendras laikas** | **47.8903** | **49.7433** | **51.1311** | **49.5882** |
---
### Testavimo eigos ekrano nuotraukos:
#### 1 bandymas
<img width="442" height="485" alt="image" src="https://github.com/user-attachments/assets/b2c1c174-4933-4191-9483-9a486f9fe922" />

#### 2 bandymas
<img width="440" height="494" alt="image" src="https://github.com/user-attachments/assets/e7097d10-b2fb-4322-bba1-119ec3993a17" />

#### 3 bandymas
<img width="431" height="491" alt="image" src="https://github.com/user-attachments/assets/1cbe4d06-e813-4ae9-b1cf-0b868baed219" />

---
## Išvados
1. Didžiąją dalį bendro vykdymo laiko užima duomenų nuskaitymas ir įrašymas į failus.
2. Duomenų skaidymas į du atskirus vektorius atmintyje yra sparčiausia operacija.
