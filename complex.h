// complex.h
//
// specifikation af en kompleks numerisk klasse
//
// (c) 1991, Maz Spork

#if !defined _COMPLEX_H
#define _COMPLEX_H

#include "sortable.h"

class Complex : public Sortable {
   double re, im;
public:
   DECLARE_TRIVIAL_FUNCTIONS (Complex)
   Complex () : re (0), im (0) { }
   Complex (const Complex& other) : re (other.re), im (other.im) { };
   Complex (const double& r, const double& i = 0) : re (r), im (i) { }
   virtual ~Complex () { }
   virtual void printOn (ostream& = cout) const;
   virtual void dumpOn (ostream& = cout) const;
   virtual void readFrom (istream& = cin);
   virtual bool isEqual (const Object&) const;
   virtual bool isGreater (const Sortable&) const;
   friend double abs (const Complex&);
   friend double norm (const Complex&);
   friend double real (const Complex&);
   friend double imag (const Complex&);
   friend Complex operator+ (const Complex&, const Complex&);
   friend Complex operator- (const Complex&, const Complex&);
   friend Complex operator* (const Complex&, const Complex&);
   friend Complex operator/ (const Complex&, const Complex&);
   operator double () { return norm (*this); }
   };

#endif

