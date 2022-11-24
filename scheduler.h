#ifndef scheduler_h
#define scheduler_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>

#include "processor.h"
#include "PCB.h"

using namespace std;

class Scheduler
{
public:
    Scheduler();
    ~Scheduler();

    void readFile(const string& fileName);
    void scheduleProcesses();
    void addProcessor(int schedAlg, double load);

private:
    vector<PCB*> processList;
    vector<Processor*> processorList;

    int processCount{};
    int memorySize{};
    int openFiles{};
};

#endif
