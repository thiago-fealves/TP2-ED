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

  public:
    Event();
    Event(double timestamp, int type, Ride* ride, Stop* stop);
    bool operator<(const Event& other) const;
    double getTimestamp() const;
    int getType() const;
    Ride* getRide() const;
    Stop* getStop() const;
};

#endif
