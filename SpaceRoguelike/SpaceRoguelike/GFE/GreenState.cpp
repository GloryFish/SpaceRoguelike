/**
 * Provides the SplashState in the GQE namespace which is typically
 * the first state to be loaded for an application.
 *
 * @file src/GQE/Core/states/SplashState.hpp
 * @author Ryan Lindeman
 * @date 20100710 - Initial Release
 * @date 20110125 - Use the new RemoveActiveState not DropActiveState.
 * @date 20110127 - Moved to GQE Core library and src directory
 * @date 20110218 - Added ReInit method
 * @date 20110218 - Change to system include style
 * @date 20110625 - Added UpdateVariable and changed Update to UpdateFixed
 * @date 20110627 - Removed extra ; from namespace
 * @date 20110721 - Remove * from GetAsset() calls since it now returns TYPE&
 */
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
    assert(NULL != mApp && "GreenState::DoInit() bad app pointer");
  }

  void GreenState::ReInit(void)
  {
    // Do nothing yet
  }

  void GreenState::UpdateFixed(void)
  {
    // Check our App pointer
    assert(NULL != mApp && "SplashState::UpdateFixed() bad app pointer, init must be called first");

    // Drop our state after 10 seconds have elapsed
    if(false == IsPaused() && GetElapsedTime() > 10.0f)
    {
      mApp->stateManager.RemoveActiveState();
    }
  }

  void GreenState::UpdateVariable(float theElapsedTime)
  {
    // Check our App pointer
    assert(NULL != mApp && "SplashState::UpdateVariable() bad app pointer, init must be called first");
  }

  void GreenState::Draw(void)
  {
    // Check our App pointer
    assert(NULL != mApp && "SplashState::Draw() bad app pointer, init must be called first");

      mApp->window.Clear(sf::Color::Green);
  }

  void GreenState::Cleanup(void)
  {
    // Last of all, call our base class implementation
    IState::Cleanup();
  }

} // namespace GQE

/**
 * Copyright (c) 2010-2011 Ryan Lindeman
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
