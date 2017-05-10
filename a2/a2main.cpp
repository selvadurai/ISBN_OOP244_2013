// ISBN Processor
// OOP244.132 - Assignment 2
// a2main.cpp
// Version 1.1
// Chris Szalwinski
// Jan 14 2011

#include <cstdio>
#include <iostream>
using namespace std;
#include "ISBNPrefix.h"
#include "ISBN.h"

#define MAXISBN 100
char menu(istream& is);

int main() {
    int no = 0;
    char c, choice;
    ISBNPrefix prefixList("prefixRanges.txt");
    ISBN isbn[MAXISBN];

    cout << "ISBN Processor\n"
         << "==============\n";

    // process user input
    do {
        choice = menu(cin);
        cout << endl;
        switch(choice) {
            case 'A':
                {
                    ISBN temp;
                    if (temp.read(cin, prefixList))
                        if (no < MAXISBN)
                            isbn[no++] = temp;
                        else
                            cerr << "** No space for more ISBNs!" << endl;
                    else
                        cerr << "** No ISBN added!" << endl;
                }
                break;
            case 'V':
                cout << "         ISBN\n";
                cout << "-------------\n";
                for (int i = 0; i < no; i++) {
					if (!isbn[i].empty()) {
						isbn[i].display(cout);
						cout << endl;
					}
                }
                break;
        }
    } while (choice != 'Q');

    return 0;
}

// menu prompts for and accepts an option selection from standard input and
// returns the character identifying the selected option
//
char menu(istream& is) {
    char c;
    int  ok = false;

    cout << '\n';
    cout << "Please select from the following options :\n";
    cout << " A - Add an ISBN\n";
    cout << " V - View all ISBNs\n";
    cout << " Q - Quit\n";
    do {
        cout << " Your selection : ";
        c = ' ';
        is.get(c);
        if (c >= 'a' && c <= 'z')
            c -= 'a' - 'A';
        if (is.fail()) {
            is.clear();
            is.ignore(2000, '\n');
            cerr << " Invalid input.  Try again." << endl;
        } else if (c == '\n') {
            ; // no input - try again
        } else if (c != 'A' && c != 'V' && c != 'Q') {
            is.ignore(2000, '\n');
            cerr << " Invalid Character.  Try again." << endl;
        } else if (is.get() != '\n') {
            is.ignore(2000, '\n');
            cerr << " Trailing Characters.  Try Again. " << endl;
        } else if (c == 'A' || c == 'V' || c == 'Q')
            ok = true;
    } while (ok == 0);

    return c;
}
