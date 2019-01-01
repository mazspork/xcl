// sortable.h
//
// specifikation p† et sort‚rbart objekt
//
// (c) 1991, Maz Spork

#if !defined _SORTABLE_H
#define _SORTABLE_H

#include "object.h"

class Sortable : public Object {
public:
   virtual void dumpOn (ostream& = cout) const;
   virtual void readFrom (istream& = cin);
   virtual bool isGreater (const Sortable&) const = 0;
   };

bool operator> (const Sortable&, const Sortable&);
bool operator< (const Sortable&, const Sortable&);
bool operator>=(const Sortable&, const Sortable&);
bool operator<=(const Sortable&, const Sortable&);

#endif
