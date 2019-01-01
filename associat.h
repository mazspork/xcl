// association.h
//
// specifikation af en associations-klasse
//
// (c) 1991, Maz Spork

#if !defined _ASSOC_H
#define _ASSOC_H

#include "object.h"

class Association : public Object {
public:
   Object* Key;
   Object* Value;

   DECLARE_TRIVIAL_FUNCTIONS (Association)
   Association () : Key (0), Value (0) { }
   Association (Object& a, Object& b) : Key (&a), Value (&b) { }
   Association (const Association&);
   virtual ~Association () { delete Key; delete Value; }
   virtual void printOn (ostream& = cout) const;
   virtual void dumpOn (ostream& = cout) const;
   virtual void readFrom (istream& = cin);
   virtual bool isEqual (const Object&) const;
   };

#endif

