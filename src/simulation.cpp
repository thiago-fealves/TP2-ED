#include "simulation.hpp"
#include "ride.hpp"

double Simulation::calculateEfficiency(Vector<Demand*>& demands) {
    int numDemands = demands.getSize();

    // Individual ride
    if (numDemands <= 1) {
        return 1.0;
    }
    
    // Get stops
    Vector<Vector2D> stops;
    for (int i = 0; i < numDemands; i++) {
        stops.append(demands.getAt(i)->getOrigin());
    }

    for (int i = 0; i < numDemands; i++) {
        stops.append(demands.getAt(i)->getDestination());
    }

    double totalDistance = 0.0;
    double movementDistance = 0.0;
    
    // Calculates distances
    for (int i = 0; i < stops.getSize() - 1; i++) {
        Vector2D stop1 = stops.getAt(i);
        Vector2D stop2 = stops.getAt(i + 1);
        double segmentDistance = Vector2D::distance(stop1, stop2);

        totalDistance += segmentDistance;

        if (i == numDemands - 1) {
            movementDistance = segmentDistance;
        }
    }
    
    // Returns efficiency
    if (totalDistance == 0.0) {
        return 0.0;
    }

    return movementDistance / totalDistance;
}

void Simulation::printOutput(double currentTimestamp, Ride* currentRide, Vector<Stop*> rideStops) {
  // Conclusion time
  std::cout << currentTimestamp << " ";

  // Total Distance
  std::cout << currentRide->getDistance() << " ";

  // Number of rides
  std::cout << rideStops.getSize() << " ";

  // Coordinates Sequence
  for (int i = 0; i < rideStops.getSize(); i++) {
    Vector2D position = rideStops.getAt(i)->getPosition();
    std::cout << position.x << " " << position.y;
    if (i < rideStops.getSize() - 1) {
      std::cout << " "; 
    }
  }
  std::cout << std::endl;
}


Vector<Demand*> Simulation::getDemands() {
  // Parameters and initialization
  SimulationParameters::getSimulationParameters();
  Vector<Demand*> allDemands(500);
  
  // Reading demands
  int numDemands;
  std::cin >> numDemands;

  for (int i = 0; i < numDemands; i++) {
    int id;
    double time;
    double origin_x, origin_y, destination_x, destination_y; 
    std::cin >> id >> time >> origin_x >> origin_y >> destination_x >> destination_y;

    // Creates new pending demand and saves it
    Demand* demand = new Demand(id, time,
        Vector2D(origin_x, origin_y), Vector2D(destination_x, destination_y),
        nullptr, PENDING);
        
    allDemands.append(demand);
  }

  return allDemands;
}

Scheduler Simulation::rideGeneration(Vector<Demand*>& allDemands, Vector<Ride*>& allRides) {
  Scheduler scheduler;
  // Processes Demands one by one
  for (int i = 0; i < allDemands.getSize(); i++) {
    Demand* currentDemand = allDemands.getAt(i);
    if (currentDemand->getState() != PENDING) {
        continue;
    }
    
    // Initialize with individual ride
    Vector<Demand*> rideDemands;
    rideDemands.append(currentDemand);

    // Searches compatible rides
    for (int j = i + 1; j < allDemands.getSize(); j++) {
        Demand* candidateDemand = allDemands.getAt(j);

        // Is it pending?
        if (candidateDemand->getState() != PENDING) continue;

        // Is there any seats available at the vehicle?
        if (rideDemands.getSize() >= SimulationParameters::capacity) break;
        
        // Is it within the timestamp threshold?
        if (candidateDemand->getTimestamp() - currentDemand->getTimestamp() >= SimulationParameters::interval) {
          continue;
        }
        
        // Origin and Destination distance criterion
        bool distanceOk = true;
        for (int k = 0; k < rideDemands.getSize(); k++) {
          Demand* demandInRide = rideDemands.getAt(k);

          // Is the origin close to all other demands in the ride?
          if (Vector2D::distance(candidateDemand->getOrigin(), 
            demandInRide->getOrigin()) > SimulationParameters::maxDistanceOrigin) {
              distanceOk = false;
              break;
          }

          // Is the destination close to all other demands in the ride?
          if (Vector2D::distance(candidateDemand->getDestination(),
            demandInRide->getDestination()) > SimulationParameters::maxDistanceDestination) {
              distanceOk = false;
              break;
          }
        }
        
        // Is the distance criterion ok?
        if (!distanceOk) {
          break;
        }

        // Temporarily add candidate to check efficiency
        rideDemands.append(candidateDemand);
        double efficiency = calculateEfficiency(rideDemands);
        
        // Is the ride with the candidate within the efficiency threshold?
        if (efficiency <= SimulationParameters::efficiency) {
            // Removes candidate
            rideDemands.removeLast();
            break;
        }

        // If the demand passes all the criterion, the candidate is already added
      }

    // Creates the new ride
    Ride* newRide = new Ride(rideDemands);
    allRides.append(newRide);
    
    // Updates pointers on all demands
    int numGroups = rideDemands.getSize();
    int updatedState = (numGroups > 1) ? COMBINED : SINGLE;

    for (int k = 0; k < numGroups; k++) {
        Demand* demand = rideDemands.getAt(k);
        demand->setRide(newRide);
        demand->setState(updatedState);
    }

    // Creates and returns event
    Stop* firstStop = newRide->getStops().getAt(0);
    double initialTimestamp = currentDemand->getTimestamp();
    Event initialEvent(initialTimestamp, EVENT_PICKUP, newRide, firstStop);
    scheduler.appendEvent(initialEvent);
  }
  return scheduler;
}

void Simulation::processEvents(Scheduler& scheduler) {
  while (!scheduler.isEmpty()) {
    // Processes one event at a time to generate the next ones
    Event currentEvent = scheduler.popNextEvent();
    
    // Event data
    double currentTimestamp = currentEvent.getTimestamp();
    Ride* currentRide = currentEvent.getRide();
    Stop* currentStop = currentEvent.getStop();
    
    // Get next stop
    int nextStopIndex = -1;
    Vector<Stop*>& rideStops = currentRide->getStops();
    for (int i = 0; i < rideStops.getSize() - 1; i++) {
      if (rideStops.getAt(i) == currentStop) {
        nextStopIndex = i + 1; // Encontramos, a próxima é i+1
        break;
      }
    }
    
    /* Schedule next event */

    // If the is still stops in current rides
    if (nextStopIndex != -1) {
      Stop* nextStop = rideStops.getAt(nextStopIndex);  

      // Get the segment between current stop and next stop
      Segment* segment = currentRide->getSegments().getAt(nextStopIndex - 1);
            
      // Next event timestamp
      double segmentDuration = segment->getDuration();
      double nextEventTimestamp = currentTimestamp + segmentDuration;

      // Next event time
      int nextEventType;
      if (nextStop->getType() == STOP_PICKUP) {
        nextEventType = EVENT_PICKUP;
      }
      else {
        nextEventType = EVENT_DROPOFF;
      }

      // Cria e agenda o próximo evento
      Event nextEvent(nextEventTimestamp, nextEventType, currentRide, nextStop);
      scheduler.appendEvent(nextEvent);
    } 
    
    // If this is the last stop of the current ride
    else { 
      // Finish all rides
      Vector<Demand*>& rideDemands = currentRide->getDemands();
      for (int i = 0; i < rideDemands.getSize(); i++) {
        rideDemands.getAt(i)->setState(FINISHED);
      }
      
      printOutput(currentTimestamp, currentRide, rideStops);

    }
  }
}



void Simulation::clearMemory(Vector<Demand*>& allDemands, Vector<Ride*>& allRides, Scheduler& scheduler) {
  for (int i = 0; i < allRides.getSize(); i++) {
        delete allRides.getAt(i);
    }

    for (int i = 0; i < allDemands.getSize(); i++) {
        delete allDemands.getAt(i);
    }
    
    scheduler.end();
}
