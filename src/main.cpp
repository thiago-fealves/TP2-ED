#include "simulation.hpp"

int main() {
    // Variables 
    Vector<Demand*> allDemands(500);
    Vector<Ride*> allRides(500);
    Scheduler scheduler;

    // Execution
    Simulation::getDemands(allDemands);
    Simulation::rideGeneration(allDemands, allRides, scheduler);  
    Simulation::processEvents(scheduler);
    Simulation::clearMemory(allDemands, allRides, scheduler);
    
    return 0;
}
