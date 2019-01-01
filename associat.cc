// association.cc
//
// implementation af en associations-klasse
//
// (c) 1991, Maz Spork

#include "association.h"

DECLARE_AS_STOREABLE (Association)
DEFINE_TRIVIAL_FUNCTIONS (Association)

// opret association fra anden association
Association::Association (const Association& from) {
   Key = &from.Key->Copy ();
   Value = &from.Value->Copy ();
   }

// sammenlign to associationer
bool Association::isEqual (const Object& other) const {
   return ((Association&)other).Key == Key &&
          ((Association&)other).Value == Value;
   }

// udskriv en association
void Association::printOn (ostream& strm) const {
   strm << *Key << " <-> " << *Value;
   }

// udl‘s en association
void Association::dumpOn (ostream& strm) const {
   Object::dumpOn (strm);
   Key->dumpOn (strm);
   Value->dumpOn (strm);
   }

// indl‘s en association
void Association::readFrom (istream& strm) {
   Object::readFrom (strm);
   Key   = ObjectManager::readPolymorphicObject (strm);
   Value = ObjectManager::readPolymorphicObject (strm);
   }

