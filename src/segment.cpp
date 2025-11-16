#include "segment.hpp"
#include "utils.hpp"

// Constructors
Segment::Segment(Stop* origin, Stop* destination, int type) :
  origin(origin), destination(destination), type(type) {
    this->distance = Vector2D::distance(destination->getPosition(), origin->getPosition());
  if (SimulationParameters::velocity > 0) {
    this->duration = this->distance / SimulationParameters::velocity;
  }
  else {
    this->duration = 0.0;
  }
}

// Getters
double Segment::getDistance() const {
  return this->distance;
} 

double Segment::getDuration() const {
  return this->duration;
}
