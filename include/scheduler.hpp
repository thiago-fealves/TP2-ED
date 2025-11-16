#ifndef SCHEDULER
#define SCHEDULER
#include "datastructures/minheap.hpp"
#include "event.hpp"

class Scheduler {
  private:
    MinHeap<Event> simulation;
  public:
    // Operations
    void initialize();
    void appendEvent(Event newEvent);
    Event popNextEvent();
    void end();
    bool isEmpty() const;
};

#endif
