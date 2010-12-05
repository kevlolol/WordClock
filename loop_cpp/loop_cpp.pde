//-----------------------------------------------------------------------------
// FILE: loop_cpp.pde
// AUTHORS: Kevin Buckner
//   VERSION
//     - 0.1 Initial Creation
//-----------------------------------------------------------------------------
///----------------------------------------------------------------------------
/// INCLUDES
///----------------------------------------------------------------------------
#include <Client.h>
#include <Ethernet.h>
#include <Server.h>
#include <Udp.h>
#include <SPI.h>
#include <StartIt.h>
///----------------------------------------------------------------------------
/// GLOBAL VARIABLES
///----------------------------------------------------------------------------
// NONE
///----------------------------------------------------------------------------
/// ENTRY ROUTINES
///----------------------------------------------------------------------------
/**************************************************************************//**
* ROUTINE: setup()
*   Loads settings onto the microcontroller.
*
* @param[out] None
* @param[in]  None
******************************************************************************/
void setup()
{

}

/**************************************************************************//**
* ROUTINE: loop()
*   Loops forever.  Equivalent to a traditional C++ main() routine with a 
* while(1) loop in the body.  In this case, loop() would execute whatever would 
* be placed in the while(1) loop.
*
* @param[out] None
* @param[in]  None
******************************************************************************/
void loop()
{
  // Pointer to start object
  StartIt* startPtr = new StartIt();  
  // Entry point
  startPtr->run();
}


