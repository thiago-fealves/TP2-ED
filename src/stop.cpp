#include "stop.hpp"

// Constructor
Stop::Stop(Vector2D position, int type, Demand* demand) : position(position), 
  type(type), demand(demand) {}

// Getters
Vector2D Stop::getPosition(){
  return this->position;
}

int Stop::getType() {
  return this->type;
}

Demand* Stop::getDemand() {
  return this->demand;
}
