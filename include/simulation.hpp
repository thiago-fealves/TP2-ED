#ifndef SIMULATION
#define SIMULATION
#include <iostream>
#include "utils.hpp"
#include "demand.hpp"
#include "ride.hpp"
#include "scheduler.hpp" 

class Simulation {
  public:
    static double calculateEfficiency(Vector<Demand*>& demands); 
    static void printOutput(double currentTimestamp, Ride* currentRide, Vector<Stop*> rideStops);
    static Vector<Demand*> getDemands();
    static Scheduler rideGeneration(Vector<Demand*>& allDemands, Vector<Ride*>& allRides);
    static void processEvents(Scheduler& scheduler);
    static void clearMemory(Vector<Demand*>& allDemands, Vector<Ride*>& allRides, Scheduler& scheduler);
};


#endif
