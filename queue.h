// queue.h
//
// specifikation af en generel enkelth‘gtet k›
//
// (c) 1991, Maz Spork

#if !defined _QUEUE_H
#define _QUEUE_H

#include "linkedlist.h"

class Queue : public LinkedList {
public:
   DECLARE_TRIVIAL_FUNCTIONS (Queue)
   Queue () : LinkedList () { };
   Queue (const Queue& q) : LinkedList (q) { };
   virtual void insertBack (Object* o) { LinkedList::Insert (o); }
   virtual Object* retrieveFront () { return Retrieve (); }
   };

#endif


