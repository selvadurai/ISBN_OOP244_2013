#include <iostream>
#include <cstdio>
#include <cstring>
#include "ISBNPrefix.h"

using namespace std;

 ISBNPrefix::ISBNPrefix(const char* filename){

        name=new char [strlen(filename)+1];
        strcpy(name,filename);


    if (fp=fopen(name,"r"))
          cout<<"File open Successfully"<<endl;
          else
            cout<<"File Failed to open"<<endl;


 }

bool ISBNPrefix::isRegistered(int area) const{ //start isRegistered
    int find, find1, find2;
    int i=1;
    bool pass;

  while(!feof(fp)  &&  i!=0) {

        //       area pub tit
        fscanf(fp,"%d %d %d",&find,&find1,&find2);

        if(area==find){
            i=0;
            pass=true;
        } else{
            pass=false;
         }

    } //end of while statement

    rewind(fp);
    return pass;


}   //exit isRegistered



int ISBNPrefix::minNoDigits(int area) const{ //start of minNoigits

int find,title,i=0,low=0,size_of_digit=0,count=0,first=0;
    char pub[8];
    pub[8]='\0';

    while(feof(fp)==i){//start of while

        fscanf(fp,"%d %s %d",&find,pub,&title);

        first=size_of_digit;

        if(area==find){// start of if area
            size_of_digit=strlen(pub);


            if(count==1){
                if(first<size_of_digit)
                    low=first;
                else
                    low=size_of_digit;
            }

            count++;

            if(size_of_digit<low)
                low=size_of_digit;


        }//end if of area

    }//end of while

    rewind(fp);
    return low;

} //end of minNodigits



bool ISBNPrefix::isRegistered(int area, const char* publisher) const{

    int i=1,find,pubfmax;
    char pubf[8];
    int pubfint,pubfint1;//get values
    pubf[8]='\0';
    bool check;

    while(!feof(fp)&& i!=0){//start of while

        fscanf(fp,"%d %s %d",&find,pubf,&pubfmax);

          if(area==find && strlen(publisher)>=strlen(pubf)){
             sscanf(pubf,"%d",&pubfint);
             sscanf(publisher,"%d",&pubfint1);

             if(pubfint<=pubfint1 && pubfint1<=pubfmax){
               check=true;
               i=0;
              }

              else {
                   check=false;
                   }


          }
          else{
            check=false;

          }

    }// end of while

    rewind(fp);
    return check;



}


ISBNPrefix::~ISBNPrefix(){

 if (fclose(fp)==0)
  cout<<"File Closed Successfully"<<endl;
  else
     cout<<"File Failed to close"<<endl;

    if(name!=NULL){
       delete [] name;
       cout<<"Name Deleted form memory"<<endl;
    }
}





ISBNPrefix::ISBNPrefix(const ISBNPrefix& source){  //COPY CONSTRUCTOR

    cout<<"copying Consturtor"<<endl;

     // allocate dynamic memory for grade string
     if (source.name != NULL) {
         name = new char[strlen(source.name) + 1];
         strcpy(name, source.name);
         fp=fopen(name,"r");

     }
     else
         name = NULL;

}

 /*ISBNPrefix& ISBNPrefix::operator=(const ISBNPrefix& source){

// allocate dynamic memory for grade string

     if (source.name != NULL) {
         name = new char[strlen(source.name) + 1];
         strcpy(name, source.name);
         fp=fopen(name,"r");

     }
     else
         name = NULL;

return *this;
}*/


