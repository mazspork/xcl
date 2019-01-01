// iterator.h
//
// specifikation p† en klasse til genneml›b af container
//
// (c) 1991, Maz Spork

#if !defined _ITERATOR_H
#define _ITERATOR_H

#include "container.h"

class Iterator : public Object {
   Container* ref;
   unsigned long index;
public:
   DECLARE_TRIVIAL_FUNCTIONS (Iterator)
   Iterator () : index (0), ref (NULL) { }
   Iterator (const Iterator& i) : ref (i.ref), index (i.index) { }
   Iterator (Container& c) : ref (&c), index (0) { }
   virtual ~Iterator () { }
   virtual bool isEqual (const Object&) const;
   virtual void printOn (ostream& = cout) const;
   const Object& operator* ();
   Iterator& operator= (const Iterator&);
   Iterator& operator= (Container&);
   Iterator& operator= (const unsigned long);
   Iterator& operator++ (int);        // prefix
   Iterator& operator++ ();         // postfix
   operator bool ();
   bool More ();
   };

#endif

