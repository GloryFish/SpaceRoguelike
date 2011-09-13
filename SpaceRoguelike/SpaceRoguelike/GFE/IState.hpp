//
//  IState.hpp
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/10/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef SpaceRoguelike_IState_hpp
#define SpaceRoguelike_IState_hpp

#include <assert.h>
#include <SFML/System.hpp>
#include "Game.hpp"
#include "CoreTypes.hpp"

namespace GFE {
    class IState {
    public:
        
        virtual ~IState() {
            // Clear out pointers
        }
        
        /**
         * GetID will return the ID used to identify this State object
         * @return GQE::typeStateID is the ID for this State object
         */
        const GFE::stateID GetID(void) const
        {
            return stateID;
        }
        
        /**
         * DoInit is responsible for initializing this State.  HandleCleanup will
         * be called if mCleanup is true so Derived classes should always call
         * IState::DoInit() first before initializing their assets.
         */
        virtual void DoInit(void)
        {
        }
        
        /**
         * ReInit is responsible for Reseting this state when the 
         * StateManager::ResetActiveState() method is called.  This way a Game
         * State can be restarted without unloading and reloading the game assets
         */
        virtual void ReInit(void) = 0;
        
        /**
         * DeInit is responsible for marking this state to be cleaned up
         */
        void DeInit(void) {
            if(true == mInit) {
                mCleanup = true;
                mInit = false;
                mElapsedTime += (float)mElapsedClock.GetElapsedTime() / 1000.0f;

                if(true == mPaused) {
                    mPausedTime += (float)mPausedClock.GetElapsedTime() / 1000.0f;
                }
            }
        }
        
        /**
         * IsInitComplete will return true if the DoInit method has been called
         * for this state.
         * @return true if DoInit has been called, false otherwise or if DeInit
         *         was called
         */
        bool IsInitComplete(void)
        {
            return mInit;
        }
        
        /**
         * IsPaused will return true if this state is not the currently active
         * state.
         * @return true if state is not current active state, false otherwise
         */
        bool IsPaused(void)
        {
            return mPaused;
        }
        
        /**
         * Pause is responsible for pausing this State since the Application
         * may have lost focus or another State has become activate.
         */
        virtual void Pause(void)
        {
            if(false == mPaused)
            {
                mPaused = true;
                mPausedClock.Reset();
            }
        }
        
        /**
         * Resume is responsible for resuming this State since the Application
         * may have gained focus or the previous State was removed.
         */
        virtual void Resume(void)
        {
            if(true == mPaused)
            {
                mPaused = false;
                mPausedTime += (float)mPausedClock.GetElapsedTime() / 1000.0f;
            }
        }
        
        /**
         * HandleEvents is responsible for handling input events for this
         * State when it is the active State.
         * @param[in] theEvent to process from the App class Loop method
         */
        virtual void HandleEvents(sf::Event theEvent) = 0;
        
        /**
         * UpdateFixed is responsible for handling all State fixed update needs for
         * this State when it is the active State.
         */
        virtual void UpdateFixed(void) = 0;
        
        /**
         * UpdateVariable is responsible for handling all State variable update
         * needs for this State when it is the active State.
         * @param[in] theElapsedTime since the last Draw was called
         */
        virtual void UpdateVariable(float theElapsedTime) = 0;
        
        /**
         * Draw is responsible for handling all Drawing needs for this State
         * when it is the Active State.
         */
        virtual void Draw(void) = 0;
        
        /**
         * HandleCleanup is responsible for calling Cleanup if this class has been
         * flagged to be cleaned up after it completes the game loop.
         */
        void HandleCleanup(void)
        {
            if(true == mCleanup)
            {
                // Call cleanup
                Cleanup();
                
                // Clear our cleanup flag
                mCleanup = false;
            }
        }
        
        /**
         * GetElapsedTime will return one of the following:
         * 1) If this state is not paused: total elapsed time since DoInit was called
         * 2) If this state is paused: total elapsed time since Pause was called
         * 3) If this state is not initialized: total elapsed time from DoInit to DeInit
         * @return total elapsed time as described above.
         */
        float GetElapsedTime(void) const
        {
            float result = (float)mElapsedClock.GetElapsedTime() / 1000.0f;
            
            if(false == mInit)
            {
                result = mElapsedTime;
            }
            
            return result;
        }
        
    protected:
        /// Pointer to the App class
        Game*                  mApp;
        
        /**
         * IState constructor is private because we do not allow copies of our
         * Singleton class
         * @param[in] theID to use for this State object
         * @param[in] theApp is a pointer to the App derived class
         */
        IState(const stateID theID, Game* theApp) :
        mApp(theApp),
        stateID(theID),
        mInit(false),
        mPaused(false),
        mCleanup(false),
        mElapsedTime(0.0f),
        mPausedTime(0.0f)
        {
            // Check that our pointer is good
            assert(NULL != theApp && "IState::IState() theApp pointer is bad");
            
            // Keep a copy of our Application pointer
            mApp = theApp; 
        }
        
        /**
         * Cleanup is responsible for performing any cleanup required before
         * this State is removed.
         */
        virtual void Cleanup(void)
        {
        }
        
    private:
        /// The State ID
        const stateID     stateID;
        /// Boolean that indicates that DoInit has been called
        bool                  mInit;
        /// State is currently paused (not active)
        bool                  mPaused;
        /// State needs to be cleaned up at the end of the next game loop
        bool                  mCleanup;
        /// Clock will help us keep track of running and paused elapsed time
        sf::Clock             mElapsedClock;
        /// Total elapsed time since DoInit was called
        float                 mElapsedTime;
        /// Clock will help us keep track of time paused
        sf::Clock             mPausedClock;
        /// Total elapsed time paused since DoInit was called
        float                 mPausedTime;
        
        /**
         * Our copy constructor is private because we do not allow copies of
         * our Singleton class
         */
        IState(const IState&);  // Intentionally undefined
        
        /**
         * Our assignment operator is private because we do not allow copies
         * of our Singleton class
         */
        IState& operator=(const IState&); // Intentionally undefined
        
    }; // class IState
}



#endif
