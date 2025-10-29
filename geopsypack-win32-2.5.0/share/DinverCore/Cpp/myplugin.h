
#include <DinverCore.h>

class MyPlugin: public DinverInterface
{
  Q_OBJECT
  Q_INTERFACES( DinverCore::DinverInterface );
public:
  virtual QString tag() const;
  virtual QString title() const ;
  virtual QString version() const ;
  virtual QString description() const ;

  virtual AbstractForward * createForward();
  virtual bool initForward(AbstractForward * forward);
  // Used for compatibility checks upon startup of the plugin
  virtual const char * interfaceVersion() const { return DINVERCORE_VERSION; }
};
