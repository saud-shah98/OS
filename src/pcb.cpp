
#include <string>
#include <cstring>
#include <iostream>
#include "process.cpp"
using namespace std;
class PCB
{
public:
    string state;
    bool initialized;
    Process current_process;
    bool active = false;
    int pid;
    string level;

    PCB()
    {
    }
    void setProcess(Process process)
    {

        current_process = process;
        setProcessMeta();
    }
    void setProcessMeta()
    {
        active = true;
        initialized = true;
        state = current_process.state;
        pid = current_process.pid;
        level = current_process.level;
        cout << "PCB created for Process with Pid: " << pid << "\tState: " << state << "\tLEVEL: " << level << "\n";
    }

    void printInstruction()
    {
        current_process.printInstruction();
    }

    void printPid()
    {
        cout << "PID: " << pid;
    }
};