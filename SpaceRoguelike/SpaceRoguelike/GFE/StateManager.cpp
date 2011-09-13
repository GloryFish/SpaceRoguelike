
#include "StateManager.hpp"

#include <assert.h>
#include <stddef.h>
#include "Core.hpp"

namespace GFE
{
  StateManager::StateManager() :
    game(NULL)
  {
  }

  StateManager::~StateManager()
  {

    // Drop all active states
    while(!stack.empty())
    {
      // Retrieve the currently active state
      IState* anState = stack.back();
 
      // Pop the currently active state off the stack
      stack.pop_back();
 
      // Pause the currently active state
      anState->Pause();
 
      // De-initialize the state
      anState->DeInit();

      // Handle the cleanup before we pop it off the stack
      anState->HandleCleanup();
 
      // Just delete the state now
      delete anState;

      // Don't keep pointers around we don't need
      anState = NULL;
    }

    // Delete all our dropped states
    while(!dead.empty())
    {
      // Retrieve the currently active state
      IState* anState = dead.back();
 
      // Pop the currently active state off the stack
      dead.pop_back();
 
      // Pause the currently active state
      anState->Pause();
 
      // De-initialize the state
      anState->DeInit();
 
      // Handle the cleanup before we pop it off the stack
      anState->HandleCleanup();
 
      // Just delete the state now
      delete anState;

      // Don't keep pointers around we don't need
      anState = NULL;
    }
 
    // Clear pointers we don't need anymore
    game = NULL;
  }

  void StateManager::RegisterGame(Game* theGame)
  {
    // Check that our pointer is good
    assert(NULL != theGame && "StateManager::RegisterGame() theGame pointer provided is bad");

    // Make a note of the pointer
    assert(NULL == game && "StateManager::RegisterGame() theGame pointer was already registered");
    game = theGame;
  }

  bool StateManager::IsEmpty(void)
  {
    return stack.empty();
  }

  void StateManager::AddActiveState(IState* theState)
  {
    // Check that they didn't provide a bad pointer
    assert(NULL != theState && "StateManager::AddActiveState() received a bad pointer");
 
    // Is there a state currently running? then Pause it
    if(!stack.empty())
    {
      // Pause the currently running state since we are changing the
      // currently active state to the one provided
      stack.back()->Pause();
    }

    // Add the active state
    stack.push_back(theState);
 
    // Initialize the new active state
    stack.back()->DoInit();
  }

  void StateManager::AddInactiveState(IState* theState)
  {
    // Check that they didn't provide a bad pointer
    assert(NULL != theState && "StateManager::AddInactiveState() received a bad pointer");

    // Add the inactive state to the bottom of the stack
    stack.insert(stack.begin(), theState);
  }

  IState* StateManager::GetActiveState(void)
  {
    return stack.back();
  }

  void StateManager::InactivateActivateState(void)
  {
    // Is there no currently active state to drop?
    if(!stack.empty())
    {
      // Retrieve the currently active state
      IState* anState = stack.back();
 
      // Pause the currently active state
      anState->Pause();

      // Pop the currently active state off the stack
      stack.pop_back();
 
      // Move this now inactive state to the absolute back of our stack
      stack.insert(stack.begin(), anState);
 
      // Don't keep pointers around we don't need anymore
      anState = NULL;
    }
    else
    {
      // Quit the application with an error status response
      if(NULL != game)
      {
        game->Quit(StatusAppStackEmpty);
      }
      return;
    }
 
    // Is there another state to activate? then call Resume to activate it
    if(!stack.empty())
    {
      // Has this state ever been initialized?
      if(stack.back()->IsInitComplete())
      {
        // Resume the new active state
        stack.back()->Resume();
      }
      else
      {
        // Initialize the new active state
        stack.back()->DoInit();
      }
    }
    else
    {
      // There are no states on the stack, exit the program
      if(NULL != game)
      {
        game->Quit(StatusAppOK);
      }
    }
  }

  void StateManager::DropActiveState(void)
  {
    // Is there no currently active state to drop?
    if(!stack.empty())
    {
      // Retrieve the currently active state
      IState* anState = stack.back();

      // Pause the currently active state
      anState->Pause();

      // Deinit currently active state before we pop it off the stack
      // (HandleCleanup() will be called by IState::DoInit() method if this
      // state is ever set active again)
      anState->DeInit();
 
      // Pop the currently active state off the stack
      stack.pop_back();
 
      // Move this now inactive state to the absolute back of our stack
      stack.insert(stack.begin(), anState);
 
      // Don't keep pointers around we don't need anymore
      anState = NULL;
    }
    else
    {
      // Quit the application with an error status response
      if(NULL != game)
      {
        game->Quit(StatusAppStackEmpty);
      }
      return;
    }

    // Is there another state to activate? then call Resume to activate it
    if(!stack.empty())
    {
      // Has this state ever been initialized?
      if(stack.back()->IsInitComplete())
      {
        // Resume the new active state
        stack.back()->Resume();
      }
      else
      {
        // Initialize the new active state
        stack.back()->DoInit();
      }
    }
    else
    {
      // There are no states on the stack, exit the program
      if(NULL != game)
      {
        game->Quit(StatusAppOK);
      }
    }
  }

  void StateManager::ResetActiveState(void)
  {
    // Is there no currently active state to reset?
    if(!stack.empty())
    {
      // Retrieve the currently active state
      IState* anState = stack.back();
 
      // Pause the currently active state
      anState->Pause();
 
      // Call the ReInit method to Reset the currently active state
      anState->ReInit();
 
      // Resume the currently active state
      anState->Resume();
 
      // Don't keep pointers around we don't need anymore
      anState = NULL;
    }
    else
    {
      // Quit the application with an error status response
      if(NULL != game)
      {
        game->Quit(StatusAppStackEmpty);
      }
      return;
    }
  }

  void StateManager::RemoveActiveState(void)
  {
    // Is there no currently active state to drop?
    if(!stack.empty())
    {
      // Retrieve the currently active state
      IState* anState = stack.back();
 
      // Pause the currently active state
      anState->Pause();
 
      // Cleanup the currently active state before we pop it off the stack
      anState->DeInit();
 
      // Pop the currently active state off the stack
      stack.pop_back();
 
      // Move this state to our dropped stack
      dead.push_back(anState);
 
      // Don't keep pointers around we don't need anymore
      anState = NULL;
    }
    else
    {
      // Quit the application with an error status response
      if(NULL != game)
      {
        game->Quit(StatusAppStackEmpty);
      }
      return;
    }
 
    // Is there another state to activate? then call Resume to activate it
    if(!stack.empty())
    {
      // Has this state ever been initialized?
      if(stack.back()->IsInitComplete())
      {
        // Resume the new active state
        stack.back()->Resume();
      }
      else
      {
        // Initialize the new active state
        stack.back()->DoInit();
      }
    }
    else
    {
      // There are no states on the stack, exit the program
      if(NULL != game)
      {
        game->Quit(StatusAppOK);
      }
    }
  }
 
  void StateManager::SetActiveState(stateID theStateID)
  {
    std::vector<IState*>::iterator it;
 
    // Find the state that matches theStateID
    for(it=stack.begin(); it < stack.end(); it++)
    {
      // Does this state match theStateID? then activate it as the new
      // currently active state
      if((*it)->GetID() == theStateID)
      {
        // Get a pointer to soon to be currently active state
        IState* anState = *it;
 
        // Erase it from the list of previously active states
        stack.erase(it);
 
        // Is there a state currently running? then Pause it
        if(!stack.empty())
        {
          // Pause the currently running state since we are changing the
          // currently active state to the one specified by theStateID
          stack.back()->Pause();
        }

        // Add the new active state
        stack.push_back(anState);
 
        // Don't keep pointers we don't need around
        anState = NULL;

        // Has this state ever been initialized?
        if(stack.back()->IsInitComplete())
        {
          // Resume the new active state
          stack.back()->Resume();
        }
        else
        {
          // Initialize the new active state
          stack.back()->DoInit();
        }

        // Exit our find loop
        break;
      } // if((*it)->GetID() == theStateID)
    } // for(it=stack.begin(); it < stack.end(); it++)
  }
 
  void StateManager::HandleCleanup(void)
  {
    // Remove one of our dead states
    if(!dead.empty())
    {
      // Retrieve the dead state
      IState* anState = dead.back();
      assert(NULL != anState && "StateManager::HandleCleanup() invalid dropped state pointer");
 
      // Pop the dead state off the stack
      dead.pop_back();
 
      // Call the DeInit if it hasn't been called yet
      if(anState->IsInitComplete())
      {
        anState->DeInit();
      }

      // Next, call HandleCleanup for this state
      anState->HandleCleanup();

      // Just delete the state now
      delete anState;

      // Don't keep pointers around we don't need
      anState = NULL;
    }
  }

}
