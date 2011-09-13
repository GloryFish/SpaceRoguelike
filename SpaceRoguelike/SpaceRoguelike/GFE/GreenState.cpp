
#import "GreenState.hpp"
#import "Logger.hpp"

#import <assert.h>

namespace GFE
{
  GreenState::GreenState(Game* theGame) :
    IState("Green", theGame)
  {
      Logger::Log() << "GreenState ctor";
  }

   GreenState::~GreenState(void)
  {
  }

  void GreenState::HandleEvents(sf::Event theEvent)
  {
  }

  void GreenState::DoInit(void)
  {
      Logger::Log() << "GreenState Init";

    // First call our base class implementation
    IState::DoInit();
    
    // Check our App pointer
    assert(NULL != game && "GreenState::DoInit() bad app pointer");
  }

  void GreenState::ReInit(void)
  {
    // Do nothing yet
  }

  void GreenState::UpdateFixed(void)
  {
    // Check our App pointer
    assert(NULL != game && "SplashState::UpdateFixed() bad app pointer, init must be called first");

    // Drop our state after 10 seconds have elapsed
    if(false == IsPaused() && GetElapsedTime() > 10.0f)
    {
      game->stateManager.RemoveActiveState();
    }
  }

  void GreenState::UpdateVariable(float theElapsedTime)
  {
    // Check our App pointer
    assert(NULL != game && "SplashState::UpdateVariable() bad app pointer, init must be called first");
  }

  void GreenState::Draw(void)
  {
    // Check our App pointer
    assert(NULL != game && "SplashState::Draw() bad app pointer, init must be called first");

      game->window.Clear(sf::Color::Green);
  }

  void GreenState::Cleanup(void)
  {
    // Last of all, call our base class implementation
    IState::Cleanup();
  }

}
