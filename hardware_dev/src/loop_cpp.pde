//----------------------------------------------------------------------------
// FILE: loop_cpp.pde
// AUTHORS: Kevin Buckner
//   VERSION
//     - 0.1 Initial Creation
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <Client.h>
#include <Ethernet.h>
#include <Server.h>
#include <Udp.h>
#include <SPI.h>
#include "StartIt.h"
//-----------------------------------------------------------------------------
// GLOBAL VARIABLES
//-----------------------------------------------------------------------------
// NONE

//-----------------------------------------------------------------------------
// ENTRY ROUTINES
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//!@brief
//!
//! ROUTINE: setup()
//!   Loads settings onto the microcontroller.
//!
//! @return None
//! @param[in]  None
//----------------------------------------------------------------------------
void setup()
{

}

//-----------------------------------------------------------------------------
//!@brief
//! ROUTINE: loop()
//!   Loops forever.  Equivalent to a traditional C++ main() routine with a 
//! while(1) loop in the body.  In this case, loop() would execute whatever would 
//! be placed in the while(1) loop.
//!
//! @return None
//! @param[in]  None
//----------------------------------------------------------------------------
void loop()
{
  // Create Arduino object
  Arduino arduinoObj;
  // Create start object
  StartIt startObj(arduinoObj);  
  // Entry point
  startObj.run_it();
}


