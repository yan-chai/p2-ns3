#include <iostream>
#include <string>
#include "DiffServ.h"
#include "TrafficClass.h"
#include <vector>

using namespace ns3;

template <>
ns3::TrafficClass* DiffServ<Packet>::Schedule();
template <>
ns3::TrafficClass* DiffServ<Packet>::Classify(Ptr<Packet> p);

template <>
DiffServ<Packet>::DiffServ (std::vector<TrafficClass*> q)
{
  q_class = q;
  in = 0;
  out = 0;
}

template <>
void DiffServ<Packet>::setMode(DiffServ::type t) 
{
  DiffServ::m_mode = t;
}

template <>
const std::string DiffServ<Packet>::getMode() 
{
  if (m_mode == 0) {
    return "byteMode";
  }
  return "packageMode";
}

template <>
bool DiffServ<Packet>::DoEnqueue(Ptr<Packet> p)
{
  bool res = Classify(p);
  in ++;
  return res;
}

template <>
Ptr<Packet> DiffServ<Packet>::DoDequeue()
{
  if (in <= out)
  {
    return NULL;
  }
  Ptr<Packet> res = Schedule()->Dequeue();
  out ++;
  return res;
}

template <>
Ptr<Packet> DiffServ<Packet>::DoRemove()
{
  if (in <= out)
  {
    return NULL;
  }
  Ptr<Packet> res = Schedule()->Dequeue();
  out ++;
  return res;
}

template <>
Ptr<const Packet> DiffServ<Packet>::DoPeek()
{
  return Schedule()->peek();
}

template <>
ns3::TrafficClass* DiffServ<Packet>::Schedule()
{
  return q_class[out%q_class.size()];
}

template <>
ns3::TrafficClass* DiffServ<Packet>::Classify(Ptr<Packet> p)
{
  return q_class[in%q_class.size()];
}




int main(int argc, char const *argv[])
{
  /* code */
  char str[] = "Hello C++";
  std::cout << "Value of str is : " << str << std::endl;
  return 0;
}