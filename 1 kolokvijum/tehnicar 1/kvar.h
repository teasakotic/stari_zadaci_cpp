#ifndef KVAR_H_INCLUDED
#define KVAR_H_INCLUDED


class Kvar {
protected:
    string naslov;
    string opis;
    int dan;
    bool tipKvara; // true - lak, false - tezak
    int status; // 0 - otkljonjen, 1 - dijagnostifikovan, 2 - neotklonjen

public:
    Kvar(string n, string o, int d, bool t, int s) : naslov(n), opis(o), dan(d), tipKvara(t), status(s){}

    bool getTipKvara(){
        return tipKvara;
    }

    void setStatus(int x){
        status = x;
    }

    void ispisiKvar(){
        cout << "Kvar: " << naslov << " " << opis << " dan:" << dan << " status: " << status << endl;
    }
    string getNaslov(){
        return naslov;
    }
};

#endif // KVAR_H_INCLUDED
