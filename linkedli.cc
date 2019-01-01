// linkedlist.cc
//
// implementation af en h‘gtet liste klasse
//
// (c) 1991, Maz Spork

#include "linkedlist.h"

DECLARE_AS_STOREABLE (LinkedList)
DEFINE_TRIVIAL_FUNCTIONS (LinkedList)

//  at finde en h‘gte ved line‘r traversering af listen
const Object* LinkedList::Locate (const unsigned long index) const {
   unsigned long i = index;
   for (ObjNode* c = head; i-- && c; c = c->next);
   return c ? c->objptr : &nil;
   }

// l‘g to LinkedList'er sammen
LinkedList LinkedList::operator+ (const LinkedList& other) {
   LinkedList ret = *this;
   ret += other;
   return ret;
   }

// find indekset p† en specifik h‘gte ved en n›gle
const unsigned long LinkedList::Locate (const Object& toFind) const {
   unsigned long i = 0;
   for (ObjNode* c = head; *c->objptr != toFind && c; c = c->next) i++;
   return i;
   }

// g† til h‘gte nr og lad dette v‘re den aktuelle
void LinkedList::goTo (const unsigned long index) {
   unsigned long i = index;
   for (ObjNode* c = head; i-- && c; c = c->next);
   cursor = c ? c : head;
   }

// kopi-konstrukt›r, genererer en reel kopi af eksisterende liste
LinkedList::LinkedList (const LinkedList& from)
   : Container (from), GenericList<Object> () {
   for (ObjNode* c = from.head; c; c = c->next)
      Insert (&c->objptr->Copy ());
   getFirst ();       // nulstil ny liste
   }

// tildeling af anden liste
LinkedList& LinkedList::operator= (const LinkedList& from) {
   ObjNode* temp, * cursor = head;

   while (cursor) {
      temp = cursor->next;
      delete cursor->objptr;
      delete cursor;
      cursor = temp;
      }
   for (cursor = from.head; cursor; cursor = cursor->next)
      Insert (&cursor->objptr->Copy ());
   getFirst ();
   return *this;
   }

// inds‘ttelse af et objekt p† listen
void LinkedList::Insert (Object* o) {
   GenericList<Object>::Insert (o);
   }

// at fjerne et objekt p† listen
Object* LinkedList::Retrieve () {
   if (!Size ()) return &nil;
   return GenericList<Object>::Retrieve ();
   }

// indekseret reference i listen, relativt index fra f›rste element
const Object& LinkedList::operator[] (const unsigned long index) const {
   if (head == NULL || index >= elementCount) return nil;
   return *Locate (index);
   }

// sammenligning af to lister
bool LinkedList::isEqual (const Object& o) const {
   bool result;
   for (ObjNode* p = head, *q = ((LinkedList&) o).head; p;
      p = p->next, q = q->next)
         if (*p->objptr != *q->objptr) return 0;
   return 1;
   }

// udskrivning af liste p† str›m
void LinkedList::printOn (ostream& strm) const {
   for (ObjNode* p = head; p; p = p->next)
      strm << *p->objptr << endl;
   }

// udl‘s en h‘gtet liste
void LinkedList::dumpOn (ostream& strm) const {
   Container::dumpOn (strm);
   for (ObjNode* p = head; p; p = p->next)
      p->objptr->dumpOn (strm);
   }

// indl‘s en h‘gtet liste
void LinkedList::readFrom (istream& strm) {
   Container::readFrom (strm);
   int i = elementCount;
   for (elementCount = 0; i; i--)
      Insert (ObjectManager::readPolymorphicObject (strm));
   }
