# Zadatak:

Napraviti specifikaciju i implementirati modele/klase kojima se opisuje sledece:
1) Stambeni objekat nalazi se na nekoj adresi 
    (mesto, ulica i broj) i znamo godinu proizvodnje. 
3) Moze da sadrzi vise prostorija. 
4) Za prostoriju znamo njezin 
    opis, godinu proizvodnje, povrsinu i temperaturu.
6) Temperatura moze da se menja samo kroz jednu od tri funkcije:
    - postaviTrenutnuTemperaturu sa parametrom temp
    - grejanje - povecava trenutnu temperaturu za 1 stepen
    - hladjenje - smanjuje temperaturu za 1 stepen
6) Kuhinja i kupatilo su posebne prostorije.
     grejanje u kuhinji se povecava za 2 stepena 
      a u kupatilu za tri stepena
     hladjenje kuhinje smanjuje temperaturu za 3 stepena a 
      u kupatilu  za dva 
9) Stambeni objekat treba da sadrzi virtuelnu metodu kojom 
se ukljucuje ili iskljucuje grejanje u svim prostorijama
10) Stambeni objekat mora da ima funkciju za racunanje
    prosecne temperature. (zbir temperatura svih prostorija)
12) Posebna vrsta stambenog objekta je Zgrada koja mora da 
    sadrzi i lift koji se ne greje. 
    (grejanje i hladjenje menja temperaturu za 0)  
13) Napisati main funkciju za kreiranje 
    jedne zgrade koja sadrzi 4 prostorije, 1 kupatilo i 
    jednu kuhinju.
14) Svakoj prostoriji postaviti trenutnu temperaturu na 20 stepeni.
15) Tri puta pokrenuti funkciju grejanja stambenog objekta i dva puta 
    pokrenuti funkciju hladjenja.
16) Izracunati i prikazati prosecnu temperaturu zgrade.

// za visu ocenu
17) Obezbediti snimanje i ucitavanje podataka iz datoteke zgrada.txt
    Format zapisa:
    <adresa>
    <godina proizvodnje>
    <vrsta prostorije>;<opis prostorije>;<godina proizvodnje>;<povrsina>;<temperatura>
   
    vrsta prostorije == OBICNA, KUHINJA, KUPATILO
    adresa=<mesto>;<ulica>;<broj>

// za najvisu ocenu
18) U opisu zgrade dodati informaciju o spratu 
     koji sadrzi stanove koji mogu da imaju prostorije.
    Omoguciti snimanje podataka u datoteku.

