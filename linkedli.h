// linkedlist.h
//
// specification p† en h‘gtet liste-klasse
//
// (c) 1991, 1992 Maz Spork

#if !defined _LINKLIST_H
#define _LINKLIST_H

#include "genericlist.h"
#include "container.h"

class LinkedList : public GenericList<Object>, public Container {
public:
   DECLARE_TRIVIAL_FUNCTIONS (LinkedList)
   LinkedList () : GenericList<Object> (), Container () { }
   LinkedList (const LinkedList&);
   virtual LinkedList& operator= (const LinkedList&);
   virtual LinkedList operator+ (const LinkedList&);
   virtual ~LinkedList () { };
   virtual void printOn (ostream& = cout) const;
   virtual void dumpOn (ostream& = cout) const;
   virtual void readFrom (istream& = cin);
   virtual bool isEqual (const Object&) const;
   virtual void Insert (Object*);
   virtual Object* Retrieve ();
   virtual const Object* getCurrent () const {
      Object* o = GenericList<Object>::getCurrent ();
      return o ? o : &nil;
      }
   virtual const Object* getFirst () const {
      Object* o = GenericList<Object>::getFirst ();
      return o ? o : &nil;
      }
   virtual const Object* getNext () const {
      Object* o = GenericList<Object>::getNext ();
      return o ? o : &nil;
      }
   virtual void goTo (const unsigned long);
   virtual const Object& operator[] (const unsigned long) const;
   virtual const unsigned long Locate (const Object&) const;
   virtual const Object* Locate (const unsigned long) const;
   };

#endif

