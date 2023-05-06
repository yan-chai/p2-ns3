#ifndef TRAFFICCLASS_H
#define TRAFFICCLASS_H
#include <cstdint>
#include <math.h>
#include <queue>
#include "ns3/packet.h"
#include <vector>

namespace ns3 {
class TrafficClass 
{
private:
    uint32_t bytes;
    uint32_t packets;
    uint32_t maxPackets;
    uint32_t maxBytes;
    double_t weight;
    uint32_t priority_level;
    bool isDefault;
    std::queue<Ptr<Packet>> m_queue;
    std::vector<Packet*> filters;

public:
    TrafficClass();
    void setBytes(uint32_t s);
    uint32_t getBytes();
    void setPackets(uint32_t p);
    uint32_t gePackets();
    void setMaxPackets(uint32_t mp);
    uint32_t getMaxPackets();
    void setMaxBytes(uint32_t s);
    uint32_t getMaxBytes();
    void setWeight(uint32_t w);
    double_t getWeight();
    void setPriority(double_t p);
    uint32_t getPriority();
    void setDefault(bool d);
    bool getDefault();
    bool Enqueue(Ptr<Packet> p);
    Ptr<Packet> Dequeue();
    Ptr<Packet> peek();
    bool match(Ptr<Packet> p);
};
}
#endif