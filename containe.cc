// container.cc
//
// implementation af abstrakt klasse for gruppering af objekter
//
// (c) 1991, 1992 Maz Spork

#include "container.h"

// metode til at l‘gge to containere sammen
Container& Container::operator+= (const Container& other) {
   for (const Object* o = other.getFirst ();
      *o != nil; o = other.getNext ()) {
         Insert (&o->Copy ());
         currentIndex++;
         }
   return *this;
   }

// metode til at udl‘se en container - udl‘ser blot t‘ller
void Container::dumpOn (ostream& strm) const {
   Object::dumpOn (strm);
   strm << elementCount << "\n";
   }

// metode til at indl‘se en container - indl‘ser blot t‘ller
void Container::readFrom (istream& strm) {
   Object::readFrom (strm);
   strm >> elementCount;
   }

