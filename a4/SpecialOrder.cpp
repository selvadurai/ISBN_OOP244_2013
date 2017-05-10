#include <iostream>
#include <cstdio>
#include <stdlib.h>     /* atoi */
#include <cstring>
#include <string.h>
#include <iomanip>


using namespace std;


#include "SpecialOrder.h"


SpecialOrder::SpecialOrder(){
  if(instructor!=NULL)
	instructor=NULL;
}


 SpecialOrder::SpecialOrder(const ISBN& isbn, const char* instr):Order(isbn){  

       if(instr==NULL && strlen(instr)==0){
             person=NULL;
            *this=SpecialOrder();
       } else{
           instructor=new char [strlen(instr)+1];
           strcpy(instructor,instr);
      	}  
  }

SpecialOrder::SpecialOrder(const SpecialOrder& source):Order(source){
  instructor=NULL;
  *this=source;
}


bool SpecialOrder::add(istream& is){
	 
             
   
          char  temp[101];
          temp[101]='\0';
           	
          Order::add(is);

            if (instructor!= NULL) {
                delete [] instructor;
                instructor=NULL;
	          }
            
	cout<< "Instructions (0 to quit): ";
              is.getline(temp,100);

          
            instructor = new char[strlen(temp)+1];
            strcpy(instructor,temp);


            if (temp[0]!='0' && temp!='\0')
                return true;
            else
                return false;
}

void SpecialOrder::display(ostream& os) const{
 Order::display(os);
 os<<instructor<<endl;
}


SpecialOrder& SpecialOrder::operator=(const SpecialOrder& source){
             
          Order::operator=(source);	
      
 	if( source.instructor != NULL){
                    instructor = new char[strlen(source.instructor) + 1];
                    strcpy(instructor, source.instructor);
                }


		  if( instructor != NULL) {
                	delete[] instructor;
                	instructor = NULL;
 		     }
    
          return *this;
}






SpecialOrder::~SpecialOrder(){
   
   if(instructor!=NULL)
  	delete [] instructor;
}




