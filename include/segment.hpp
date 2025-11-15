#ifndef SEGMENT
#define SEGMENT
#include "stop.hpp"
// Enum on states for readability
constexpr int PICKUP = 0;
constexpr int DROPOFF = 1;
constexpr int MOVEMENT = 2;

class Segment {
  private:
    // Attributes
    Stop* origin;
    Stop* destination;
    double duration;
    double distance;
    int type;

  public:
    // Constructors and Destructors
    Segment(Stop* origin, Stop* destination, int type);

    // Operations
    double getDistance();
};


#endif
