#include "segment.hpp"
#include <cmath>

double Segment::getDistance() {
  return this->distance;
} 

Segment::Segment(Stop* origin, Stop* destination, int type) :
  origin(origin), destination(destination), type(type) {
    double x = destination->getPosition().x - origin->getPosition().x;
    double y = destination->getPosition().y - origin->getPosition().y;
    this->distance = sqrt(pow(x,2) + pow(y,2));

  // TODo: Calcular distancia
}
