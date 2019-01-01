// dictionary.h
//
// specifikation af en katalog-klasse
//
// (c) 1991, Maz Spork

#if !defined _DICT_H
#define _DICT_H

#include "linkedlist.h"
#include "association.h"

class Dictionary : public LinkedList {
public:
   DECLARE_TRIVIAL_FUNCTIONS (Dictionary)
   Dictionary () : LinkedList () { }
   Dictionary (const Dictionary& from) : LinkedList (from) { }
   virtual void addAssociation (Object&, Object&);
   virtual Object* getAssociation (Object&);
   };

#endif

