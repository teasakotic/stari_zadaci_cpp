#ifndef AUTOMOBIL_H_INCLUDED
#define AUTOMOBIL_H_INCLUDED

#include <vector>

class Automobil {
    protected:
    string nazivProizvodjaca;
    string model;
    vector<Deo*> delovi;
    public:

        Automobil(string n, string m): nazivProizvodjaca(n), model(m) { }

        virtual bool ispravnost() {
         // prodjem kroz sve delove - for petlja
         // ako naidjem na neispravan deo, vratim false
         // ako su svi ispravni, vratim true

         for (int i = 0; i < delovi.size(); i++){
            if (delovi[i]->ispravnost() == false){
                return false;
            }
         }
         return true;
        }

        virtual void vozi(double duzinaVoznje){
            cout << nazivProizvodjaca << ", " << model << ", je zavrsio voznju duzina " << duzinaVoznje << endl;
            // prodjem kroz sve delove - for petlja
            // za svaki deo pozovem upotrebi()

            for(int i = 0; i < delovi.size(); i++){
                delovi[i]->upotrebi(duzinaVoznje);
            }
        }

        virtual void tehnickiPregled(){
        // prodjem kroz sve delove - for
        // ispisem ih (pazi na novi red)
            for (int i = 0; i < delovi.size(); i++){
                delovi[i]->ispis();
            }
        }

        virtual void ubaciDeo(Deo* d) = 0;
};

#endif // AUTOMOBIL_H_INCLUDED
