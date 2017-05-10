

#ifndef SPECIALORDER
#define SPECIALORDER 

#include "Order.h"

class SpecialOrder: public Order
{
 protected:
  char *instructor;
  public:
  SpecialOrder();

  SpecialOrder(const ISBN& isbn, const char* instr);
  SpecialOrder(const SpecialOrder& source);
  bool add(istream& is);
  virtual void display(ostream& os) const;
  virtual SpecialOrder& operator=(const SpecialOrder& source); 
  virtual ~SpecialOrder();
};

#endif


