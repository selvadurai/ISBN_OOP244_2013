#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include "ISBN.h"
class Order{

protected:
char* person;
char isbn_num [13];
int ordered;
int delivered;
ISBN isbno;

    public:
        Order(){cout<<"Order constructor"<<endl;person=NULL; ordered=0; delivered=0;};//default constructor
        Order(const ISBN& isbn);
        Order(const ISBN& isbn, const char* nm);

        Order(const Order& source);//copy construtor


        virtual bool has(const ISBN& isbn) const;

        virtual int outstanding() const;

       	virtual bool client(istream& is);
        virtual void name(char* str) const;
        virtual bool add(istream& is);
        virtual bool add(int n);
        bool receive(istream& is);
        virtual void display(ostream& os) const;
        virtual ~Order();
        friend ostream& operator<<(ostream& os, const Order& order);
        virtual  Order& operator= (const Order&);

};

#endif
