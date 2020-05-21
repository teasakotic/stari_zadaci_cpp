#include "adresa.h"

Adresa::Adresa(const string &mesto, const string &ulica, const string &broj):
    mesto(mesto), ulica(ulica), broj(broj) {
}

Adresa::Adresa(istream &in) {
    in >> mesto >> ulica >> broj;
}
