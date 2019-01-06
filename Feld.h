#include <iostream>

struct Feld {

    // Destruktor:
virtual ~Feld () {}

 // Liefert die Länge des Felds zurück:
    virtual int laenge() const = 0;

// Klammeroperator für nicht-konstante Objekte:

    virtual double &operator [] (int a) = 0;
    // Klammeroperator für konstante Objekte:

    virtual double &operator [] (int a) const = 0;
};

 // Feld auf den Ausgabestrom ausgeben:
 std::ostream& operator << (std::ostream& os, Feld& feld) {
         os << "[";
        for(int i=0; i<feld.laenge(); i++) {
            os << " " << feld [i];
         }
         os << " ]";
         return os;
 }