# Maticová kalkulačka

Naprogramuju maticovou kalkulačku, podporující několik maticových operací. Komunikace uživatele bude realizovana přes terminal a připravéné příkazy. Taky bude možné ukladat spočítané matice do souborů, a načítat jich ze souborů.


## Dostupné operace s maticemi
* Sčítání
* Odčítání
* Násobení
* Transpozice
* Horizontální sloučení
* Oříznutí
* Inverze (pro čtvercové matice)
* Výpočet determinantu
* Určení hodnosti
* Gaussova Eliminační Metoda
* Gaussova Eliminační Metoda s komentářem

Polymorfismus byl použit pro různé typy matic:
* husté (hodnoty uloženy do 2D pole)
* řídké (hodnoty uloženy do mapy koordinat a hodnot, protože řídké matice obsahují přiliš hodně nulových hodnot, které není nutně zachovat)