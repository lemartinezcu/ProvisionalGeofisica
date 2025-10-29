#ifndef FORWARD_H
#define FORWARD_H

#include <DinverCore.h>

class Forward : public AbstractForward
{
public:
  virtual AbstractForward * clone() const;
  virtual double misfit( double * model, bool& ok );
};

#endif // FORWARD_H
