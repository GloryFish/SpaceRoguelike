
#ifndef   GREEN_STATE_HPP_INCLUDED
#define   GREEN_STATE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "IState.hpp"

namespace GFE
{
  /// Provides simple Splash screen game state
  class GreenState : public IState
  {
  public:
    /**
     * GreenState constructor
     * @param[in] theGame is a pointer to the App class.
     */
    GreenState(Game* theGame);

    /**
     * SplashState deconstructor
     */
    virtual ~GreenState(void);

    /**
     * DoInit is responsible for initializing this State
     */
    virtual void DoInit(void);

    /**
     * ReInit is responsible for Reseting this state when the 
     * StateManager::ResetActiveState() method is called.  This way a Game
     * State can be restarted without unloading and reloading the game assets
     */
    virtual void ReInit(void);

    /**
     * HandleEvents is responsible for handling input events for this
     * State when it is the active State.
     * @param[in] theEvent to process from the App class Loop method
     */
    virtual void HandleEvents(sf::Event theEvent);

    /**
     * UpdateFixed is responsible for handling all State fixed update needs for
     * this State when it is the active State.
     */
    virtual void UpdateFixed(void);
 
    /**
     * UpdateVariable is responsible for handling all State variable update
     * needs for this State when it is the active State.
     * @param[in] theElapsedTime since the last Draw was called
     */
    virtual void UpdateVariable(float theElapsedTime);

    /**
     * Draw is responsible for handling all Drawing needs for this State
     * when it is the Active State.
     */
    virtual void Draw(void);

  protected:
    /**
     * Cleanup is responsible for performing any cleanup required before
     * this State is removed.
     */
    virtual void Cleanup(void);

  private:
    // Variables
    /////////////////////////////////////////////////////////////////////////
  }; // class GreenState
}

#endif // CORE_SPLASH_STATE_HPP_INCLUDED
