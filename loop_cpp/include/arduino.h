//-----------------------------------------------------------------------------
// FILE: arduino.h
// AUTHORS: Kevin Buckner
//   VERSION
//     - 0.1 Initial Creation
///----------------------------------------------------------------------------
/// INCLUDE GUARD
///----------------------------------------------------------------------------
#ifndef _ARDUINO_H_ 
#define _ARDUINO_H_
///----------------------------------------------------------------------------
/// INCLUDES
///----------------------------------------------------------------------------
#include <Ethernet.h>
///----------------------------------------------------------------------------
/// CLASS VARIABLES
///----------------------------------------------------------------------------
const byte ETHERNET_SHIELD_MAC_ADDRESS[] =
                        {0x90, 0xA2, 0xDA, 0x00, 0x23, 0x13}; // MAC Address
const byte ETHERNET_SHIELD_IP_ADDRESS[] = {192, 168, 1, 3}; // IPv4 Address 
//-----------------------------------------------------------------------------
/// CLASS DEFINITION
///----------------------------------------------------------------------------
class Arduino
{
  public:
  /**************************************************************************//**
  * CONSTRUCTOR: Arduino::Arduino()
  *   Class default constructor.
  *
  * @param[out] None
  * @param[in]  None
  ******************************************************************************/
  Arduino();

  /**************************************************************************//**
  * METHOD: Arduino::Arduino(byte mac [6],  byte ip [4])
  *   Class ethernet style constructor.
  * 
  * @param[out] None
  * @param[in] byte mac[6] (MAC address)
  * @param[in] byte ip[4] (IP address [IEEE 802.11 IPv4])
  ******************************************************************************/
  Arduino(byte mac [6],  byte ip [4]);

  /**************************************************************************//**
  * POINTER COPY CONSTRUCTOR: Arduino::Arduino(const Arduino &rhs)
  *   Class copy constructor.
  *
  * @param[out] None
  * @param[in]  const Arduino rhs - Reference to the right hand side of the 
  *                                 equation
  ******************************************************************************/
  Arduino(const Arduino &rhs);

  /**************************************************************************//**
  * ASSIGNMENT OPERATOR: Arduino::operator=Arduino(const Arduino rhs)
  *   Class assignment operator.
  *
  * @param[out] Arduino lhs - Reference to the left hand side of the equation
  * @param[in]  const Arduino rhs - Reference to the right hand side of the 
  *                                 equation 
  ******************************************************************************/
  Arduino operator=(const Arduino &rhs);
 
  /**************************************************************************//**
  * DESTRUCTOR: Arduino::~Arduino()
  *   Class default destructor.
  *
  * @param[out] None
  * @param[in]  None
  ******************************************************************************/
  ~Arduino();

  /**************************************************************************//**
  * METHOD: Arduino::init_ethernet()
  *   Default ether net mode initializer.
  *
  * @param[out] None
  * @param[in]  None
  ******************************************************************************/
  void init_ethernet();

  protected:
  private:
  // Bytes for the MAC address
  byte m_mac [6];
  // Bytes for the IP address (assumed to be IPv4)
  byte m_ip [4];
}; // End class Arduino

#endif // _ARDUINO_H_ 

