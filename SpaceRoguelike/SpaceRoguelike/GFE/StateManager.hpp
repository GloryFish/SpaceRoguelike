#ifndef   SpaceRoguelike_StateManager_hpp
#define   SpaceRoguelike_StateManager_hpp
 
#include <vector>
#include <string>

#include "CoreTypes.hpp"

namespace GFE
{
  /// Provides game state manager class for managing game states
  class StateManager
  {
  public:
    /**
     * StateManager constructor
     */
    StateManager();

    /**
     * StateManager deconstructor
     */
    virtual ~StateManager();

    /**
     * RegisterApp will register a pointer to the App class so it can be used
     * by the StateManager for error handling and log reporting.
     * @param[in] theGame is a pointer to the App (or App derived) class
     */
    void RegisterGame(Game* theGame);

    /**
     * IsEmpty will return true if there are no active states on the stack.
     * @return true if state stack is empty, false otherwise.
     */
    bool IsEmpty(void);

    /**
     * AddActiveState will add theState provided as the current active
     * state.
     * @param[in] theState to set as the current state
     */
    void AddActiveState(IState* theState);

    /**
     * AddInactiveState will add theState provided as an inactive state.
     * @param[in] theState to be added as an inactive state
     */
    void AddInactiveState(IState* theState);

    /**
     * GetActiveState will return the current active state on the stack.
     * @return pointer to the current active state on the stack
     */
    IState* GetActiveState(void);

    /**
     * InactivateActiveState will cause the current active state to
     * become an inactive state without uninitializing its assets (doesn't
     * call DeInit) and return to the previous state on the stack. This
     * will cause the state to retain its assets.
     */
    void InactivateActivateState(void);

    /**
     * DropActiveState will cause the current active state to uninitialize
     * (calls DeInit) and become an inactive state and return to the
     * previous state on the stack. When a state is uninitialized its
     * assets are unloaded.
     */
    void DropActiveState(void);
 
    /**
     * ResetActiveState will cause the current active state to be reset
     * by calling the ReInit method for that state. This is useful for
     * "Play Again Y/N?" scenarios.
     */
    void ResetActiveState(void);

    /**
     * RemoveActiveState will cause the current active state to be removed
     * and return to the previous state on the stack.  Once a state has
     * been removed, you must re-add the state.  If you just want to
     * inactivate the current active state then use DropActiveState instead.
     */
    void RemoveActiveState(void);

    /**
     * SetActiveState will find the state specified by theStateID and make
     * it the current active state and move the previously current active
     * state as the next state.
     * @param[in] theStateID is the ID of the State to make active
     */
    void SetActiveState(stateID theStateID);
 
    /**
     * HandleCleanup is responsible for dealing with the cleanup of recently
     * dropped states.
     */
    void HandleCleanup(void);

  private:
    // Constants
    ///////////////////////////////////////////////////////////////////////////

    // Variables
    ///////////////////////////////////////////////////////////////////////////
    /// Pointer to the App class for error handling and logging
    Game*                  game;
    /// Stack to store the current and previously active states
    std::vector<IState*>  stack;
    /// Stack to store the dead states until they properly cleaned up
    std::vector<IState*>  dead;

    /**
     * StateManager copy constructor is private because we do not allow copies
     * of our class
     */
    StateManager(const StateManager&); // Intentionally undefined

    /**
     * Our assignment operator is private because we do not allow copies
     * of our class
     */
    StateManager& operator=(const StateManager&); // Intentionally undefined

  }; // class StateManager
}

#endif // CORE_STATE_MANAGER_HPP_INCLUDED

