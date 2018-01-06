#ifndef FISHTESTAPP_H
#define FISHTESTAPP_H

#include "MooseApp.h"

class fishTestApp;

template <>
InputParameters validParams<fishTestApp>();

class fishTestApp : public MooseApp
{
public:
  fishTestApp(InputParameters parameters);
  virtual ~fishTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* FISHTESTAPP_H */
