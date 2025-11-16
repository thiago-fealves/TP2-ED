#ifndef STOP
#define STOP
#include "utils.hpp"

class Demand; // Forward Declaration to solve circular import

// Enum for readability
constexpr int STOP_PICKUP = 0;
constexpr int STOP_DROPOFF = 1;

class Stop {
  private:
    Vector2D position;
    int type;
    Demand* demand;

  public:
    // Constructor 
    Stop(Vector2D position, int type, Demand* demand);

    // Getters
    Vector2D getPosition();
    int getType();
    Demand* getDemand();
}; 

#endif
