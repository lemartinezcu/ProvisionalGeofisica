#include <math.h>
#include <DinverCore/DinverC.h>

/*
  A short name without space and special character to identify the plugin.
  It must be unique. To get a list of plugin tag: dinver -plugin-list

  Mandatory to define it.
*/
const char * dinver_plugin_tag()
{
  return "CTemplate";
}

/*
  A brief user frienly string to identify the plugin

  Mandatory to define it.
*/
const char * dinver_plugin_title()
{
  return "C template";
}

/*
  A string containing the version of the plugin

  Mandatory to define it.
*/
const char * dinver_plugin_version()
{
  return "1.0.0";
}

/*
  A (long) user frienly string to describe the plugin. It can be a html string.

  Mandatory to define it.
*/
const char * dinver_plugin_description()
{
  return "<p>Minima of Rastrigin's Function.</p>";
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
  dinver_set_range( forward, 0, -5.0, 5.0, 0, 0);
  dinver_set_range( forward, 1, -5.0, 5.0, 0, 0);
  dinver_add_greater_than_condition( forward, 1, 1.0, 0, 2.0 );
}

/*
  This is the heart of the problem, enter here the forward and the misfit computation.

  You can set ok to false if the input model contains unconsistent information.
  By default it is set to true.
*/
void dinver_forward( int nd, float * model, int * ok, float * misfit)
{
  int i;
  // Check complex condition
  if ( model[0]*model[0]+model[1]*model[1] >= 25.0 ) {
    *ok = 0;
    return;
  }

  // Compute misfit value
  *misfit = 22;
  for (i = 0; i<2; i++ ) {
    *misfit += model[i]*model[i] - 10 * cos ( 2 * M_PI * model[i] )-1.0;
  }
}
