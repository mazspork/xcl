// dequeue.h
//
// implementation af en generel dobbelth‘gtet k›
//
// (c) 1991, Maz Spork

#if !defined _DEQUEUE_H
#define _DEQUEUE_H

#include "queue.h"

class DeQueue : public Queue {
public:
   DECLARE_TRIVIAL_FUNCTIONS (DeQueue)
   DeQueue () : Queue () { };
   DeQueue (const DeQueue& q) : Queue (q) { };
   virtual void insertFront (Object* o) { Insert (o); }
   virtual Object* retrieveBack () { return Retrieve (); }
   };

#endif
