//----------------------------------------------------------------------------
// FILE: arduino.cpp
// AUTHORS: Kevin Buckner
// VERSION
//   - 0.1 Initial Creation
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// INCLUDES
//----------------------------------------------------------------------------
#include "arduino.h"
//----------------------------------------------------------------------------
// CLASS METHODS
//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//!@brief
//!
//! CONSTRUCTOR: Arduino::Arduino()
//!   Class default constructor.
//!
//! @param[in]  None
//----------------------------------------------------------------------------
Arduino::Arduino()
:
m_ethernetType(ETHERNET_CLIENT),
m_clientPtr(NULL)
{

}

//-----------------------------------------------------------------------------
//!@brief
//!
//! @param[in] byte mac[6] (mac address)
//! @param[in] byte ip[4] (ip address [IEEE 802.11 IPv4])
//----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
//!@brief
//!
//!   Class copy constructor.  Effectively copies over all private member 
//! variables from object rhs.
//!
//! @param[in]  const Arduino rhs - Reference to the right hand side of the 
//!                                 equation
//----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
//!@brief
//!
//! ASSIGNMENT OPERATOR: Arduino::operator=Arduino(const Arduino rhs)
//!   Class assignment operator.
//!
//! @return Arduino *lhsPtr - Reference to the left hand side of the equation
//! @param[in]  const Arduino rhs - Reference to the right hand side of the 
//!                                 equation 
//----------------------------------------------------------------------------
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


//-----------------------------------------------------------------------------
//!@brief
//!
//! DESTRUCTOR: Arduino::~Arduino()
//!   Class default destructor.
//!
//! @param[in]  None
//----------------------------------------------------------------------------
Arduino::~Arduino()
{
  //----------------------------- Parameters --------------------------------//
  // None
  //-------------------------------------------------------------------------//
  
  //------------------------------- Routine ---------------------------------//
  //-------------------------------------------------------------------------//
  //client.stop();
}

//-----------------------------------------------------------------------------
//!@brief
//!
//! METHOD: Arduino::init_ethernet()
//!   Default ether net mode initializer.
//!
//! @param[in]  None
//----------------------------------------------------------------------------
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


//---------------------------------------------------------------------------
//!@brief
//!
//! METHOD: Arduino::flipBit(int pin)
//!   Default ether net mode initializer.
//!
//! @param[in] int pin 
//--------------------------------------------------------------------------
void Arduino::flipBit(int pin)
{
  digitalWrite(pin, !digitalRead(pin));
}

//---------------------------------------------------------------------------
//!@brief
//!
//! METHOD: Arduino: getMacAddress()
//!   Getter for this arduino's MAC address. Returns a 
//! pointer to the first element of a byte array in memory (casted as a 
//! void *).
//!
//! @return const byte*                                                       
//---------------------------------------------------------------------------
const byte* Arduino::getMacAddress() 
{
  return(this->m_mac);
}

//--------------------------------------------------------------------------
//!@brief
//!
//! METHOD: Arduino::getIpAddress()
//!   Getter for this arduino's IP [IEEE 802.11 IPv4] address. Returns a 
//! pointer to the first element of a byte array in memory (casted as a 
//! void *).
//!
//! @return const byte*
//--------------------------------------------------------------------------
const byte* Arduino::getIpAddress()
{
  return(this->m_mac);
}


//--------------------------------------------------------------------------  
//!@brief
//!
//! METHOD: Arduino: setMacAddress()
//!   Setter for this arduino's MAC address.  Changes a private member
//! variable within this Arduino object.  Attempts to reconnect.
//!
//! @param[in] byte* addrPtr
//--------------------------------------------------------------------------
void Arduino::setMacAddress(byte* addrPtr)
{
  free(this->m_mac);
  for(int i = 0; i < 6; i++)
    *(this->m_mac+i)= *(addrPtr+i);
  this->reconnect();
}


//---------------------------------------------------------------------------
//!@brief
//!
//! METHOD: Arduino::setIpAddress()
//!  Setter for this arduino's IP [IEEE 802.11 IPv4] address. Changes a private member
//! variable within this Arduino object. Attempts to reconnect.
//! @param[in] byte* addrPtr
//--------------------------------------------------------------------------
void Arduino::setIpAddress(byte* addrPtr)
{
  free(this->m_ip);

  for(int i = 0; i < 4; i++)
    *(this->m_ip+i) = *(addrPtr+i);
  this->reconnect();
}

//---------------------------------------------------------------------------
//!@brief
//!
//! METHOD: Arduino::reconnect()
//!   Reconnects with the Arduino's current MAC address and IPv4 Address.  
//! This Arduino's IP and MAC address are stored as private member variables
//! of this class.
//--------------------------------------------------------------------------
void Arduino::reconnect()
{
  Ethernet.begin(this->m_mac, this->m_ip);
  switch(m_ethernetType)
  {
    case ETHERNET_CLIENT:
      // connect();
      break;
    default:
      break;
  }// End switch
}

//---------------------------------------------------------------------------
//!@brief
//!
//! METHOD: Arduino::connect()
//!   Connects with the Arduino's current MAC address and IPv4 Address. This 
//! Arduino's IP and MAC address are stored as private member variables
//! of this class.
//--------------------------------------------------------------------------
void Arduino::connect()
{
  Ethernet.begin(m_mac, m_ip);
  Serial.begin(9600);
  if(m_clientPtr->connect())
  {
    Serial.println("Connected\n");
    m_clientPtr->println("GET /search?q=arduino HTTP/1.0");
    m_clientPtr->println();
  }
  else
  {
    Serial.println("Connection failed\n");
  }
}

//---------------------------------------------------------------------------
//!@brief
//!
//! METHOD: Arduino::serialConnect()
//!   Connects with the Arduino's current MAC address and IPv4 Address. This 
//! Arduino's IP and MAC address are stored as private member variables
//! of this class.
//--------------------------------------------------------------------------
void Arduino::serialConnect()
{
  Serial.begin(9600);
  Serial.println("USB Connected\n");
}

//---------------------------------------------------------------------------
//!@brief
//!
//! METHOD: Arduino::serialPrint(const char*)
//!   Connects with the Arduino's current MAC address and IPv4 Address. This 
//! Arduino's IP and MAC address are stored as private member variables
//! of this class.
//!@param[in] const char* txt
//--------------------------------------------------------------------------
void Arduino::serialPrint(const char* txt)
{
  Serial.println(txt);
}


//----------------------------------------------------------------------------
// END CLASS METHODS
//----------------------------------------------------------------------------

