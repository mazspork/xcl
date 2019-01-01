// sortedlist.c
//
// implementation af en sorteret liste
//
// (c) 1991, Maz Spork

#include "sortedlist.h"

DECLARE_AS_STOREABLE (SortedList)
DEFINE_TRIVIAL_FUNCTIONS (SortedList)

// inds‘t objekt i listen p† den rette plads afh‘ngig af sortering
void SortedList::Insert (Object* obj) {
   ObjNode* a = head, *b = 0;         // after og before node-pointere

   if (order == AscendingOrder)
      while (a && *(Sortable*) obj > *(Sortable*) a->objptr)
         b = a, a = a->next;
   else    //  == DescendingOrder
      while (a && *(Sortable*) obj < *(Sortable*) a->objptr)
         b = a, a = a->next;

   insertAt (obj, b);
   }

