// dstring.h
//
// specification p† en streng-klasse
//
// (c) 1991, Maz Spork

#if !defined _STRING_H
#define _STRING_H

#include "sortable.h"

class String : public Sortable {
protected:
   char* sptr;
   unsigned len;
public:
   DECLARE_TRIVIAL_FUNCTIONS (String)
   String () : sptr (NULL), len (0) { }
   String (const char*);
   String (const String&);
   virtual ~String ();
   virtual bool isGreater (const Sortable&) const;
   virtual bool isEqual (const Object&) const;
   virtual void printOn (ostream& = cout) const;
   virtual void dumpOn (ostream& = cout) const;
   virtual void readFrom (istream& = cin);
   String& operator= (const String&);
   operator const char* const () const { return sptr; }
   unsigned Length () const { return len; }
   bool operator () (const String) const;
   String toLower () const;
   String toUpper () const;
   void Set (const char);
   friend String operator+ (const String&, const String&);
   };

#endif
