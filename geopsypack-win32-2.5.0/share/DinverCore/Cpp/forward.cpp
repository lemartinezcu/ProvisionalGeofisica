
#include "forward.h"

/*!
  The Rastrigin function 2D is used as an example

    F(X) = A n + Sum [i=1,...,n] xi^2-A cos ( w xi )

    We use:
      n = 2
      A = 10
      -5 &lt; xi &lt; 5

  Two parameters: x1 and x2, from -5 to 5

  We impose that x&lt;y, further on we also use a secondary complex condition
  that [x, y] must be inside circle of radius 5, hence x1^2+x2^2&lt;25. The last
  condition is checked during misfit computation.
*/
AbstractForward * Forward::clone() const
{
  Forward * f = new Forward;
  RealSpace& parameterSpace = f->parameterSpace();
  // Setup two parameters and name them x1 and x2, with units set as meters.
  Parameter * x1Param = parameterSpace.addParameter("x1", "m", -5.0, 5.0, ParameterGrid::Linear, 0);
  Parameter * x2Param = parameterSpace.addParameter("x2", "m", -5.0, 5.0, ParameterGrid::Linear, 0);

  // Add the simple condition
  parameterSpace.addCondition(
    new SimpleCondition( x2Param, SimpleCondition::GreaterThan, 1.0, x1Param, 2.0 )
  );
  return f;
}

/*!
  This is the heart of the problem, enter here the forward and the misfit computation.
  \a model is a vector of parameterSpace().variableParameterCount() components (equal
  to the number of parameters initialized in the constructor).

  You can set \a ok to false if the input \a model contains unconsistent information.
  By default it is set to true.
*/
double Forward::misfit( double * model, bool& ok )
{
  // If you want to print received model to log (for debug)
  //printModel(model);

  // Check complex condition
  if ( model[0]*model[0]+model[1]*model[1] >= 25.0 ) {
    ok = false;
    return 0.0;
  }

  // Compute misfit value
  double misfit = 22;
  for (int i = 0; i<2; i++ ) {
    misfit += model[i]*model[i] - 10 * cos ( 2 * M_PI * model[i] )-1.0;
  }

  return misfit;
}
