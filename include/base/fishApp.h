#ifndef FISHAPP_H
#define FISHAPP_H

#include "MooseApp.h"

class fishApp;

template <>
InputParameters validParams<fishApp>();

class fishApp : public MooseApp
{
public:
  fishApp(InputParameters parameters);
  virtual ~fishApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* FISHAPP_H */
