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

---

## [v1.0] – Studentų dalijimo strategijų optimizavimas ir spartos analizė

Šioje versijoje realizuotos ir ištirtos 3 studentų skaidymo į dvi grupes („vargšiukai“ ir „kietekai“) strategijos, naudojant `std::vector` ir `std::list`:
* **1 strategija:** Bendro studentų konteinerio skaidymas į du naujus to paties tipo konteinerius (`vargsiukai` ir `kietekai`).
* **2 strategija:** Naudojamas tik vienas naujas konteineris (`vargsiukai`), o perkelti studentai ištrinami iš pradinio konteinerio.
* **3 strategija (optimizuota):**
  * `std::vector` atveju – elementai pertvarkomi vietoje su `std::stable_partition`.
  * `std::list` atveju – atrenkami su `std::copy_if` ir ištrinami su `std::remove_if`.

### Programos surinkimas su Makefile:
* **Windows (MinGW):** `mingw32-make`
* **Linux / macOS:** `make`
* **Valymas:** `mingw32-make clean` (arba `make clean`)

---

### Spartos tyrimo rezultatų palyginimas (3 bandymai ir vidurkiai):

#### `std::vector` dalijimo sparta (sekundėmis)

| Įrašų kiekis | Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :---: | :--- | :---: | :---: | :---: | :---: |
| **1 000** | 1 strategija (2 nauji) | 0.00023 s | 0.00026 s | 0.00025 s | **0.00025 s** |
| | 2 strategija (1 naujas + erase) | 0.00230 s | 0.00229 s | 0.00230 s | **0.00230 s** |
| | 3 strategija (stable_partition) | 0.00020 s | 0.00028 s | 0.00023 s | **0.00024 s** |
| **10 000** | 1 strategija (2 nauji) | 0.00171 s | 0.00401 s | 0.00216 s | **0.00263 s** |
| | 2 strategija (1 naujas + erase) | 0.13966 s | 0.15406 s | 0.16966 s | **0.15446 s** |
| | 3 strategija (stable_partition) | 0.00106 s | 0.00104 s | 0.00148 s | **0.00119 s** |
| **100 000** | 1 strategija (2 nauji) | 0.01193 s | 0.01271 s | 0.01880 s | **0.01448 s** |
| | 2 strategija (1 naujas + erase) | 17.35977 s | 22.38708 s | 62.03684 s | **33.92790 s** |
| | 3 strategija (stable_partition) | 0.01001 s | 0.01764 s | 0.01268 s | **0.01344 s** |
| **1 000 000** | 1 strategija (2 nauji) | 0.11873 s | 0.18579 s | 0.15692 s | **0.15381 s** |
| | 2 strategija (1 naujas + erase) | 3931.54666 s | *(praleista)* | *(praleista)* | **~3931.55 s (~65.5 min)** |
| | 3 strategija (stable_partition) | 0.10980 s | 0.18422 s | 0.13811 s | **0.14404 s** |
| **10 000 000** | 1 strategija (2 nauji) | 1.55251 s | 1.72796 s | 1.68434 s | **1.65494 s** |
| | 2 strategija (1 naujas + erase) | *(praleista)* | *(praleista)* | *(praleista)* | **Neatlikta dėl O(N²)** |
| | 3 strategija (stable_partition) | 1.56781 s | 1.94487 s | 1.58775 s | **1.70014 s** |

---

#### `std::list` dalijimo sparta (sekundėmis)

| Įrašų kiekis | Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :---: | :--- | :---: | :---: | :---: | :---: |
| **1 000** | 1 strategija (2 nauji) | 0.00025 s | 0.00021 s | 0.00024 s | **0.00023 s** |
| | 2 strategija (1 naujas + erase) | 0.00009 s | 0.00009 s | 0.00008 s | **0.00009 s** |
| | 3 strategija (copy_if / remove_if) | 0.00010 s | 0.00018 s | 0.00010 s | **0.00013 s** |
| **10 000** | 1 strategija (2 nauji) | 0.00186 s | 0.00152 s | 0.00142 s | **0.00160 s** |
| | 2 strategija (1 naujas + erase) | 0.00079 s | 0.00101 s | 0.00060 s | **0.00080 s** |
| | 3 strategija (copy_if / remove_if) | 0.00130 s | 0.00162 s | 0.00157 s | **0.00150 s** |
| **100 000** | 1 strategija (2 nauji) | 0.01390 s | 0.02008 s | 0.01887 s | **0.01762 s** |
| | 2 strategija (1 naujas + erase) | 0.00618 s | 0.01251 s | 0.00833 s | **0.00901 s** |
| | 3 strategija (copy_if / remove_if) | 0.01390 s | 0.02365 s | 0.01795 s | **0.01850 s** |
| **1 000 000** | 1 strategija (2 nauji) | 0.22032 s | 0.21944 s | 0.22028 s | **0.22001 s** |
| | 2 strategija (1 naujas + erase) | 0.06001 s | 0.11886 s | 0.10781 s | **0.09556 s** |
| | 3 strategija (copy_if / remove_if) | 0.21984 s | 0.26030 s | 0.25816 s | **0.24610 s** |
| **10 000 000** | 1 strategija (2 nauji) | 2.79896 s | 2.77290 s | 2.29979 s | **2.62388 s** |
| | 2 strategija (1 naujas + erase) | 0.68958 s | 2.91798 s | 1.02950 s | **1.54569 s** |
| | 3 strategija (copy_if / remove_if) | 2.51071 s | 6.85801 s | 2.88454 s | **4.08442 s** |

---

### Testavimo eigos ekrano nuotraukos:

#### 0 bandymas

#### 1 bandymas

#### 2 bandymas

#### 3 bandymas



---

### v1.0 Išvados ir analizė:

1. **2 strategijos $O(N^2)$ problema su `std::vector`:**
   * Naudojant `erase()` cikle, po kiekvieno elemento ištrynimo visi likę elementai perslenkami atmintyje ($O(N)$ veiksmas).
   * Bendras sudėtingumas tampa **$O(N^2)$**, todėl 1 000 000 įrašų apdorojimas truko **3931.55 s (virš 65 min)**. Vektoriui ši strategija dideliems duomenų kiekiams yra netinkama.
2. **2 strategijos efektyvumas su `std::list`:**
   * Sąraše trynimas (`erase`) yra $O(1)$, nes tereikia perstatyti mazgų rodykles. Todėl `std::list` 2 strategijoje veikė sparčiausiai (0.091 s su 1M įrašų), nes nereikėjo skirti papildomos atminties antram konteineriui.
3. **3 strategijos optimizacija:**
   * Vektoriaus atveju `std::stable_partition` algoritmas išsprendė perslinkimų problemą – su 1M įrašų laikas krito nuo 3931 s iki **0.136 s**.
   * Pritaikius šį algoritmą, vektorius aplenkė sąrašą dėl spartinančiosios atminties efektyvumo tolydžioje atmintyje.
