#include "event.hpp"

Event::Event(double timestamp, int type, Ride* ride, Stop* stop) : 
  timestamp(timestamp), type(type), ride(ride), stop(stop) {}

 
bool Event::operator>(const Event& other) const {
  return this->timestamp > other.timestamp;
}

double Event::getTimestamp() const { return timestamp; }
int Event::getType() const { return type; }


