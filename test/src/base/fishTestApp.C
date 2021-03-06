#include "fishTestApp.h"
#include "fishApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<fishTestApp>()
{
  InputParameters params = validParams<fishApp>();
  return params;
}

fishTestApp::fishTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  fishApp::registerObjectDepends(_factory);
  fishApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  fishApp::associateSyntaxDepends(_syntax, _action_factory);
  fishApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    fishTestApp::registerObjects(_factory);
    fishTestApp::associateSyntax(_syntax, _action_factory);
  }
}

fishTestApp::~fishTestApp() {}

void
fishTestApp::registerApps()
{
  registerApp(fishApp);
  registerApp(fishTestApp);
}

void
fishTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
fishTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
fishTestApp__registerApps()
{
  fishTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
fishTestApp__registerObjects(Factory & factory)
{
  fishTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
fishTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  fishTestApp::associateSyntax(syntax, action_factory);
}
