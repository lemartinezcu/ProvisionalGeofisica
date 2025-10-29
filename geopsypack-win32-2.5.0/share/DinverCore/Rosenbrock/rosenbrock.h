/*
  Do not alter this file.

  This is required by dinver to recognize this library as a plugin.

  You can rename myplugin.h and myplugin.cpp, if you also change the include
  in myplugin.cpp.
*/

#include <DinverCore.h>
#include <DinverCore/DinverC.h>

class CForward : public AbstractForward
{
public:
  virtual AbstractForward * clone() const {
    CForward * f = new CForward;
    dinver_init_run( f );
    return f;
  }
  virtual double misfit( bool& ok ) {
    int ndAll = parameterSpace().allParameterCount();
    float model[ndAll];
    for (int i=0;i<ndAll;i++) {
      model[i] = parameterSpace().parameter(i)->realValue();
    }
    float misfitValue = 1e99;
    int iok = ok;
    dinver_forward( ndAll, model, &iok, &misfitValue );
    ok = iok;
    return misfitValue;
  }
};

class CPlugin: public DinverInterface
{
  Q_OBJECT
  Q_INTERFACES( DinverCore::DinverInterface );
public:
  CPlugin() { dinver_init_global(); }
  virtual QString tag() const { return dinver_plugin_tag(); }
  virtual QString title() const { return dinver_plugin_title(); }
  virtual QString version() const { return dinver_plugin_version(); }
  virtual QString description() const { return dinver_plugin_description(); }
  virtual const char * interfaceVersion() const { return DINVERCORE_VERSION; }
  virtual AbstractForward * createForward() { return new CForward; }
};
