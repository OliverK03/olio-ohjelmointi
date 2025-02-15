## Olio-ohjelmointi
Object-Oriented Programming (OOP) course in Oulu University of Applied Science

# Tehtävä 1

Tässä tehtävässä toteutetaan numeroarvauspeli, jossa pelaajan tulee arvata tietokoneen arpoma satunnainen luku.

1. Perusversio (main-funktiossa)
    Arvotaan satunnainen luku väliltä 1-20.
    Pyydetään pelaajalta arvaus.
    Ilmoitetaan, onko arvaus pienempi, suurempi tai oikea.
    Toistetaan, kunnes pelaaja arvaa oikein.

2. Funktiointiin siirtäminen
    Siirretään pelilogiikka omaan funktioonsa:

    `code int game();`

Lasketaan arvausten määrä ja palautetaan se pääohjelmaan.
3. Parametrisoitu versio
Lisätään funktiolle parametri maxnum, joka määrittää suurimman arvottavan luvun:
cpp
Kopioi
Muokkaa
int game(int maxnum);
Pääohjelmassa tulostetaan pelin loputtua arvausten määrä.
Muut huomioitavat asiat
Käytetään satunnaislukugeneraattoria (cstdlib ja ctime).
Arvottu luku saadaan rajoitettua modulo-operaattorilla.
Tulostetaan debug-tietoa ohjelman toiminnan varmistamiseksi.

# Tehtävä 2
Toteuta viikkotehtävän 1 mukainen arvauspeli nyt oliopohjaisesti. 


# Tehtävä 3
Tässä tehtävässä harjoitellaan perintää kahden luokan avulla:

1. Chef-luokka:
    Konstruktori ottaa parametrinä kokin nimen.
    Jäsenfunktiot makeSalad(int ingredients) ja makeSoup(int ingredients), jotka palauttavat valmistettujen annosten määrän.
        Salaatti: 1 annos = 5 ainesta
        Keitto: 1 annos = 3 ainesta
Kaikki metodit, konstruktori ja destruktori tulostavat debug-tietoa.

2. ItalianChef-luokka (perii Chef-luokan):
    Lisää jäsenmuuttujan salasanalle (password = "pizza").
    Jäsenfunktio askSecret(string givenPassword, int flour, int water):
        Tarkistaa, onko salasana oikein.
        Jos oikein, kutsuu makePizza(int flour, int water).
    makePizza (privaatti):
        1 pizza = 5 jauhoa + 5 vettä.
        Palauttaa valmistettujen pizzojen määrän.

Tavoitteena on toteuttaa luokat annettujen määrittelyjen mukaan ja varmistaa, että perintä toimii oikein.