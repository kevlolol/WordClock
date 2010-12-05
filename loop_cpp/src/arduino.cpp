//-----------------------------------------------------------------------------
// FILE: arduino.cpp
// AUTHORS: Kevin Buckner
//   VERSION
//     - 0.1 Initial Creation
//-----------------------------------------------------------------------------
///----------------------------------------------------------------------------
/// INCLUDES
///----------------------------------------------------------------------------
#include "arduino.h"
///----------------------------------------------------------------------------
/// CLASS METHODS
///----------------------------------------------------------------------------
/**************************************************************************//**
* METHOD: Arduino::Arduino()
*   Class default constructor.
*
* @param[out] None
* @param[in]  None
******************************************************************************/
Arduino::Arduino()
{

}

/**************************************************************************//**
* METHOD: Arduino::Arduino()
*   Class ethernet style constructor.
* 
* @param[out] None
* @param[in] byte mac[6] (mac address)
* @param[in] byte ip[4] (ip address [IEEE 802.11 IPv4])
******************************************************************************/
Arduino::Arduino(byte mac [6],  byte ip [4])
{
  //----------------------------- Parameters --------------------------------//
  int i;
  //-------------------------------------------------------------------------//
 
  for(i = 0; i < 6; i++)
  {
    this->m_mac[i] = mac[i];
    if(i < 4)
    {
      m_ip[i] = ip[i];
    }
    else
    {
      // Do nothing
    }
  }
  Ethernet.begin(m_mac, m_ip);
}

/**************************************************************************//**
* POINTER COPY CONSTRUCTOR: Arduino::Arduino(const Arduino &rhs)
*   Class copy constructor.  Effectively copies over all private member 
* variables from object rhs.
*
* @param[out] None
* @param[in]  const Arduino rhs - Reference to the right hand side of the 
*                                 equation
******************************************************************************/
Arduino::Arduino(const Arduino &rhs)
{
  //----------------------------- Parameters --------------------------------//
  int i;
  //-------------------------------------------------------------------------//
  
  //------------------------------- Routine ---------------------------------//
  for(i = 0; i < 6; i++)
  {
    this->m_mac[i] = rhs.m_mac[i];
    if(i < 4)
    {
      this->m_ip[i] = rhs.m_ip[i];
    }
    else
    {
      // Do nothing
    }
  }
  //-------------------------------------------------------------------------//
}


/**************************************************************************//**
* ASSIGNMENT OPERATOR: Arduino::operator=Arduino(const Arduino rhs)
*   Class assignment operator.
*
* @param[out] Arduino *lhsPtr - Reference to the left hand side of the equation
* @param[in]  const Arduino rhs - Reference to the right hand side of the 
*                                 equation 
******************************************************************************/
Arduino::Arduino Arduino::operator=(const Arduino &rhs)
{
  //----------------------------- Parameters --------------------------------//
  int i;
  Arduino *lhsPtr = NULL; // Initialize to NULL
  //-------------------------------------------------------------------------//
  
  //------------------------------- Routine ---------------------------------//
  lhsPtr = new Arduino();
  for(i = 0; i < 6; i++)
  {
    lhsPtr->m_mac[i] = rhs.m_mac[i];
    if(i < 4)
    {
      lhsPtr->m_ip[i] = rhs.m_ip[i];
    }
    else
    {
      // Do nothing
    }
  }
  return(*lhsPtr);
  //-------------------------------------------------------------------------//
}


/**************************************************************************//**
* DESTRUCTOR: Arduino::~Arduino()
*   Class default destructor.
*
* @param[out] None
* @param[in]  None
******************************************************************************/
Arduino::~Arduino()
{
  //----------------------------- Parameters --------------------------------//
  // None
  //-------------------------------------------------------------------------//
  
  //------------------------------- Routine ---------------------------------//
  // No pointers to delete
  //-------------------------------------------------------------------------//
}

/**************************************************************************//**
* METHOD: Arduino::init_ethernet()
*   Default ether net mode initializer.
*
* @param[out] None
* @param[in]  None
******************************************************************************/
void Arduino::init_ethernet()
{
  //----------------------------- Parameters --------------------------------//
  int i = 0;
  //-------------------------------------------------------------------------//
  
  //------------------------------- Routine ---------------------------------//
  for(i = 0; i < 6; i++)
  {
    this->m_mac[i] =ETHERNET_SHIELD_MAC_ADDRESS[i];
    if(i < 4)
    {
      this->m_ip[i] = ETHERNET_SHIELD_IP_ADDRESS[i];
    }
    else
    {
      // Do nothing
    }
  }
  //-------------------------------------------------------------------------//
}

///----------------------------------------------------------------------------
/// END CLASS METHODS
///----------------------------------------------------------------------------

