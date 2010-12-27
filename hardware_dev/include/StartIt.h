//----------------------------------------------------------------------------
// FILE: StartIt.h
// AUTHORS: Kevin Buckner
//   VERSION
//     - 0.1 Initial Creation
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// INCLUDE GUARD
//----------------------------------------------------------------------------
#ifndef _START_IT_H_ 
#define _START_IT_H_
//----------------------------------------------------------------------------
// INCLUDES
//----------------------------------------------------------------------------
#include "arduino.h"
#include <TimerOne.h>
#include <stdlib.h>
//----------------------------------------------------------------------------
// CLASS VARIABLES
//----------------------------------------------------------------------------
// NONE
//----------------------------------------------------------------------------
// CLASS DEFINITION
//----------------------------------------------------------------------------
class StartIt
{
  public:
  //-----------------------------------------------------------------------------
  //!@brief
  //! CONSTRUCTOR: StartIt()
  //!   Class default constructor.
  //!@param[in] Arduino obj
  //----------------------------------------------------------------------------
  StartIt(Arduino obj);
 
  //-----------------------------------------------------------------------------
  //!@brief
  //! DESTRUCTOR: ~StartIt()
  //!   Class destructor.
  //----------------------------------------------------------------------------
  ~StartIt();

  //-----------------------------------------------------------------------------
  //! METHOD: run_it()
  //!   Runs the main code we wish to execute on the microcontroller.
  //----------------------------------------------------------------------------
  void run_it();

  //-----------------------------------------------------------------------------
  //!@brief
  //! 
  //!  
  //----------------------------------------------------------------------------
  void setDateTime(char* inTxt);

  protected:
  private:

  //! Pointer to the microcontroller
  Arduino* m_ucontrolPtr;
};
#endif // _START_IT_H_

