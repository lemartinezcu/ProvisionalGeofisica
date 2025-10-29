
/*
  A short name without space and special character to identify the plugin.
  It must be unique. To get a list of plugin tag: dinver -plugin-list

  Mandatory to define it.
*/
const char * dinver_plugin_tag()
{
  return "FortranTemplate";
}

/*
  A brief user frienly string to identify the plugin

  Mandatory to define it.
*/
const char * dinver_plugin_title()
{
  return "Fortran template";
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

