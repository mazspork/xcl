// array.c
//
// implementation p† statisk allokeret klasse for gruppering af objekter.
// Array-klassen indeholder pointere til objekter.
//
// (c) 1991, 1992 Maz Spork

#include "array.h"

DECLARE_AS_STOREABLE (Array)
DEFINE_TRIVIAL_FUNCTIONS (Array)

// konstru‚r en Array med fast st›rrelse, angivet som tvungen parameter
Array::Array (const unsigned long size)
   : Container (size), GenericArray<Object> (size) {
   elementCount = size;
   for (unsigned long i = 0; i < elementCount; i++) rep [i] = &nil;
   }

// kopi-konstrut›r: Array til Array
Array::Array (const Array& other)
   : Container (other), GenericArray<Object> (other.elementCount) {
   for (unsigned i = 0; i < elementCount; i++)
      rep [i] = &(other.rep [i]->Copy ());
   currentIndex = 0;
   }

// l‘g to Array-objekter sammen
Array Array::operator+ (const Array& other) {
   Array ret = *this;
   ret += other;
   return ret;
   }

// destru‚r Array, deallokerer alle objekter ikke lig nil
Array::~Array () {
   for (unsigned i = 0; i < elementCount; i++)
      if (*rep [i] != nil) delete rep [i];
   }

// inds‘t et objekt i et Array p† en (eventuelt uspecificeret) position
void Array::Insert (Object* o) {
   if (*rep [currentIndex] != nil) delete rep [currentIndex];
   rep [currentIndex] = o;
   }

// fjern et objekt fra et Array, klienten har nu objektet
Object* Array::Retrieve () {
   if (currentIndex >= elementCount) {
      cerr << "Array::Retrieve: index out of bounds\n";
      return &nil;
      }
   Object* temp = rep [currentIndex];
   rep [currentIndex] = &nil;
   return temp;
   }

// unders›g objektet p† positionen, returnerer konstant reference
const Object* Array::getCurrent () const {
   if (currentIndex >= elementCount) return &nil;
   return GenericArray<Object>::getCurrent ();
   }

// n‘ste objekt
const Object* Array::getNext () const {
   if (currentIndex + 1 >= elementCount) return &nil;
   return GenericArray<Object>::getNext ();
   }

// f›rste objekt (ogsaa konst.)
const Object* Array::getFirst () const {
   if (!elementCount) return &nil;
   return GenericArray<Object>::getFirst ();
   }

// bedre syntaks for getCurrent, returnerer konstant pointer
const Object& Array::operator[] (const unsigned long pos) const {
   if (pos < elementCount) return *rep [pos];
   cerr << "Array::operator[]: index out of bounds\n";
   return nil;
   }

// anden version, returnerer reference til pointer, kan bruges som rvalue
Object*& Array::operator[] (const unsigned long pos) {
   if (pos < elementCount) return rep [pos];
   cerr << "Array::operator[]: index out of bounds\n";
   return *rep;
   }

// udskriv et Array
void Array::printOn (ostream& strm) const {
   strm << "[ ";
   for (unsigned i = 0; i < elementCount - 1; i++)
      strm << *rep [i] << ",";
   strm << *rep [elementCount - 1] << " ]";
   }

// udl‘s et Array
void Array::dumpOn (ostream& strm) const {
   Container::dumpOn (strm);
   for (unsigned i = 0; i < elementCount; i++) rep [i]->dumpOn (strm);
   }

// indl‘s et Array
void Array::readFrom (istream& strm) {
   Container::readFrom (strm);
   for (int i = 0; i < elementCount; i++)
      rep [i] = ObjectManager::readPolymorphicObject (strm);
   }

// sammenlign to Arrays, skal ogs† v‘re af samme st›rrelse
bool Array::isEqual (const Object& other) const {
   if (((Array&)other).elementCount != elementCount) return 0;
   for (int i = 0; i < elementCount; i++)
      if (*rep [i] != *((Array&)other).rep [i]) return 0;
   return 1;
   }



