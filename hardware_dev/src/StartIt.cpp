//----------------------------------------------------------------------------
// FILE:StartIt.cpp
// AUTHORS: Kevin Buckner
//   VERSION
//     - 0.1 Initial Creation
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include "StartIt.h"
//-----------------------------------------------------------------------------
// CLASS METHODS
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//!@brief
//!
//! CONSTRUCTOR: StartIt()
//!   Class default constructor.
//---------------------------------------------------------------------------
StartIt::StartIt(Arduino obj)
:
m_ucontrolPtr(NULL)
{
  m_ucontrolPtr = &obj;
}

//-----------------------------------------------------------------------------
//!@brief
//! METHOD: run_it()
//!   Runs the main code we wish to execute on the microcontroller.
//----------------------------------------------------------------------------
void StartIt::run_it()
{
  Timer1.attachInterrupt(m_ucontrolPtr->interrupt);
  while(1)
  {
    // Code to execute goes here
  }
}

//-----------------------------------------------------------------------------
//!@brief
//! DESTRUCTOR: ~StartIt()
//!   Class destructor.
//----------------------------------------------------------------------------
StartIt::~StartIt()
{
  free(m_ucontrolPtr);
}

//-----------------------------------------------------------------------------
//!@brief
//! 
//!  
//----------------------------------------------------------------------------
void StartIt::setDateTime(char* inTxt)
{
  char *pos = strchr(inTxt, '^');
  char endHeader[] = 
"********************************************************************************\n";

  sprintf(pos, "%s\\n%s\\n\\n%s",__DATE__,__TIME__, endHeader);
}


//-----------------------------------------------------------------------------
// END CLASS METHODS
//-----------------------------------------------------------------------------

