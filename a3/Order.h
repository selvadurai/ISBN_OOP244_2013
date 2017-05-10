#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include "ISBN.h"
class Order{

char* person;
char isbn_num [13];
int ordered;
int delivered;
ISBN isbno;

    public:
        Order(){cout<<"Order construtor"<<endl;person=NULL; ordered=0; delivered=0;};//default constructor
        Order(const ISBN& isbn);
        Order(const ISBN& isbn, const char* nm);

        Order(const Order& source);//copy construtor


        bool has(const ISBN& isbn) const;

        int outstanding() const;

        bool client(istream& is);
        void name(char* str) const;
        bool add(istream& is);
        bool add(int n);
        bool receive(istream& is);
        void display(ostream& os) const;
        virtual ~Order();
        friend ostream& operator<<(ostream& os, const Order& order);
        Order& operator= (const Order&);

};

#endif
