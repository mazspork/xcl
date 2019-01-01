// stack.h
//
// specifikation af en generel stak (FILO-buffer)
//
// (c) 1991, Maz Spork

#if !defined _STACK_H
#define _STACK_H

#include "linkedlist.h"

class Stack : public LinkedList {
public:
   DECLARE_TRIVIAL_FUNCTIONS (Stack)
   Stack () : LinkedList () { };
   Stack (const Stack& s) : LinkedList (s) { };
   void Push (Object* o) { insertAt (o, NULL); }
   Object* Pop () { cursor = head; return Retrieve (); }
   virtual void Insert (Object* o) { insertAt (o, head); }
   };

#endif

