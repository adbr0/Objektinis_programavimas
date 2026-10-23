**Pastaba:** Bendrą projekto informaciją bei ankstesnių versijų (`v0.1`, `v0.2`) realizacijas rasite pagrindinėje [main šakoje](https://github.com/adbr0/Objektinis_programavimas/blob/main/README.md). Šioje šakoje pateikta išsami **v0.3** konteinerių tyrimo ataskaita.

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

#### 1 000 įrašų
| Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :---: | :---: | :---: |
| Duomenų nuskaitymas | 0.0035 s | 0.0114 s | std::vector |
| Rūšiavimas | 0.0008 s | 0.0003 s | std::list |
| Dalijimas į 2 grupes | 0.0003 s | 0.0006 s | std::vector |
| Išvedimas į failus | 0.0037 s | 0.0060 s | std::vector |
| **Bendras laikas** | **0.0084 s** | **0.0183 s** | **std::vector** |

#### 10 000 įrašų
| Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :---: | :---: | :---: |
| Duomenų nuskaitymas | 0.0159 s | 0.0463 s | std::vector |
| Rūšiavimas | 0.0064 s | 0.0032 s | std::list |
| Dalijimas į 2 grupes | 0.0023 s | 0.0039 s | std::vector |
| Išvedimas į failus | 0.0114 s | 0.0228 s | std::vector |
| **Bendras laikas** | **0.0360 s** | **0.0762 s** | **std::vector** |

#### 100 000 įrašų
| Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :---: | :---: | :---: |
| Duomenų nuskaitymas | 0.1326 s | 0.2745 s | std::vector |
| Rūšiavimas | 0.0838 s | 0.0337 s | std::list |
| Dalijimas į 2 grupes | 0.0151 s | 0.0373 s | std::vector |
| Išvedimas į failus | 0.1107 s | 0.2343 s | std::vector |
| **Bendras laikas** | **0.3442 s** | **0.5798 s** | **std::vector** |

#### 1 000 000 įrašų
| Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :---: | :---: | :---: |
| Duomenų nuskaitymas | 1.3565 s | 2.7478 s | std::vector |
| Rūšiavimas | 1.1667 s | 0.4358 s | std::list |
| Dalijimas į 2 grupes | 0.1985 s | 0.3741 s | std::vector |
| Išvedimas į failus | 1.2504 s | 2.3098 s | std::vector |
| **Bendras laikas** | **3.9722 s** | **5.8675 s** | **std::vector** |

#### 10 000 000 įrašų
| Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :---: | :---: | :---: |
| Duomenų nuskaitymas | 15.8594 s | 27.9072 s | std::vector |
| Rūšiavimas | 16.5368 s | 6.9703 s | std::list |
| Dalijimas į 2 grupes | 2.2394 s | 4.7069 s | std::vector |
| Išvedimas į failus | 14.9393 s | 24.5081 s | std::vector |
| **Bendras laikas** | **49.5882 s** | **64.0924 s** | **std::vector** |

---
### Testavimo eigos ekrano nuotraukos:
#### 1 bandymas
<img width="485" height="475" alt="Screenshot 2026-10-23 154900" src="https://github.com/user-attachments/assets/dd034489-cbb6-4194-9044-d5e20166b7e6" />

#### 2 bandymas
<img width="485" height="480" alt="Screenshot 2026-10-23 155037" src="https://github.com/user-attachments/assets/0cfcc772-2bc3-4b21-b436-0b5692732ff0" />

#### 3 bandymas
<img width="485" height="479" alt="Screenshot 2026-10-23 155206" src="https://github.com/user-attachments/assets/6b9bbdf9-420d-4198-b6c0-1e0c29895e2c" />

---

### Tyrimo išvada:
**Bendroji sparta ir įvestis/išvestis:** `std::vector` bendras veikimo laikas visais atvejais buvo mažesnis nei `std::list`. Duomenų nuskaitymas ir įrašymas su vektoriumi vyko beveik dvigubai greičiau.
