#include <iostream>
using namespace std;
#include "pcb.cpp";

class Dispatcher
{
public:
    PCB current_pcb;
    Dispatcher()
    {
    }

    void setPCB(PCB pcb)
    {
        pcb = current_pcb;
    }

    void switch_context(PCB current_pcb)
    { // Switching from new to ready
        while (current_pcb.active)
        {
            if (current_pcb.active && (current_pcb.state == "NEW"))
            {
                // Check if we have resources
                current_pcb.state = "READY";
                cout << current_pcb.state;
            }
            // Start Process
            current_pcb.state = "READY";
            cout << current_pcb.state;

            // Finished process
            if (current_pcb.active && (current_pcb.state != "NEW" || "WAITING") && (current_pcb.state == "READY"))
            {
                // Process Complete
                current_pcb.active == false;
                current_pcb.state = "DONE";
                cout << current_pcb.state;
            }
            else
            {
                current_pcb.state = "WAITING";
                cout << current_pcb.state;
            }
        }
    }
};
