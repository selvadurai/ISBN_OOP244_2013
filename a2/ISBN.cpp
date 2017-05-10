#include <iostream>
#include <cstdio>
#include <stdlib.h>     /* atoi */
#include <cstring>

using namespace std;
#include "ISBN.h"
#include "ISBNPrefix.h"

ISBN::ISBN(){
    strcpy(string," ");
    strcpy(area, "");
    strcpy(publisher, "");
    strcpy(title, "");
    isbnreg=false;
}


ISBN::ISBN(const char* str, const ISBNPrefix& list){

int pass=0,i=0,x=0, area_length=0, pub_length=0, area_num=0, remainder=0,y=0;

    /*######################################################
    #   Varaible notifiation                               #
    #   i - counts the  number of chars going into area    #
    #   x -counts the  number of chars going into publiser #
    #   y -counts the  number of chars going into title    #
    ########################################################
    */
    isbnreg=false;

    if(str!=NULL && isValid(str)==1)
    {

        strcpy(string,str);


        for(i=0; i<5; i++) //start of for loop looking area
        {

            area[i]=str[i];
            area[i+1]='\0';
            area_num=atoi(area);

            if(list.isRegistered(area_num)==1  )  //verfies area
            {
                area_length=strlen(area);
                num=area_num;

                for(x=0; x<7; x++) //looking for publisher
                {
                    publisher[x]=str[area_length+x];
                    publisher[x+1]='\0';

                    if(list.isRegistered(area_num,publisher)==1 && area_length!=0)  //verfies publisher if true find title
                    {
                        x=100;
                        i=100;
                        pub_length=strlen(publisher);

                        remainder=pub_length+area_length;
                        pass=1;

                        while(remainder<9) //finding title
                        {
                            //y is intilized to 0

                            title[y]=str[remainder];
                            title[y+1]='\0';
                             isbnreg=true;
                            //adds 1
                            y++;
                            remainder++;
                        } //end of finding title

                    } // end of verfies publisher if true find title




                } //end of looking for publisher



            }//end of verfiries area
            else  //if area is not verify
            {
                pass=0;
            }// end if area is not verfy



        } //end loop looking for area

    }//end of looking for To verify Null
      else
          strcpy(string," "); //if string is not valid
}



 bool ISBN::isRegistered(const ISBNPrefix& list){
      bool pass;

      if(list.isRegistered(num)==1 && list.isRegistered(num,publisher)==1)
              pass=true;
            else
              pass=false;

      return pass;
}


bool ISBN::empty() const{
    bool pass;

    if(isValid(string)==0|| isbnreg==false)
        pass=true;
    else
        pass=false;

    return pass;
}



bool ISBN::isRegistered() const{

    bool pass;

    if(isbnreg==true)
        pass=true;
    else
        pass=false;

 return pass;
}


void ISBN::toStr(char* str) const{
    strcpy(str,string);
}


void  ISBN::toStrWithStyle(char* str) const {
    

    if(isValid(string)==1 && isbnreg==true){
        strcpy(str,area);
        strcat(str,"-");
        strcat(str,publisher);
        strcat(str,"-");
        strcat(str,title);
        strcat(str,"-");
        str[12] = string[9];
        str[13] = '\0';

    }
    else{
        strcpy(str,string);
        str[strlen(string)+1]='\0';
    }


}


void ISBN::display(ostream& os) const{

os<<string<<endl;
}


int isValid(const char* str){

    int check=0,i=0,numval=0,count=10;

    if(str!=NULL && str[0]>=48 && str[0]<=57)  //start of null if statement
    {
        for (i=0; i<strlen(str); i++)  //start of for statement
        {
            //48=0 to 57=9 in ascci table

            if(str[i]>=48 && str[i]<=57)  // asci if statemen
                {

                    switch (str[i])
                    {

                    case '0'://finds area
                        numval+=(0*count);
                        break;

                    case '1':
                        numval+=(1*count);
                        break;

                    case '2':
                        numval+=(2*count);
                        break;

                    case '3'://finds area
                        numval+=(3*count);
                        break;

                    case '4':
                        numval+=(4*count);
                        break;


                    case '5':
                        numval+=(5*count);
                        break;

                    case '6':
                        numval+=(6*count);
                        break;


                    case '7':
                        numval+=(7*count);
                        break;

                    case '8'://finds area
                        numval+=(8*count);
                        break;

                    case '9':
                        numval+=(9*count);
                        break;


                }//end of switch


                count--;
            }//end of if statemment

        } //end for statement




            if(( numval % 11)==0 && numval>=0 )
                check=1;
            else
                check=0;

           /*Found algrothrim if string char 9 ends 'X'
             it must have remainder value of 1 */

            if(str[9]=='X' && (numval %11)==1)
                    check=1;
        }// end of str null statement

        return check;

}


