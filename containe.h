// contbase.h
//
// baseklasse for alle containere af alle typer
//
// (c) 1992, Maz Spork

#if !defined (_CONTBASE_H)
#define _CONTBASE_H

class ContainerBase {
protected:
   unsigned long elementCount;        // st›rrelse p† container
   unsigned long currentIndex;        // aktuelt index i container
   ContainerBase (unsigned long size)
   : elementCount (size), currentIndex (0) { }
   ContainerBase () : elementCount (0), currentIndex (0) { }
   ContainerBase (const ContainerBase& other)
   : elementCount (other.elementCount), currentIndex (0) { }
   };

#endif




