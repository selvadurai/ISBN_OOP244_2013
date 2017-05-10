#ifndef ISBNPREFIX_H
#define ISBNPREFIX_H

  class ISBNPrefix {
      FILE *fp;
      char* name;
      ISBNPrefix(const ISBNPrefix&); //copy construtor
      ISBNPrefix& operator=(const ISBNPrefix&); //operator overloading

       public:

        ISBNPrefix(const char* filename);
        bool isRegistered(int area) const ;
        int minNoDigits(int area) const;
        bool isRegistered( int area, const char* publisher) const;
        virtual ~ISBNPrefix();

 };

#endif
