#include <iostream.h>
#include "sortedlist.h"
#include "dstring.h"

void main () {
        LinkedList l1, l2, l3;
        l1.Insert (new String ("a"));
        l1.Insert (new String ("b"));
        l1.Insert (new String ("c"));
        l2.Insert (new String ("d"));
        l2.Insert (new String ("e"));
        l2.Insert (new String ("f"));

        cout << "l1 == " << l1 << "\n";
        cout << "l2 == " << l2 << "\n";
        cout << "l3 == " << l3 << "\n";

        l3 = l1 + l2;

        cout << "l3 == " << l3 << "\n";
        }

