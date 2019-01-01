// dstring.cc
//
// implementation af an dynamisk strengklasse
//
// (c) 1991, Maz Spork

#include <string.h>                       // strengmanipulationer
#include <ctype.h>                        // is...(), to...() osv.
#include "dstring.h"

DECLARE_AS_STOREABLE (String)
DEFINE_TRIVIAL_FUNCTIONS (String)

// opret en String fra C-streng
String::String (const char* s) {
   if (s && *s) {
      len = strlen (s);
      sptr = new char [len + 1];
      strcpy (sptr, s);
      }
   else sptr = NULL, len = 0;
   }

// opret en String fra anden String
String::String (const String& other) : len (other.len) {
   sptr = new char [len + 1];
   strcpy (sptr, other.sptr);
   }

// dealloker en String
String::~String () {
   if (len) delete sptr;
   }

// sammenlign to strenge for st›rrelse
bool String::isGreater (const Sortable& o) const {
   String& other = (String&) o;
   return strcmp (sptr, other.sptr) > 0;
   }

// sammenlign to strenge for lighed (*helt* ens)
bool String::isEqual (const Object& o) const {
   String& other = (String&) o;
   return len == other.len && !strcmp (sptr, other.sptr);
   }

// udskriv en String
void String::printOn (ostream& strm) const {
   strm << sptr;
   }

// udl‘s en String, udskriver ogs† l‘ngden p† strengen, s† strenge
// der indeholder b†de anf›rselstegn og linieskift kan udl‘ses
void String::dumpOn (ostream& strm) const {
   Sortable::dumpOn (strm);
   strm << len << " " << sptr << "\n";
   }

// ind‘s en String
void String::readFrom (istream& strm) {
   Sortable::readFrom (strm);
   if (len) delete sptr;
   strm >> len;
   strm.get ();
   sptr = new char [len + 1];
   strm.getline (sptr, len + 1);
   }

// tildel en String en anden String
String& String::operator= (const String& s) {
   if (this == &s) return *this;
   if (len) delete sptr;
   sptr = new char [s.len + 1];
   len = s.len;
   strcpy (sptr, s.sptr);
   return *this;
   }

// l‘g to strenge sammen ("A" + "B" == "C")
String operator+ (const String& s1, const String& s2) {
   char* temp = new char [s1.len + s2.len + 1];
   strcpy (temp, s1.sptr);
   strcat (temp, s2.sptr);
   return String (temp);
   }

// konvert‚r til store bogstaver
String String::toUpper () const {
   String temp = *this;
   strupr (temp.sptr);
   return temp;
   }

// konvert‚r til sm† bogstaver
String String::toLower () const {
   String temp = *this;
   strlwr (temp.sptr);
   return temp;
   }

// s›g efter substreng (fx. "CD" i "ABCDEF")
bool String::operator () (const String searchFor) const {
   return strstr (sptr, searchFor) != NULL;
   }

// s‘t alle tegn i strengen til bestemt v‘rdi
void String::Set (const char c) {
   strnset (sptr, c, len);
   }
