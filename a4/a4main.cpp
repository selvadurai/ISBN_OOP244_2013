#include <iostream>
using namespace std;
#include "ISBNPrefix.h"
#include "SpecialOrder.h"


int main(){
ISBNPrefix list("prefixRanges.txt");

ISBN isbn("0003194876" ,list);


SpecialOrder t(isbn, "put");

return 0;
}
