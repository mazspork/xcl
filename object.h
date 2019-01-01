// object.h
//
// specifikaion af rod-klassen Object, fejl-klassen Nil samt
// I/O-klassen ObjectManager
//
// (c) 1991, Maz Spork

#if !defined _OBJECT_H
#define _OBJECT_H

#include <iostream.h>

// fremad-referencer til de fire klasser i denne fil
class Nil;
class Object;
class classInfo;
class ObjectManager;

// anvendelige navne for afledte typer
typedef int bool;         // boolsk v‘rdi
typedef Object* (*PTOM) ();    // pointer til funktion

const TRUE  = 1;
const FALSE = 0;

// klassebeskrivelser for ikke-abstrakte klasser
enum Class {
	aNil,                  // fejl-objekt
	aLinkedList,           // h‘gtet liste
	aSortedList,           // sorteret h‘gtet liste
	aStack,                // stak (f›rst-ind-sidst-ud-buffer)
	aQueue,                // k› (f›rst-ind-f›rst-ud-buffer)
	aDeQueue,              // dobbelt-endt k›
	aArray,                // en line‘r liste
	aComplex,              // komplekst tal
	aString,               // streng
	aIterator,             // genneml›b af containere
	aAssociation,          // en association mellem to objekter
	aDictionary,           // et katalog over associationer
	};

// statisk klasse til definition af ind- og udl‘selige objekter
class ObjectManager {
	static classInfo* classList;
public:
	~ObjectManager ();
	static Object* readPolymorphicObject (istream& = cin);
	static bool Announce (char*, PTOM);
	};

// rod-objektet for alle klasser Object - privat klasse
// medlemsfunktioner (alle virtuelle undtagen konstrukt›rer) for:
// 	- konstruktion af objekt (beskyttet funktion)
// 	- destruktion af objekt
//		- ud- og indl‘sning af objekt
//		- udskrivning af objekt
// 	- sammenligning af objekter
// 	- typeidenitifikation af objekt
// 	- kopiering af objekt (deep copy)
// 	- navneidentifikation af objekt

class Object {
protected:
	Object () { };
	Object (const Object&) { };
public:
	virtual ~Object () { };
	virtual void printOn (ostream& = cout) const = 0;
	virtual void readFrom (istream& = cin);
	virtual void dumpOn (ostream& = cout) const;
	virtual bool isEqual (const Object&) const = 0;
	virtual Class Type () const = 0;
	virtual Object& Copy () const = 0;
	virtual const char* Name () const = 0;
	};

// det "tomme" objekt - bruges i fejl og termineringer (kun ‚n forekomst)
extern Nil nil;

// fejl-klasse: bruges til identifikation af ulovligt objekt
class Nil : public Object {
public:
	Nil () { }
	virtual ~Nil () { }
	virtual void printOn (ostream& strm = cout) const { strm << Name (); }
	virtual void readFrom (istream& strm = cin) { strm >> ws; }
	virtual bool isEqual (const Object& o) const { return bool (&o); }
	virtual Class Type () const { return aNil; }
	virtual Object& Copy () const { return nil; }
	virtual const char* Name () const { return "Nil"; }
	};

// globale metoder til sammenligning af objekter
bool operator== (const Object&, const Object&);
bool operator!= (const Object&, const Object&);

// globale metoder til udskrivning og indl‘sning af objektindhold
ostream& operator<< (ostream&, const Object&);
istream& operator>> (istream&, const Object&);

// makro til registrering af klasser med I/O-kapabilitet
#define DECLARE_AS_STOREABLE(CLASS)                                     \
   static Object* Create ## CLASS () {                                  \
      return new CLASS;                                                 \
      }                                                                 \
   static bool init ## CLASS = ObjectManager::Announce (                \
      #CLASS, Create ## CLASS                                           \
      );

// makro til erkl‘ring/implementation af trivielle medlemsfunktioner
#define DECLARE_TRIVIAL_FUNCTIONS(CLASS)                               \
	virtual Class Type () const;                                        \
	virtual Object& Copy () const;                                      \
	virtual const char* Name () const;

// makro til implementation af trivielle medlemsfunktioner
#define DEFINE_TRIVIAL_FUNCTIONS(CLASS)                               \
	Class CLASS ## ::Type () const { return a ## CLASS; }              \
	Object& CLASS ## ::Copy () const { return *new CLASS (*this); }    \
	const char* CLASS ## ::Name () const { return #CLASS ; }

#endif
