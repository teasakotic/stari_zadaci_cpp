#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED

class Motor : public Deo {
public:
    Motor(string np, string nd, double os) : Deo(np,nd,os) {}
    virtual void ispis() {
        cout << nazivDela << "(" <<nazivProizvodjaca << "), pohabanost:" << ostecenost << endl;
    }
};


#endif // MOTOR_H_INCLUDED
