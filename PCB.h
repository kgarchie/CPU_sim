#ifndef pcb_h
#define pcb_h

#include <iostream>

using namespace std;

class PCB {
public:
    PCB();

    explicit PCB(int pid);

    ~PCB();

    void allocateMemory(int memorySize);

    void deallocateMemory();

    void execute(int schedulingAlgorithm) const;

private:
    int processID{};
    string processName;
    int processType{};
    int activityStatus{};
    int cpuBurstTime{};
    int priority{};
    int baseRegister{};
    int limitRegister{};
    int numberOfFiles{};

    char *memoryPointer{};
};
#endif