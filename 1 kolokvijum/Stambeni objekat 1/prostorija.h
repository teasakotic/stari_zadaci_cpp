#ifndef PROSTORIJA_H_INCLUDED
#define PROSTORIJA_H_INCLUDED

using namespace std;

class Prostorija {
protected:
    string opis;
    int godinaProizvodnje;
    double povrsina;
    double temperatura;
public:

    Prostorija() : opis("Velika"), godinaProizvodnje(2000), povrsina(30.2), temperatura(26.3) {}
    Prostorija(string o, int gp, double p, double t) : opis(o), godinaProizvodnje(gp), povrsina(p), temperatura(t) {}

    virtual void postavitiTrenutnuTemperaturu(double temp){
        temperatura = temp;
    }

    virtual void grejanje(){
        temperatura += 1;
    }

    virtual void hladjenje(){
        temperatura -= 1;
    }

    double getTemperatura(){
        return temperatura;
    }

    // dodatna metoda, cisto da vidimo da li sve radi
    void ispisi(){
        cout << "Soba: " << opis << "   temperatura: " << temperatura << endl;
    }
};


class Kuhinja : public Prostorija{
public:
    Kuhinja() : Prostorija() {}
    Kuhinja(string o, int gp, double p, double t) : Prostorija(o, gp, p, t) {}

    void grejanje() {
        temperatura += 2;
    }

    void hladjenje() {
        temperatura -= 3;
    }
};

class Kupatilo : public Prostorija {
public:
    Kupatilo() : Prostorija() {}
    Kupatilo(string o, int gp, double p, double t) : Prostorija(o, gp, p, t) {}

    void grejanje() {
        temperatura += 3;
    }

    void hladjenje() {
        temperatura -= 2;
    }
};

class Lift : public Prostorija {
public:
    Lift() : Prostorija() {}
    Lift(string o, int gp, double p, double t) : Prostorija(o, gp, p, t) {}

    void grejanje() {
        temperatura += 0; // moze i da se nista ne napise
    }

    void hladjenje() {
        temperatura -= 0; // moze i da ostane prazno
    }
};


#endif // PROSTORIJA_H_INCLUDED
