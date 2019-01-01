// sortedlist.h
//
// specifikation p† en sorteret liste
//
// (c) 1991, Maz Spork

#if !defined _SORTLIST_H
#define _SORTLIST_H

#include "linkedlist.h"
#include "sortable.h"

class SortedList : public LinkedList {
public:
   enum SortOrder {   // indlejret opremsning
      AscendingOrder, DescendingOrder, randomOrder
      };
private:
   SortOrder order;
public:
   DECLARE_TRIVIAL_FUNCTIONS (SortedList)
   SortedList (SortOrder o = AscendingOrder) : order (o) { }
   SortedList (const SortedList& o) : LinkedList (o), order (o.order) { }
   virtual void Insert (Object*);
   };

#endif
