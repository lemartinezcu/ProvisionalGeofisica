#include <DinverCore/DinverC.h>

/*
  A short name without space and special character to identify the plugin.
  It must be unique. To get a list of plugin tag: dinver -plugin-list

  Mandatory to define it.
*/
const char * dinver_plugin_tag()
{
  return "Rosenbrock";
}

/*
  A brief user frienly string to identify the plugin

  Mandatory to define it.
*/
const char * dinver_plugin_title()
{
  return "Rosenbrock function";
}

/*
  A string containing the version of the plugin

  Mandatory to define it.
*/
const char * dinver_plugin_version()
{
  return "1.0";
}

/*
  A (long) user frienly string to describe the plugin. It can be a html string.

  Mandatory to define it.
*/
const char * dinver_plugin_description()
{
  return "Search for the minimum of the Rosenbrock function."
         "Mainly for testing exploration capabilities by "
         "comparison with Rickwood and Sambridge 2006.";
}

/*
  Initialize global variables. If you share global variables between inversion runs and if
  runs can modify these global variables, you must be careful of correctly lock ressources.
  If you want to avoid such problems, make sure than common variables are written only during
  initialization or do not start more than one run at a time inside dinver.
*/
void dinver_init_global()
{
}

/*
  Initialize parameters and eventually misfit computation
*/
void dinver_init_run( DinverForward forward )
{
  dinver_set_parameter_count( forward, 2 );
  // Starts at 0.004 to avoid misfit 0. It is not really a fundamental problem to have a
  // minimum misfit of zero but as misfits are plotted on a log scale, this is nicer
  // if misfit does not reach zero exactly.
  dinver_set_range( forward, 0, -2.004, 2.0, 0, 0 );
  dinver_set_range( forward, 1, -2.004, 2.0, 0, 0 );
}

/*
  This is the heart of the problem, enter here the forward and the misfit computation.

  You can set ok to false if the input model contains unconsistent information.
  By default it is set to true.
*/
void dinver_forward( int nd, float * model, int * ok, float * misfit)
{
  float tmp1 = 1.0 - model[0];
  float tmp2 = model[1]-model[0]*model[0];
  *misfit = tmp1*tmp1 + 100.0*tmp2*tmp2;
}
