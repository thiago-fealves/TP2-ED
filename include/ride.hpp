#ifndef RIDE
#define RIDE
#include "datastructures/vector.hpp"
#include "segment.hpp"
#include "utils.hpp"

class Demand; // Forward Declaration to solve circular imports

class Ride {
  private:
    // Attributes
    Vector<Segment*> segments; 
    Vector<Demand*> demands;
    Vector<Stop*> stops;

    // Statistics
    double duration;
    double distance;
    double efficiency;

  public:
    Ride(Vector<Demand*> demands);
    ~Ride();
};

#endif
