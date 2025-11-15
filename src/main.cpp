#include "ride.hpp"
#include "simulation.hpp"
int main() {
  Vector<Demand*> allDemands = Simulation::getDemands();
  Vector<Ride*> allRides(500);
  Scheduler scheduler = Simulation::rideGeneration(allDemands, allRides);  
  Simulation::processEvents(scheduler); 
  Simulation::clearMemory(allDemands, allRides, scheduler);
}

