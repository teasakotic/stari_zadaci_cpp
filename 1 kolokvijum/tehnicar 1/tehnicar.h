#ifndef TEHNICAR_H_INCLUDED
#define TEHNICAR_H_INCLUDED

class Tehnicar {
protected:
    bool tipTehnicara; //true - ekspert, false - pocetnik
    string ime;
    string prezime;
    string struka;
public:
    Tehnicar(bool tip, string im, string pre, string st) : tipTehnicara(tip), ime(im), prezime(pre), struka(st) {}
    void popravi(Kvar* k){
        if (tipTehnicara == false){
            dijagnostifikovanje(k);
        } else if (tipTehnicara == true && k->getTipKvara() == false) {
            dijagnostifikovanje(k);
        }

        k->setStatus(0);

     // menjaju status kvara
    }
    void dijagnostifikovanje(Kvar *k){
        k->setStatus(1);
    }

    void ispisiTehnicara(){
        cout << "Ja sam " << ime << " " << prezime << " struka mi je " << struka << endl;
    }
    string getStruka(){
        return struka;
    }
};

#endif // TEHNICAR_H_INCLUDED
