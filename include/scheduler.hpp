#ifndef SCHEDULER
#define SCHEDULER

#include "datastructures/minheap.hpp"
#include "event.hpp"
class Scheduler {
  private:
    MinHeap<Event> simulation;
  public:
    Scheduler();
    void initialize();
    void appendEvent();
    void popNextEvent();
    void end();

};

#endif
