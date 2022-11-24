#include <iostream>
#include <stdlib.h>

#include "PCB.h"

using namespace std;

PCB::PCB()
= default;

PCB::PCB(int pid)
{
    processID = pid;
    processType = 0;
    activityStatus = 0;
    cpuBurstTime = 0;
    baseRegister = 0;
    limitRegister = 0;
    numberOfFiles = 0;

    memoryPointer = nullptr;
}

PCB::~PCB()
= default;

void PCB::allocateMemory(int memorySize)
{
    memoryPointer = new char[memorySize];
}

void PCB::deallocateMemory()
{
    delete [] memoryPointer;
}

void PCB::execute(int schedulingAlgorithm) const
{
    if(schedulingAlgorithm == 1)
    {
        cout << "Process " << processID << " is running on FCFS." << endl;
    }
    else if(schedulingAlgorithm == 2)
    {
        cout << "Process " << processID << " is running on Round Robin." << endl;
    }
    else if(schedulingAlgorithm == 3)
    {
        cout << "Process " << processID << " is running on Shortest Job First." << endl;
    }
    else if(schedulingAlgorithm == 4)
    {
        cout << "Process " << processID << " is running on Priority." << endl;
    }
    else
    {
        cout << "Invalid scheduling algorithm." << endl;
        exit(1);
    }
}
