#include "ride.hpp"
#include "simulation.hpp"
int main() {
  Vector<Demand*> allDemands = Simulation::getDemands();
  Vector<Ride*> allRides;
  Scheduler scheduler = Simulation::RideGeneration(allDemands, allRides);  
  Simulation::processEvents(scheduler); 
  Simulation::clearMemory(allDemands, allRides, scheduler);
}

