#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Deo{
    public:
        string naziv = "";
        string proizvodjac = "";
        int ostecenost = 0;

        virtual void ispis(){
            cout<<"Naziv: "<<naziv<<" proizvodjac: "<<proizvodjac<<" pohabanost: "<<ostecenost<<"\n";
        }

        virtual void upotrebi(int duzina){
            ostecenost += duzina;
        }

        virtual bool ispravnost() = 0;
};


class Automobil{
    public:
        string nazivProizvodjaca;
        string model;
        vector<Deo*> delovi;

        virtual bool ispravnost(){
            // int osteceni = 0;
            // for(Deo* deo: delovi){
            //     if(!deo->ispravnost())
            //     osteceni++;
            // }
            // if(osteceni>0)
            //     return false;
            // else
            //     return false;
            // vraca true ako su svi delovi ispravni
            for(Deo* deo: delovi){
                if(!deo->ispravnost()){
                    return false;
                }
            }
            return true;
        };
        virtual void vozi(int duzina)=0; 
        virtual void tehnickiPregled(){
            // ispis svih delova i njihovu ostecenost
            for(Deo* deo: delovi){
                deo->ispis();
            }
        }
};

class Motor:public Deo{
    public: 
        virtual bool ispravnost(){
            if(ostecenost>=1000){
                return true;
            }else{
                return false;
            }
        }

};

class BMW: public Automobil{
    public:
    virtual void vozi(int duzina){
        cout<<"Automobil: "<<nazivProizvodjaca<<" model:"<<model<<" je zavrsio voznju duzine: "<<duzina<<"\n";
        for(Deo* deo: delovi){
            deo->upotrebi(duzina);
        }
    }
};



int main(){
    cout<<"MAIN\n";

    BMW a = BMW();
    
    Motor* motor = new Motor();
    motor->naziv = "HDI 19";
    motor->proizvodjac = "BMW";
    a.delovi.push_back(motor);

    motor = new Motor();
    motor->naziv = "EL 2000";
    motor->proizvodjac = "BMW";
    a.delovi.push_back(motor);

    a.vozi(100);
    a.tehnickiPregled();
    a.vozi(100);
    a.tehnickiPregled();

    bool ispravan = a.ispravnost();
    cout<<"Auto je ispravan: "<<ispravan<<"\n";

    a.vozi(1000);
    a.tehnickiPregled();

    return 0;
}