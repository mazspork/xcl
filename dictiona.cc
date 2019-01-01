// dictionary.cc
//
// implementation af en katalog-klasse, indeholdende associationer
// mellem objekter.
//
// (c) 1991, Maz Spork

#include "dictionary.h"

DECLARE_AS_STOREABLE (Dictionary)
DEFINE_TRIVIAL_FUNCTIONS (Dictionary)

// tilf›j en association: et opslagsobjekt og en associeret v‘rdi
void Dictionary::addAssociation (Object& a, Object& b) {
   Insert (new Association (a, b));
   }

// find en association til en given n›gle
Object* Dictionary::getAssociation (Object& searchKey) {
   for (ObjNode* n = head; n; n = n->next) // line‘r s›gning!
      if (*((Association*) n->objptr)->Key == searchKey)
         return ((Association*) n->objptr)->Value;
   return &nil;
   }
