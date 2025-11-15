#include "scheduler.hpp"
#include "event.hpp"

void Scheduler::appendEvent(Event event) {
  simulation.insert(event);
}

void Scheduler::initialize() {
  // Not really needed, constructor dealt with the job
}

Event Scheduler::popNextEvent() {
  return simulation.extractMin();
}

bool Scheduler::isEmpty() const{
  return simulation.empty();
}

void Scheduler::end(){
  // TODO: Statistics here
}
