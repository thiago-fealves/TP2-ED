#include "segment.hpp"
#include "utils.hpp"
#include <cmath>

Segment::Segment(Stop* origin, Stop* destination, int type) :
  origin(origin), destination(destination), type(type) {
    double x = destination->getPosition().x - origin->getPosition().x;
    double y = destination->getPosition().y - origin->getPosition().y;
    this->distance = sqrt(pow(x,2) + pow(y,2));
  if (SimulationParameters::velocity > 0) {
    this->duration = this->distance / SimulationParameters::velocity;
  }
  else {
    this->duration = 0.0;
  }
}

double Segment::getDistance() const {
  return this->distance;
} 

double Segment::getDuration() const {
  return this->duration;
}
