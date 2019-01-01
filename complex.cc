// complex.cc
//
// implementation af en kompleks numerisk klasse
//
// (c) 1991, Maz Spork

#include <math.h>                   // mathematiske funktioner & konstanter
#include "complex.h"

DECLARE_AS_STOREABLE (Complex)
DEFINE_TRIVIAL_FUNCTIONS (Complex)

// abs() er en friend-funktion for at tillade bedre syntaks
double abs (const Complex& c) {
   return sqrt (norm (c));
   }

// norm er en friend-funktion for at tillade bedre syntaks
double norm (const Complex& c) {
   return c.re * c.re + c.im * c.im;
   }

// return‚r reel del af det komplekse tal (friend-funktion)
double real (const Complex& c) {
   return c.re;
   }

// return‚r imagin‘r del af det komplekse tal (friend-funktion)
double imag (const Complex& c) {
   return c.im;
   }

// sammenlign to komplekse tal for st›rrelsesforhold
bool Complex::isGreater (const Sortable& o) const {
   Complex& other = (Complex&) o;
   return abs (*this) > abs (other);
   }

// sammenlign to komplekse tal for lighed
bool Complex::isEqual (const Object& other) const {
   return ((Complex&)other).re == re && ((Complex&)other).im == im;
   }

// f›lgende fire udf›rer addition, subtraktion, multiplikation og division
Complex operator+ (const Complex& c1, const Complex& c2) {
   return Complex (c1.re + c2.re, c1.im + c2.im);
   }

Complex operator- (const Complex& c1, const Complex& c2) {
   return Complex (c1.re - c2.re, c1.im - c2.im);
   }

Complex operator* (const Complex& c1, const Complex& c2) {
   return Complex (
      c1.re * c2.re - c1.im * c2.im,
      c1.re * c2.im + c1.im * c2.re
      );
   }

Complex operator/ (const Complex& c1, const Complex& c2) {
   return Complex (
      (c1.re * c2.re + c1.im * c2.im) / norm (c2),
      (c1.im * c2.re - c1.re * c2.im) / norm (c2)
      );
   }

// udskriv et komplekst tal
void Complex::printOn (ostream& strm) const {
   strm << "(" << re << "," << im << ")";
   }

// udl‘s et komplekst tal
void Complex::dumpOn (ostream& strm) const {
   Object::dumpOn (strm);
   strm << re << "\n" << im << "\n";
   }

// indl‘s et komplekst tal
void Complex::readFrom (istream& strm) {
   Object::readFrom (strm);
   strm >> re >> im;
   }
