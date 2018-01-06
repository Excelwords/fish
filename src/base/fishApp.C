#include "fishApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<fishApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

fishApp::fishApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  fishApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  fishApp::associateSyntax(_syntax, _action_factory);
}

fishApp::~fishApp() {}

void
fishApp::registerApps()
{
  registerApp(fishApp);
}

void
fishApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
fishApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
fishApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
fishApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
fishApp__registerApps()
{
  fishApp::registerApps();
}

extern "C" void
fishApp__registerObjects(Factory & factory)
{
  fishApp::registerObjects(factory);
}

extern "C" void
fishApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  fishApp::associateSyntax(syntax, action_factory);
}
