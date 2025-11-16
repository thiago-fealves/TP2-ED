#include "ride.hpp"
#include "demand.hpp"
#include "stop.hpp"
#include "segment.hpp"

// Constructor and Destructor
Ride::Ride(Vector<Demand*>& demands) : demands(demands),duration(0.0),
  distance(0.0),efficiency(0.0) {

  int numDemands = demands.getSize();
  if (numDemands == 0) return;

  // Pickup
  for (int i = 0; i < numDemands; i++) {
      Demand* demand = demands.getAt(i);
      this->stops.append(new Stop(demand->getOrigin(), STOP_PICKUP, demand));
  }

  // Drop Off
  for (int i = 0; i < numDemands; i++) {
    Demand* demand = demands.getAt(i);
    this->stops.append(new Stop(demand->getDestination(), STOP_DROPOFF, demand));
  }

 // Creating segments
  int numStops = this->stops.getSize();
  for (int i = 0; i < numStops - 1; i++) {
    Stop* stopOrigem = this->stops.getAt(i);
    Stop* stopDestino = this->stops.getAt(i + 1);
    int segmentType;
    
    // Segment between two Pick Up Stops is a PICKUP type
    if (i < numDemands - 1) {
      segmentType = PICKUP; 
    }

    // Segment between one Pick Up Stop and one Drop off Stop is a MOVEMENT type
    else if (i == numDemands - 1) {
      segmentType = MOVEMENT; 
    }

    // Segment between two dropoffs is a DROPOFF type
    else {
      segmentType = DROPOFF;
    }

    // Initialization and statististics
    Segment* newSegment = new Segment(stopOrigem, stopDestino, segmentType);
    this->segments.append(newSegment);
    this->distance += newSegment->getDistance();
    this->duration += newSegment->getDuration();
  }
}

Ride::~Ride(){
  for (int i = 0; i < segments.getSize(); i++) {
    delete segments.getAt(i);
  }

  for (int i = 0; i < stops.getSize(); i++) {
    delete stops.getAt(i);
  }
}

// Getters
Vector<Stop*>& Ride::getStops() {
    return this->stops;
}

Vector<Segment*>& Ride::getSegments() {
    return this->segments;
}

Vector<Demand*>& Ride::getDemands() {
    return this->demands;
}

double Ride::getDistance() const {
  return this->distance;
} 

