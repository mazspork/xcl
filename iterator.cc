// iterator.cc
//
// implementation af en klasse til genneml›b af container
//
// (c) 1991, 1992 Maz Spork

#include "iterator.h"

// metode til opt‘lling af et genneml›bs-objekt (postfix)
Iterator& Iterator::operator++ () {
   ref->getNext ();
   return *this;
   }

// metode til opt‘lling af et genneml›bs-objekt (pretfix)
Iterator& Iterator::operator++ (int) {
   ref->getNext ();
   return *this;
   }

// return‚r det aktuelle objekt, som genneml›beren "peger" p†
const Object& Iterator::operator* () {
   return *ref->getCurrent ();
   }

// return‚r en sandhedsv‘rdi afh‘ngig af, om slutningen er n†et
bool Iterator::More () {
   return index < ref->Size ();
   }

// samme som forrige, men bedre syntaks
Iterator::operator bool () {
   return More ();
   }

// sammenlign to genneml›bere
bool Iterator::isEqual (const Object& other) const {
   return index == ((Iterator&) other).index
         && ref == ((Iterator&) other).ref;
   }

// udskriv en genneml›ber p† den aktuelle position
void Iterator::printOn (ostream& strm) const {
   strm << ref->operator[] (index) << " (index " << index << ")";
   }

// tildel en genneml›ber fra en anden genneml›ber
Iterator& Iterator::operator= (const Iterator& other) {
   index = other.index, ref = other.ref;
   return *this;
   }

// tildel en container til en genneml›ber
Iterator& Iterator::operator= (Container& cont) {
   index = 0, ref = &cont;
   return *this;
   }

// tildel en container en indeks-v‘rdi
Iterator& Iterator::operator= (const unsigned long pos) {
   index = pos;
   return *this;
   }
