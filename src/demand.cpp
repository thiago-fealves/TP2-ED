#include "demand.hpp"

// Constructor
Demand::Demand(int id, double timestamp, Vector2D origin,
  Vector2D destination, Ride* ride, int state) : id(id),
  timestamp(timestamp), origin(origin), 
  destination(destination), ride(ride), state(state) {};

// Getters and setters
int Demand::getID() const {
  return this->id;
}

double Demand::getTimestamp() const {
  return this->timestamp;
}

Vector2D Demand::getOrigin() const {
  return this->origin;
}

Vector2D Demand::getDestination() const {
  return this->destination;
}

Ride* Demand::getRide() const {
  return this->ride;
}

int Demand::getState() const {
  return this->state;
}

void Demand::setRide(Ride* ride) {
    this->ride = ride;
}

void Demand::setState(int state) {
    this->state = state;
}
