// sortable.cc
//
// implementation af abstrakt sort‚rbart objekt
//
// (c) 1991, Maz Spork

#include "sortable.h"

// kald den virtuelle isGreater()-metode for at unders›ge forholdet
bool operator> (const Sortable& a, const Sortable& b) {
   return a.isGreater (b);
   }

// mindre end er det samme som ej st›rre end og ej ens
bool operator< (const Sortable& a, const Sortable& b) {
   return ! (a.isGreater (b) || a.isEqual (b));
   }

// st›rre end eller lig med (lige ud ad landevejen)
bool operator>= (const Sortable& a, const Sortable& b) {
   return a.isGreater (b) || a.isEqual (b);
   }

// mindre end eller lig med er det samme som ej st›rre end
bool operator<= (const Sortable& a, const Sortable& b) {
   return !a.isGreater (b);
   }

// udl‘s et sort‚rbart objekt (dummy-metode)
void Sortable::dumpOn (ostream& strm) const {
   Object::dumpOn (strm);
   }

// indl‘s et sort‚rbart objekt (dummy-metode)
void Sortable::readFrom (istream& strm) {
   Object::readFrom (strm);
   }
