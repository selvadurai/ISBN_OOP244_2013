#ifndef ISBNPREFIX_H
#define ISBNPREFIX_H

  class ISBNPrefix {
    FILE *fp;

    public:
        ISBNPrefix(const char* filename);

        ISBNPrefix(const ISBNPrefix& source);

        bool isRegistered(int area) const ;
        int minNoDigits(int area) const;
        bool isRegistered( int area, const char* publisher) const;
        ~ISBNPrefix();
 };


#endif
