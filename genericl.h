// genericlist.h
//
// specifikation p†
//   en generisk h‘gtet liste, implementeret som skabelon, og
//   en generisk line‘r liste, implementeret som skabelon.
//
// (c) 1992, Maz Spork

#include "containerbase.h"

template <class Element>
   class GenericList : public virtual ContainerBase {
   public:
      struct GenericNode {      // privat struktur
    GenericNode* next;
    Element* objptr;
    GenericNode (Element* obj) : objptr (obj), next (0) { }
    };
   protected:
      GenericNode* head;
      GenericNode* cursor;       // aktuel h‘gte
      GenericNode* trail;   // f›lger cursor
      GenericNode* tail;
      void insertAt (Element*, GenericNode*);
      GenericList () : head (0), cursor (0), trail (0), tail (0) { }
      ~GenericList ();
      void Insert (Element*);
      Element* Retrieve ();
      Element* getCurrent () const { return cursor->objptr; }
      Element* getFirst () {
    trail = 0, cursor = head, currentIndex = 0;
    return cursor->objptr;
    }
      Element* getNext () {
    if (!cursor || !cursor->next) return 0;
    trail = cursor, cursor = cursor->next, currentIndex++;
    return cursor->objptr;
    };
      };

template <class Element>
   class GenericArray : public virtual ContainerBase {
   protected:
      Element** rep;
      GenericArray (const unsigned long);
      ~GenericArray ();
      const Element* getCurrent () const { return rep [currentIndex]; }
      const Element* getFirst () { return rep [currentIndex = 0]; }
      const Element* getNext () { return rep [++currentIndex]; }
      };

// prototype n›dvendig for f›lgende typedef's
class Object;

// anvendelige navne for parametiserede typer
typedef GenericList<Object> ObjList;
typedef GenericList<Object>::GenericNode ObjNode;

// destrukt›r for generisk liste, fjerner h‘gter og objekter
template <class Element>
   GenericList<Element>::~GenericList () {
      for (GenericNode* p = head; p;) {
    GenericNode* temp = p;
    p = p->next;
    delete temp->objptr;
    delete temp;
    }
      }

// inds‘t element i listen p† given h‘gteposition
template <class Element>      // protected medlemsfunktion
   void GenericList<Element>::insertAt (
      Element* elem, GenericNode* pos) {
    ObjNode* temp = cursor;
    cursor = pos;       // pr‘serv‚r aktuel position
    Insert (elem);
    cursor = temp;
    }

// inds‘t h‘gte i listen p† "aktuel" cursorposision
template <class Element>
   void GenericList<Element>::Insert (Element* elem) {
      ContainerBase::elementCount++;
      GenericNode* newNode = new GenericNode (elem);
      if (head) {
    if (cursor)
       newNode->next = cursor->next,
       cursor->next = newNode,
       cursor = newNode;
    else
       newNode->next = head, head = cursor = newNode;
    }
      else
    cursor = head = newNode, trail = 0;
      if (!newNode->next) tail = newNode;
      }

// hent fra listen p† "aktuel" cursorposition
template <class Element>
   Element* GenericList<Element>::Retrieve () {
      if (!cursor) return &nil;
      elementCount--;
      if (trail)
    trail->next = cursor->next;     // opdater listen
      else head = cursor->next;
      Element* elem = cursor->objptr;
      delete cursor;
      cursor = trail ? trail->next : head;
      return elem;
      }

// medlemsfunktioner i generisk line‘r liste

// konstrukt›r, allokerer et pointerarray
// de individuelle elementer allokeres eller tildeles af subklasserne
template <class Element>
   GenericArray<Element>::GenericArray (const unsigned long size)
   : ContainerBase (size) {
      rep = new Element* [size];
      }

// destrukt›r, deallokerer array'et
template <class Element>
   GenericArray<Element>::~GenericArray () {
      delete rep;
      }


