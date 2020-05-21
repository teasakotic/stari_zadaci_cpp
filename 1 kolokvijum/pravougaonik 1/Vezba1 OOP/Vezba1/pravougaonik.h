#ifndef PRAVOUGAONIK_H_INCLUDED
#define PRAVOUGAONIK_H_INCLUDED
#include "oblik.h"

class Pravougaonik:public Oblik{
public:
    //atributi
    float a;
    float b;

    //konstruktor
    Pravougaonik(float a, float b){
        this->a = a;
        this->b = b;
    }

    //geteri
    float getA(){
        return this->a;
    }

    float getB(){
        return this->b;
    }

    void setA(float novaA){
        this->a = novaA;
    }

    void setB(float novaB){
        this->b = novaB;
    }

    //metode
    void iscrtaj(){
        cout<<"Ovo je pravougaonik sa stranicom "<<getA()<<"cm i "<<getB()<<"cm i povrsinom "<<getA()*getB()<<"cm"<<endl;
    }

};

#endif // PRAVOUGAONIK_H_INCLUDED
