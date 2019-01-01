// object.cc
//
// implementation af rod-klassen Object, fejl-klassen Nil og
// I/O-klassen ObjectManager.
//
// (c) 1991, Maz Spork

#include "object.h"
#include "string.h"

// initi‚r statiske data i ObjectManager. Tabellen createAddress indeholder
// adresser p† funktioner, som explicit allokerer objekter af forskellige
// typer, og returnerer en polymorf reference. Det tillader ObjectManger
// at allokere objekter p† basis af en klasseidentifikation, og derefter
// kalde indl‘sningsmetoder i det p†g‘ldende objekt.

classInfo* ObjectManager::classList = NULL;

// f›lgende erkl‘ring sikrer ordentlig oprydning i globale data
static ObjectManager cleanup;

// det globale nil-objekt (det 'tomme' objekt)
Nil nil;

// Annoncer nil-objektet som "gennemsigtigt" udl‘seligt
static Object* CreateNil () { return &nil; }
static bool initNil = ObjectManager::Announce ("Nil", CreateNil);

// privat klasse til administration af eksplicit allokering af objekter
class classInfo {
   friend ObjectManager;                        // bruges kun herfra !
   char* Name;                                      // klassens navn
   PTOM allocFunc;                            // klassens allokator
   classInfo* next;                              // n‘ste klasse...
   classInfo (char* s, PTOM f, classInfo* n) :
      Name (s), allocFunc (f), next (n) { }
   };

// udl‘sning af et objekt gennem en ostream (uden typeinformation)
ostream& operator<< (ostream& strm, const Object& obj) {
   obj.printOn (strm);
   return strm;
   }

// indl‘sning af et objekt gennem en istream (uden typeinformation)
istream& operator>> (istream& strm, Object& obj) {
   obj.readFrom (strm);
   return strm;
   }

// udl‘sning af et objekt genne en ostream (med typeinformation)
void Object::dumpOn (ostream& strm) const {
   strm << Name () << " ";

// p† dette sted kan v‘rdien af "this" inds‘ttes i et Dictionary
// og gives en association. P† den m†de kan dumpOn() ved opslag
// i Dictionary'et sikre, at et objekt ikke bliver udl‘st to gange.

   }

// indl‘sning af et objekt med (skjult) typeinformation
void Object::readFrom (istream& strm) {
   strm >> ws;
   }

// sammenligning af objekter
bool operator== (const Object& a, const Object& b) {
   return a.Type () == b.Type () ? a.isEqual (b) : 0;
   }

bool operator!= (const Object& a, const Object& b) {
   return !(a == b);
   }

// annoncering af ny klasse i hierarkiet (statisk metode)
bool ObjectManager::Announce (char* className, PTOM pointer) {
   classList = new classInfo (className, pointer, classList);
   return 1;
   }

// l‘s et objekt fra en istream (statisk metode)
Object* ObjectManager::readPolymorphicObject (istream& strm) {
   char className [0x20];
   strm >> className;
   for (classInfo* c = classList; c; c = c->next)
      if (!strcmp (c->Name, className)) break;
   if (!c) return &nil;
   Object* empty = (c->allocFunc) ();
   empty->readFrom (strm);
   return empty;
   }

// dealloker alle objekter, der blev allokeret med statiske "annonceringer"
ObjectManager::~ObjectManager () {
   classInfo* cursor = classList;
   while (cursor) {
      classInfo* temp = cursor;
      cursor = cursor->next;
      delete temp;
      }
   }
