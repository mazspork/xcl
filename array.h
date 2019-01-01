// array.h
//
// specifikation p† statisk allokeret klasse for gruppering af objekter.
//
// (c) 1991, 1992 Maz Spork

#if !defined _ARRAY_H
#define _ARRAY_H

#include "container.h"
#include "genericlist.h"

class Array : public Container, public GenericArray<Object> {
public:
   DECLARE_TRIVIAL_FUNCTIONS (Array)
   Array (const unsigned long = DEFAULT_CAP);
   Array (const Array&);
   virtual ~Array ();
   virtual void Insert (Object*);
   virtual Object* Retrieve ();
   virtual const Object* getCurrent () const;
   virtual const Object* getFirst () const;
   virtual const Object* getNext () const;
   virtual const Object& operator[] (const unsigned long) const;
   virtual Array operator+ (const Array&);
   virtual Object*& operator[] (const unsigned long);
   virtual void printOn (ostream& = cout) const;
   virtual void dumpOn (ostream& = cout) const;
   virtual void readFrom (istream& = cin);
   virtual bool isEqual (const Object&) const;
   };

#endif


