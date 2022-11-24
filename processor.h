#ifndef processor_h
#define processor_h

#include <iostream>
#include <queue>

#include "PCB.h"

using namespace std;

class Processor
{
public:
    Processor();
    Processor(int schedAlg, double load);
    ~Processor();

    void setReadyQueue(vector<PCB*> processList);
    void executeProcesses();

private:
    queue<PCB*> readyQueue;

    int schedulingAlgorithm{};
    double processorLoad{};
    int processorID{};
};

#endif