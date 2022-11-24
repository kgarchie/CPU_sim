// scheduler.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>

#include "scheduler.h"
#include "processor.h"
#include "PCB.h"

using namespace std;

Scheduler::Scheduler() = default;

Scheduler::~Scheduler() = default;

void Scheduler::readFile(const string& fileName) {
    ifstream inFile;
    inFile.open(fileName.c_str(), ifstream::binary);

    if (!inFile) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    inFile.read((char *) &processCount, sizeof(processCount));
    inFile.read((char *) &memorySize, sizeof(memorySize));
    inFile.read((char *) &openFiles, sizeof(openFiles));

    cout << "There are " << processCount << " processes." << endl;
    cout << "There is " << memorySize << "KB of memory." << endl;
    cout << "There are " << openFiles << " open files." << endl;

    for (int i = 0; i < processCount; i++) {
        int pid;
        inFile.read((char *) &pid, sizeof(pid));

        PCB *process = new PCB(pid);
        processList.push_back(process);

        cout << "Process " << i << ": " << pid << endl;
    }

    inFile.close();
}

void Scheduler::scheduleProcesses() {
    for (auto & i : processList) {
        i->allocateMemory(memorySize);
    }

    for (auto & i : processorList) {
        i->setReadyQueue(processList);
    }

    for (auto & i : processorList) {
        i->executeProcesses();
    }

    for (auto & i : processList) {
        i->deallocateMemory();
    }
}

void Scheduler::addProcessor(int schedAlg, double load) {
    auto *processor = new Processor(schedAlg, load);
    processorList.push_back(processor);
}