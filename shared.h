// shared.h
//
// specifikation af deleligt objekt mellem flere containerklasser
//
// (c) 1991, Maz Spork

#if !defined _SHARED_H
#define _SHARED_H

#include "object.h"

// et "delt" objekt, opn†et gennem delegering og filtrering af destrukt›r
class SharedObject : public Object {
   Object* ref;
public:
   SharedObject (Object* o) : ref (o) { }
   SharedObject (Object& o) : ref (&o) { }
   virtual ~SharedObject () { }
   virtual void printOn (ostream& s = cout) const { ref->printOn (s); }
   virtual void readFrom (istream& s = cin) { ref->readFrom (s); }
   virtual void dumpOn (ostream& s = cout) const { ref->dumpOn (s); }
   virtual bool isEqual (const Object& o) const { return ref->isEqual (o); }
   virtual Class Type () const { return ref->Type (); }
   virtual Object& Copy () const { return ref->Copy (); }
   virtual const char* Name () const { return ref->Name (); }
   };

#endif
