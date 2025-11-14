#ifndef EVENT
#define EVENT
#include "demand.hpp"
#include "ride.hpp"
#include "stop.hpp"

// Enum for readability
constexpr int EVENT_PICKUP = 0;
constexpr int EVENT_DROPOFF = 1;

class Event{
  private:
    double timestamp;
    int type;
    Ride* ride;
    Stop* stop;
};

#endif
