# Olio-ohjelmointi
Object-Oriented Programming (OOP) course in Oulu University of Applied Science

## Tehtävä 1

Tässä tehtävässä toteutetaan numeroarvauspeli, jossa pelaajan tulee arvata tietokoneen arpoma satunnainen luku.

### 1. Perusversio (main-funktiossa)
- Arvotaan satunnainen luku väliltä 1-20.
- Pyydetään pelaajalta arvaus.
- Ilmoitetaan, onko arvaus pienempi, suurempi tai oikea.
- Toistetaan, kunnes pelaaja arvaa oikein.

### 2. Funktiointiin siirtäminen
- Siirretään pelilogiikka omaan funktioonsa:

```cpp
int game();
```

- Lasketaan arvausten määrä ja palautetaan se pääohjelmaan.

### 3. Parametrisoitu versio
- Lisätään funktiolle parametri maxnum, joka määrittää suurimman arvottavan luvun:

```cpp
int game(int maxnum);
```
    
- Pääohjelmassa tulostetaan pelin loputtua arvausten määrä.

#### Muut huomioitavat asiat
- Käytetään satunnaislukugeneraattoria (cstdlib ja ctime).
- Arvottu luku saadaan rajoitettua modulo-operaattorilla.
- Tulostetaan debug-tietoa ohjelman toiminnan varmistamiseksi.

## Tehtävä 2

**Tässä tehtävässä Tässä tehtävässä toteutetaan viikkotehtävän 1 mukainen numeroarvauspeli oliopohjaisesti käyttäen Game-luokkaa.** 

### Game-luokka
-Konstruktori:
    - Saa parametrina ```maxNumber```, joka määrittää arvottavan luvun alueen (1 - maxNumber).
    - Arpoo arvattavan luvun.
    - Tulostaa debug-tietoa.
- ```void Play()```
    - Toteuttaa pelilogiikan (kysyy arvauksia, antaa vihjeitä).
    - Laskee arvausten määrän.
- ```void printGameResult()```
    - Tulostaa oikean luvun ja arvausten määrän pelin päätyttyä.

### Ohjelman tiedostorakenne
1. ```Game.h``` - Luokan otsikkotiedosto
2. ```Game.cpp``` - Luokan toteutustiedosto
3. ```main.cpp``` - Luo ```Game```-olion ja käynnistää pelin


### Lisävaatimukset
- Debug-tulostukset konstruktoriin ja jäsenfunktioihin.
- Testaa ohjelman toiminta varmistamalla, että peli etenee oikein.

## Tehtävä 3

**Tässä tehtävässä harjoitellaan perintää kahden luokan avulla:** 

### 1. Chef-luokka:
- Konstruktori ottaa parametrinä kokin nimen.
- Jäsenfunktiot ```makeSalad(int ingredients)``` ja ```makeSoup(int ingredients)```, jotka palauttavat valmistettujen annosten määrän.
    - Salaatti: 1 annos = 5 ainesta
    - Keitto: 1 annos = 3 ainesta
- Kaikki metodit, konstruktori ja destruktori tulostavat debug-tietoa.

### 2. ItalianChef-luokka (perii Chef-luokan):
- Lisää jäsenmuuttujan salasanalle (```password = "pizza"```).
- Jäsenfunktio ```askSecret(string givenPassword, int flour, int water)```:
    - Tarkistaa, onko salasana oikein.
    - Jos oikein, kutsuu ```makePizza(int flour, int water)```.
- ```makePizza``` (privaatti):
    - 1 pizza = 5 jauhoa + 5 vettä.
    - Palauttaa valmistettujen pizzojen määrän.

**Tavoitteena on toteuttaa luokat annettujen määrittelyjen mukaan ja varmistaa, että perintä toimii oikein.** 

## Tehtävä 4

**Tässä tehtävässä harjoitellaan yhdistelmäolioiden käyttöä ja perintää pankkitili- ja luottotili-luokkien avulla.**
**Tavoitteena on mallintaa pankkitilejä, luottoja ja asiakastoimintoja käyttäen perintää ja yhdistelmäolioita.**

### 1. Pankkitili-luokka (```Pankkitili```)
- ```deposit(double amount)``` - Tallettaa rahaa tilille (ei negatiivisia talletuksia).
- ```withdraw(double amount)``` - Nostaa rahaa tililtä (ei negatiivisia nostoja, saldo ei saa mennä alle 0).
- ```getBalance()``` - Palauttaa tilin saldon.
- Virtuaaliset metodit, jotta perityt luokat voivat muokata toimintaa.

### 2. Luottotili-luokka (```Luottotili```) (perii ```Pankkitili```)
- Konstruktori saa parametrina nimen ja henkilökohtaisen luottorajan.
- ```withdraw(double amount) override``` - Nostaa rahaa luottotililtä (ei negatiivisia nostoja, mutta tilin saldo voi mennä miinukselle luottorajaan asti).
- ```deposit(double amount) override``` - Maksaa luottovelkaa (ei voi maksaa enempää kuin on velkaa, saldo ei saa ylittää nollaa).
- ```getBalance()``` palauttaa saldon.

### 3. Asiakas-luokka (```Asiakas```)
- Jäsenmuuttujat:
    - ```Pankkitili pankkitili```
    - ```Luottotili luottotili```
- Konstruktori saa asiakkaan nimen ja luottorajan.
- ```showSaldo()``` - Tulostaa molempien tilien saldot.
- ```talletus(double amount)``` - Lisää rahaa pankkitilille.
- ```nosto(double amount)``` - Nostaa rahaa pankkitililtä.
- ```luotonMaksu(double amount)``` - Maksaa velkaa luottotililtä.
- ```luotonNosto(double amount)``` - Nostaa rahaa luottotililtä.

### 4. TiliSiirto Asiakkaiden Välillä
- ```tiliSiirto(double amount, Asiakas& vastaanottaja)```
    - Siirtää rahaa asiakkaan pankkitililtä toisen asiakkaan pankkitilille.
    - Ei voi tehdä siirtoa, jos saldo ei riitä.

### Ohjelman tiedostorakenne
1. ```Pankkitili.h / Pankkitili.cpp``` - Pankkitili-luokan määrittely ja toteutus.
2. ```Luottotili.h / Luottotili.cpp``` - Luottotili-luokan määrittely ja toteutus.
3. ```Asiakas.h / Asiakas.cpp``` - Asiakas-luokan määrittely ja toteutus.
4. ```main.cpp``` -  Luo Asiakas-olioita, suorittaa tilisiirtoja ja testaa logiikkaa.


## Tehtävä 5
**Tässä tehtävässä toteutetaan Notifikaattori-järjestelmä, joka käyttää osoittimia ja linkitettyä listaa seuraajien hallintaan.**
**Tavoitteena käyttää osoittimia ja linkitettyä listaa seuraajien hallintaan dynaamisesti!**

### 1. Seuraaja-luokka ( ```Seuraaja ```)
-  ```string nimi ``` - Seuraajan nimi.
-  ```Seuraaja* next ``` - Osoitin seuraavaan seuraajaan (käytetään linkitetyn listan rakentamiseen).
-  Konstruktori - Asettaa seuraajan nimen ja alustaa  ```next = nullptr ```.
-  ```paivitys(string viesti) ``` - Tulostaa viestin konsolille ("[nimi] sai viestin: [viesti]").
-  ```getNimi() ``` - Palauttaa seuraajan nimen.

### 2. Notifikaattori-luokka (```Notifikaattori```)
- ```Seuraaja* alku``` - Osoitin listan ensimmäiseen seuraajaan.
- Konstruktori - Alustaa ```alku = nullptr```.
- ```void lisaa(Seuraaja* uusi)``` - Lisää uuden seuraajan listan alkuun.
- ```void poista(string nimi)``` - Poistaa tietyn nimisen seuraajan listalta.
- ```void tulosta()``` - Tulostaa kaikkien seuraajien nimet.
- ```void postita(string viesti)``` - Lähettää viestin kaikille seuraajille kutsumalla ```paivitys()```-funktiota.

### 3. Linkitetyn listan käsittely

#### Lisäys (```lisaa()```)
1. Asetetaan uuden seuraajan ```next``` osoittamaan nykyiseen alkuun.
2. Päivitetään ```alku``` osoittamaan uuteen seuraajaan.
    - Ennen: ```alku -> B```
    - Lisätään A: ```A -> B``` ja ```alku = A```

#### Poisto (```poista()```)
1. Etsitään poistettava seuraaja.
2. Jos löytyy, päivitetään edellisen ```next``` osoittamaan seuraajan ```next```.
    - Ennen: ```A -> B -> C```
    - Poistetaan B: ```A -> C``` (B ohitetaan)

####Listan läpikäynti (```tulosta()``` ja ```postita()```)
- ```while (o != nullptr)```
    - Käydään lista läpi ```next```-osoittimen avulla, kunnes saavutetaan ```nullptr```.


### 4. Ohjelman tiedostorakenne
- ```Seuraaja.h``` - Seuraaja-luokan määrittely ja toteutus.
- ```Notifikaattori.h```  - Notifikaattori-luokan määrittely ja toteutus.
- ```main.cpp```  Luo Notifikaattori-olion, lisää seuraajia, poistaa heitä ja testaa viestien lähettämistä.

## Tehtävä 6

**Tehtävässä hyödynnetään C++ standardikirjastoa (`vector`, `algorithm`, `string`) opiskelijoiden hallintaan**
**Tavoitteena harjoitella C++ standardikirjaston käyttöä ja tietorakenteita (`vector`, `algorithm`).**

### Tehtävän Ydinasiat

1. `Student`-luokka
    - Jäsenmuuttujat: `name (string)`, `age (int)`.
    - Getterit & setterit (`getName()`, `getAge()`, `setName()`, `setAge()`).
    - `printStudentInfo()` - Tulostaa opiskelijan tiedot.
2. Pääohjelma (`main.cpp`)
    - Valikko: Käyttäjä voi lisätä, tulostaa, järjestää ja etsiä opiskelijoita.
    - Tiedot tallennetaan `vector<Student>`-listaan.
    - `algorithm`-kirjaston funktiot (`sort()`, `find_if()`) käytössä.

### Pääohjelman Valinnat

| **Valinta** | **Toiminto** |
|:------------:|-------------|
| **0** | Lisää opiskelija `vector<Student>`-listaan. |
| **1** | Tulostaa kaikki opiskelijat. |
| **2** | Järjestää ja tulostaa opiskelijat **nimen** mukaan (`sort()`). |
| **3** | Järjestää ja tulostaa opiskelijat **iän** mukaan (`sort()`). |
| **4** | Etsii opiskelijaa nimellä (`find_if()`). |

### Keskeiset C++ Standardikirjaston Käytöt
1. `vector<Stduent>`
    - `push_back()` - Lisää opiskelijoita listaan.
    - `begin()` / `end()` - Käytetään `find_if()`- ja `sort()`-funktioissa.
2. `sort()` (`algorithm`)

    - Lambda-funktiota hyödyntäen:
```cpp
sort(studentList.begin(), studentList.end(), 
    [](const Student& a, const Student& b) { return a.getName() < b.getName(); });
```
3. `find_if()` (`algorithm`)
    - Käytetään opiskelijan hakemiseen nimen perusteella:
```cpp
auto it = find_if(studentList.begin(), studentList.end(), 
    [&name](const Student& student) { return student.getName() == name; });
```
