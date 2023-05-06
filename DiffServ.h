#ifndef DIFFSERV_H
#define DIFFSERV_H
#include <iostream>
#include "ns3/queue.h"
#include <string>
#include <vector>
#include "TrafficClass.h"

using namespace ns3;


template <typename Packet>
class DiffServ : public Queue<Packet>
{
public:
  enum type 
  {
    byteMode = 0, packageMode
  };

  DiffServ (std::vector<TrafficClass*> q);

private:
  type m_mode = packageMode;
  std::vector<TrafficClass*> q_class; 
  int in;
  int out;

public:
  void setMode(type t);
  const std::string getMode();
  bool DoEnqueue(Ptr<ns3::Packet> p);
  Ptr<Packet> DoDequeue();
  Ptr<Packet> DoRemove();
  Ptr<const Packet> DoPeek();
  TrafficClass* Schedule();
  TrafficClass* Classify(Ptr<Packet> p);

};

#endif