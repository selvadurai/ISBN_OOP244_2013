#include <iostream>
#include <cstdio>
#include <stdlib.h>     /* atoi */
#include <cstring>
#include <iomanip>
using namespace std;
#include "ISBN.h"
#include "Order.h"

Order::Order(const ISBN& isbn){
      	person=NULL;
	delivered=0;
	ordered=0;
	isbno=isbn;
}

Order::Order(const ISBN& isbn,const char* nm){

   if(nm==NULL || strlen(nm)==0){
        person=NULL;
        *this = Order();
    }
     else{
        person=new char [strlen(nm)+1];
        cout<<"check2"<<endl;
        strcpy(person,nm);
        isbno =isbn;

        ordered=0;
        delivered=0;
      }
}

bool Order::client(istream& is){

    char  temp[101];
          temp[101]='\0';
    cout<< "Enter Name (0 to quit): ";

            is.getline(temp,100);


            if (person != NULL) {
                delete [] person;
                person=NULL;
	          }

            person = new char[strlen(temp)+1];
            strcpy(person,temp);


            if (temp[0]!='0' && temp!='\0')
                return true;
            else
                return false;

    }

void Order::name(char* str) const{

    if(person!=NULL || strlen(person)!=0)
               strcpy(str,person);
             else
               str=NULL;
}

int Order::outstanding() const{
    return ordered;
}

bool Order::add(istream& is){
 int temp;
 cout<<"Enter the Quantity (0 to quit): ";

 do{

 is>>temp;
 is.ignore(2000, '\n');

 if(temp<0)
     cout<<" try again please enter postinve num Enter the Quantity (0 to quit): ";


 }while(temp<0);


 if(temp==0)
   return false;


 if(temp>0){
     ordered+=temp;
     return true;
 }
  else
     return false;

}

bool Order::add(int n){

    char is [11];
    isbno.toStr(is);
    is[11]='\0';

    isbn_num[13]='\0';

    ISBNPrefix list("prefixRanges.txt");
    ISBN thisISBN(is,list);

     if(n>0 && thisISBN.isRegistered()){
        ordered+=n;
        return true;
      }
      else
        return false;
}

Order::Order(const Order& source){
    person=NULL;
   *this=source;
}



bool Order::receive(istream& is){
    int temp;
    cout<<"Quantity (0 to quit)";

    do{
        is>>temp;
        is.ignore(2000, '\n');

        if(temp<0 || temp>ordered)
        cout<<" try again please enter postinve num Enter the Quantity (0 to quit): ";

        if(temp==0)
            return false;

    }while(temp<0 || temp>ordered);


        if(temp<ordered && temp>0){
            delivered+=temp;
            return true;
            }



}

void Order::display(ostream& os) const{
char star[13];
isbno.toStrWithStyle(star);
star[13]='\0';

 if(person!=NULL)
     os<<setw(13)<<star<<setw(9)<<ordered<<setw(11)<<delivered<<setw(25)<<person;
   else
      os<<setw(13)<<star<<setw(9)<<ordered<<setw(11)<<delivered<<setw(25);
}


bool Order::has(const ISBN& isbn)const{

 if( isbn==isbno )
    return true;
   else
     return false;
}

Order::~Order(){

    if(person!=NULL){
     delete [] person;
     person=NULL;
    }
}

ostream& operator<<(ostream& os, const Order& order){
    order.display(os);

return os;
}

Order& Order::operator=(const Order& source) {

   if(this != &source) {
		delivered = source.delivered;
		ordered = source.ordered;
		isbno = source.isbno;

         if( person != NULL) {
                delete[] person;
                person = NULL;
                }

                 if( source.person != NULL){
                    person = new char[strlen(source.person) + 1];
                    strcpy(person, source.person);
                }
            }

    return *this;
}



