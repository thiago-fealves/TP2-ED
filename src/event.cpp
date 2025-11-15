#include "event.hpp"

Event::Event(double timestamp, int type, Ride* ride, Stop* stop) : 
  timestamp(timestamp), type(type), ride(ride), stop(stop) {}

 
bool Event::operator>(const Event& other) const {
  return this->timestamp > other.timestamp;
}

double Event::getTimestamp() const { 
  return this->timestamp;
}

int Event::getType() const {
  return this->type;
}

Ride* Event::getRide() {
  return this->ride;
}

Stop* Event::getStop() {
  return this->stop;
}




