#include "Feld.h"
#include <iostream>

class FeldImpl : public Feld {

private:
    double *werte;
    int _laenge;
public:

 // Konstruktor:
FeldImpl(int laenge) : _laenge(laenge){
    werte = new double[laenge]();
     for(int i=0; i<laenge; i++) {
         werte [i] = 0;
     }
}

 // Destruktor:
 ~FeldImpl() {
     if(werte!=nullptr) {
        delete [] werte;
     }
 }

 // Liefert die Länge des Felds zurück:
     int laenge() const {
         return _laenge;
     }

 // Klammeroperator für nicht-konstante Objekte:
    virtual double &operator [] (int i) {
        return werte[i];
    }

 // Klammeroperator für konstante Objekte:
    virtual double &operator [] (int i) const {
        return werte[i];
     }

// Zuweisungsoperator mit Verschiebesemantik
 FeldImpl& operator = (FeldImpl&& f) {
     if(this!=&f) {
        if (werte != nullptr) {
           delete[] werte;
        }
        werte = f.werte;
        _laenge = f.laenge();
         f._laenge = 0;
         f.werte = nullptr;
        }
        return *this;
     }
 };