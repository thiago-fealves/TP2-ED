#ifndef DEMAND
#define DEMAND
#include "utils.hpp"
#include "ride.hpp"

// Enum on states for readability
constexpr int PENDING = 0;
constexpr int SINGLE = 1;
constexpr int COMBINED = 2;
constexpr int FINISHED = 3;

class Ride; // Forward Declaration to solve circular import

class Demand {
  private:
    // Attributes
    int id;
    double timestamp;
    Vector2D origin;
    Vector2D destination;
    Ride* ride;
    int state;

    // Statistics
    // TO-DO: Adicionar estatísticas
  public:
  Demand(int id, double timestamp, Vector2D origin, Vector2D destination, Ride* ride, int state);
  ~Demand();  
};


#endif
