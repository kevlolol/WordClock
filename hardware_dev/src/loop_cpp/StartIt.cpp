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
  char* outFile = (char*)malloc(sizeof(char)*512);
  outFile = "C:\\Users\\Kevin\\Desktop\\Arduino\\loop_cpp\\test_results\\test_results_";
  sprintf(outFile, "%s%s%s%s",outFile,__DATE__,__TIME__,".txt");
  char* inTxt = (char*)malloc(sizeof(char)*2048);
  inTxt =  
"********************************************************************************\n \
    ~ PRELIMINARY TEST RESULTS ~\n \
      Author(s): Kevin Buckner\n \
      ^\
	     \
********************************************************************************"
; 
  Arduino* obj = m_ucontrolPtr;
  obj->serialConnect();
  obj->serialPrint("Outside the while loop.\n\n");
  obj->serialWriteToFile(inTxt, outFile);
  free(outFile);
  free(inTxt);

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

