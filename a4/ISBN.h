#ifndef ISBN_H
#define ISBN_H

#include "ISBNPrefix.h"
#include "ISBN.h"
#include <iostream>


    class ISBN
    {
        char area[6];
        char publisher[8];
        char title[8];
        char string[13];
        bool isbnreg;
        int num;//area num

    public:
        ISBN();
        ISBN(const char* str, const ISBNPrefix& list);
        bool isRegistered(const ISBNPrefix& list);
        bool empty() const;
        bool isRegistered() const;
        void toStr(char* str) const;
        void toStrWithStyle(char* str) const;
        void display(ostream& os) const;
        bool read(istream& is, const ISBNPrefix& list);
      friend  bool operator==(const ISBN& left, const ISBN& right);
      friend ostream& operator<<(ostream& os, const ISBN& isbn);
};


int isValid(const char* str);


#endif
