#include <iostream>
#include "TrafficClass.h"

using namespace ns3;

void TrafficClass::setBytes(uint32_t s)
{
    bytes = s;
}
uint32_t TrafficClass::getBytes()
{
    return bytes;
}
void TrafficClass::setPackets(uint32_t p)
{
    packets = p;
}
uint32_t TrafficClass::gePackets()
{
    return packets;
}
void TrafficClass::setMaxPackets(uint32_t mp)
{
    maxPackets = mp;
}
uint32_t TrafficClass::getMaxPackets()
{
    return maxPackets;
}
void TrafficClass::setMaxBytes(uint32_t s)
{
    maxBytes = s;
}
uint32_t TrafficClass::getMaxBytes()
{
    return maxBytes;
}
void TrafficClass::setWeight(uint32_t w)
{
    weight = w;
}
double_t TrafficClass::getWeight()
{
    return weight;
}
void TrafficClass::setPriority(double_t p)
{
    priority_level = p;
}
uint32_t TrafficClass::getPriority()
{
    return priority_level;
}
void TrafficClass::setDefault(bool d) 
{
    isDefault = d;
}
bool TrafficClass::getDefault()
{
    return isDefault;
}
bool TrafficClass::Enqueue(Ptr<Packet> p)
{
    if (m_queue.size() < maxPackets)
    {
        return false;
    }
    m_queue.push(p);
    return true;
}
Ptr<Packet> TrafficClass::Dequeue()
{
    if (m_queue.empty()) 
    {
        return NULL;
    }
    Ptr<Packet> res = m_queue.front();
    m_queue.pop();
    return res;
}
Ptr<Packet> TrafficClass::peek()
{
    return m_queue.front();
}
bool TrafficClass::match(Ptr<Packet> p)
{
    return true;
}