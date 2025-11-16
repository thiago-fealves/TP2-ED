#include "demand.hpp"
#include "ride.hpp"
#include "scheduler.hpp"
#include "stop.hpp"

class Simulation {
 public:
    static double calculateEfficiency(Vector<Demand*>& demands);
    static void printOutput(double currentTimestamp, Ride* currentRide, Vector<Stop*>& rideStops);
    static void getDemands(Vector<Demand*>& allDemands);
    static void rideGeneration(Vector<Demand*>& allDemands, Vector<Ride*>& allRides, Scheduler& scheduler); 
    static void processEvents(Scheduler& scheduler);
    static void clearMemory(Vector<Demand*>& allDemands, Vector<Ride*>& allRides, Scheduler& scheduler);
};
