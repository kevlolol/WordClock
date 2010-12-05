//----------------------------------------------------------------------------
// FILE: arduino.h
// AUTHORS: Kevin Buckner
//   VERSION
//     - 0.1 Initial Creation
//----------------------------------------------------------------------------
// INCLUDE GUARD
//----------------------------------------------------------------------------
#ifndef _ARDUINO_H_ 
#define _ARDUINO_H_
//----------------------------------------------------------------------------
// INCLUDES
//----------------------------------------------------------------------------
#include <Ethernet.h>
//----------------------------------------------------------------------------
// CLASS VARIABLES
//----------------------------------------------------------------------------
const byte ETHERNET_SHIELD_MAC_ADDRESS[] =
                        {0x90, 0xA2, 0xDA, 0x00, 0x23, 0x13}; // MAC Address
const byte ETHERNET_SHIELD_IP_ADDRESS[] = {192, 168, 1, 3}; // IPv4 Address 
//----------------------------------------------------------------------------
// CLASS DEFINITION
//----------------------------------------------------------------------------
class Arduino
{
  public:
  //---------------------------------------------------------------------------
  //!@brief
  //! CONSTRUCTOR: Arduino::Arduino()
  //!   Class default constructor.
  //!
  //! @return None
  //! @param[in]  None
  //--------------------------------------------------------------------------
  Arduino();

  //---------------------------------------------------------------------------
  //!@brief
  //! CONSTRUCTOR: Arduino::Arduino(byte mac [6],  byte ip [4])
  //!   Class ethernet style constructor.
  //! 
  //! @return None
  //! @param[in] byte mac[6] (MAC address)
  //! @param[in] byte ip[4] (IP address [IEEE 802.11 IPv4])
  //--------------------------------------------------------------------------
  Arduino(byte mac [6],  byte ip [4]);

  //---------------------------------------------------------------------------
  //!@brief
  //! COPY CONSTRUCTOR: Arduino::Arduino(const Arduino &rhs)
  //!   Class copy constructor.
  //!
  //! @return None
  //! @param[in]  const Arduino rhs - Reference to the right hand side of the 
  //!                                 equation
  //--------------------------------------------------------------------------
  Arduino(const Arduino &rhs);

  //---------------------------------------------------------------------------
  //!@brief
  //! ASSIGNMENT OPERATOR: Arduino::operator=Arduino(const Arduino rhs)
  //!   Class assignment operator.
  //!
  //! @return Arduino lhs - Reference to the left hand side of the equation
  //! @param[in]  const Arduino rhs - Reference to the right hand side of the 
  //!                                 equation 
  //--------------------------------------------------------------------------
  Arduino operator=(const Arduino &rhs);
 
  //---------------------------------------------------------------------------
  //!@brief
  //! DESTRUCTOR: Arduino::~Arduino()
  //!   Class default destructor.
  //!
  //! @return None
  //! @param[in]  None
  //--------------------------------------------------------------------------
  ~Arduino();

  //---------------------------------------------------------------------------
  //!@brief
  //! METHOD: Arduino::init_ethernet()
  //!   Default ether net mode initializer.
  //!
  //! @return None
  //! @param[in]  None
  //--------------------------------------------------------------------------
  void init_ethernet();

  protected:
  private:
  /// Bytes for the MAC address
  byte m_mac [6];
  /// Bytes for the IP address (assumed to be IPv4)
  byte m_ip [4];
}; // End class Arduino

#endif // _ARDUINO_H_ 

