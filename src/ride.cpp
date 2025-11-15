#include "ride.hpp"

int 

Ride::Ride(Vector<Segment*> segments, Vector<Demand*> demands) : segments(segments), demands(demands) {
  for (Segment* segment : segments){
    distance += segment.distance;
  }
}
