//How to handle this situation for name lookup? 

#include <iostream>
#include <string>

class USBDevice {
private:
    long m_id{};

public:
    USBDevice(long id) : m_id{ id } {}
    long getID() const { return m_id; }
};

class NetworkDevice {
private:
    long m_id{};

public:
    NetworkDevice(long id) : m_id{ id } {}
    long getID() const { return m_id; }
};

// WirelessAdapter inherits from BOTH USBDevice and NetworkDevice
class WirelessAdapter : public USBDevice, public NetworkDevice {
public:
    WirelessAdapter(long usbId, long netId)
        : USBDevice{ usbId }, NetworkDevice{ netId } {}
};

// We go in the order in which classes are inherited from 
//class WirelessAdapter : public USBDevice, public NetworkDevice {
//First USBDevice, then networkdevice, then wireless adapter is built 
//that colon list order don't matter 


//Diamond problem

//         [ Device ]          <-- Common Ancestor
//         /        \
//        /          \
//   [ Printer ]   [ Scanner ]  <-- Intermediate Classes
//        \          /
//         \        /
//        [ Copier ]           <-- Inherits from both

//Dupicate instanties of Device are created, wasted memory, ambigious 
//name lookup is done in parallel / phases, derived -> derived 2 -> derived 3. diamond problem isn't solved name lookup, if its ambigous, its gone 

//using composition is a solution 
//explicitly mention where to get the function 
//reserve multiple inheritance for pure interfaces,