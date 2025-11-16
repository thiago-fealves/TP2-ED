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
    Vector<Stop*> stops;

    // Statistics
    double duration;
    double distance;
    double efficiency;

  public:
    // Constructors and Destructors
    Ride(Vector<Demand*>& demands);
    ~Ride();

    // Getters
    Vector<Stop*>& getStops(); 
    Vector<Segment*>& getSegments();
    Vector<Demand*>& getDemands();
    double getDistance() const;
};

#endif
