#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "scheduler.h"
#include "processor.h"
#include "PCB.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "Please provide an input file." << endl;
        exit(1);
    }

    string fileName = argv[1];

    Scheduler scheduler = Scheduler();
    scheduler.readFile(fileName);

    for(int i = 2; i < argc; i+=3)
    {
        int schedAlg = atoi(argv[i]);
        double load = atof(argv[i+1]);
        int processorID = atoi(argv[i+2]);

        scheduler.addProcessor(schedAlg, load);
    }

    scheduler.scheduleProcesses();

    return 0;
}