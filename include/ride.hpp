#ifndef RIDE
#define RIDE
#include "datastructures/vector.hpp"
#include "segment.hpp"

class Demand; // Forward Declaration to solve circular imports

class Ride {
  private:
    // Attributes
    Vector<Segment*> segments; 
    Vector<Demand*> demands;

    // Statistics
    double duration;
    double distance;
    double efficiency;

  public:
    Ride();
    ~Ride();
};

#endif
