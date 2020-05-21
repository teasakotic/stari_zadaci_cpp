#ifndef TOCAK_H_INCLUDED
#define TOCAK_H_INCLUDED

class Tocak : public Deo {
public:
    Tocak(string np, string nd, int os) : Deo(np,nd,os) { }
    virtual void ispis() {
        cout << nazivDela << "(" <<nazivProizvodjaca << "), pohabanost:" << ostecenost << endl;
    }

};

#endif // TOCAK_H_INCLUDED
