#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <queue>

#include "processor.h"
#include "PCB.h"

using namespace std;

Processor::Processor() = default;

Processor::Processor(int schedAlg, double load) {
    schedulingAlgorithm = schedAlg;
    processorLoad = load;
}

Processor::~Processor() = default;

void Processor::setReadyQueue(vector<PCB *> processList) {
    int processCount = (int) (processList.size() * processorLoad);

    for (int i = 0; i < processCount; i++) {
        readyQueue.push(processList[i]);
    }
}

void Processor::executeProcesses() {
    cout << "Processor " << processorID << " is using scheduling algorithm " << schedulingAlgorithm << " with "
         << processorLoad * 100 << "% load." << endl;

    while (!readyQueue.empty()) {
        PCB *process = readyQueue.front();
        readyQueue.pop();

        process->execute(schedulingAlgorithm);

        usleep(200);
    }
}
