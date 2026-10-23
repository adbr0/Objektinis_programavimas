---

## [v0.3] – Konteinerių spartos analizė: std::vector vs std::list

### Sistemos specifikacija:
* **CPU:** 13th Gen Intel(R) Core(TM) i7-1365U
* **RAM:** 32.0 GB LPDDR5
* **Storage:** SAMSUNG MZVL21T0HDLU-00BLL 
* **Kompiliatorius:** GCC (Code::Blocks aplinkoje)

### Tyrimo metodika:
* Tyrimas atliktas su 5 duomenų failais (1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 įrašų).
* Kiekvienam konteineriui atlikti 3 bandymai, lentelėje pateikiami apskaičiuoti vidurkiai sekundėmis.

---

### Spartos tyrimo rezultatų palyginimas (vidurkiai):

| Įrašų kiekis | Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :--- | :---: | :---: | :---: |
| **1 000** | Duomenų nuskaitymas | 0.0035 s | 0.0114 s | std::vector |
| | Rūšiavimas | 0.0008 s | 0.0003 s | std::list |
| | Dalijimas į 2 grupes | 0.0003 s | 0.0006 s | std::vector |
| | Išvedimas į failus | 0.0037 s | 0.0060 s | std::vector |
| | **Bendras laikas** | **0.0084 s** | **0.0183 s** | **std::vector** |
| **10 000** | Duomenų nuskaitymas | 0.0159 s | 0.0463 s | std::vector |
| | Rūšiavimas | 0.0064 s | 0.0032 s | std::list |
| | Dalijimas į 2 grupes | 0.0023 s | 0.0039 s | std::vector |
| | Išvedimas į failus | 0.0114 s | 0.0228 s | std::vector |
| | **Bendras laikas** | **0.0360 s** | **0.0762 s** | **std::vector** |
| **100 000** | Duomenų nuskaitymas | 0.1326 s | 0.2745 s | std::vector |
| | Rūšiavimas | 0.0838 s | 0.0337 s | std::list |
| | Dalijimas į 2 grupes | 0.0151 s | 0.0373 s | std::vector |
| | Išvedimas į failus | 0.1107 s | 0.2343 s | std::vector |
| | **Bendras laikas** | **0.3442 s** | **0.5798 s** | **std::vector** |
| **1 000 000** | Duomenų nuskaitymas | 1.3565 s | 2.7478 s | std::vector |
| | Rūšiavimas | 1.1667 s | 0.4358 s | std::list |
| | Dalijimas į 2 grupes | 0.1985 s | 0.3741 s | std::vector |
| | Išvedimas į failus | 1.2504 s | 2.3098 s | std::vector |
| | **Bendras laikas** | **3.9722 s** | **5.8675 s** | **std::vector** |
| **10 000 000** | Duomenų nuskaitymas | 15.8594 s | 27.9072 s | std::vector |
| | Rūšiavimas | 16.5368 s | 6.9703 s | std::list |
| | Dalijimas į 2 grupes | 2.2394 s | 4.7069 s | std::vector |
| | Išvedimas į failus | 14.9393 s | 24.5081 s | std::vector |
| | **Bendras laikas** | **49.5882 s** | **64.0924 s** | **std::vector** |

---

### Tyrimo išvada:
**Bendroji sparta ir įvestis/išvestis:** `std::vector` bendras veikimo laikas visais atvejais buvo mažesnis nei `std::list`. Duomenų nuskaitymas ir įrašymas su vektoriumi vyko beveik dvigubai greičiau.
