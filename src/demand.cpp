#include "demand.hpp"

Demand::Demand(int id, double timestamp, Vector2D origin,
  Vector2D destination, Ride* ride, int state) : id(id),
  timestamp(timestamp), origin(origin), 
  destination(destination), ride(ride), state(state) {};

