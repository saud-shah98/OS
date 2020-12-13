
#include <string>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include "critical_section.cpp"
using namespace std;

class Process
{
public:
	// Process Instance Variables;
	string instruction[10];

	string state;
	string level;
	pid_t pid;
	int bt;	 // Burst Time
	int art; // Arrival Time
	CriticalSection critical;
	Process()
	{
		state = "New";
	}

	void setInstruction(string new_instruction[32])
	{

		for (int i = 0; i < 32; i++)
		{
			instruction[i] = new_instruction[i];
		}
	}

	void printInstruction()
	{
		cout << "\t\tThe instruction is: " << instruction << "\n";
	}
	void printPID()
	{
		cout << "\t\t The PID for this Process is: ";
	}
	void setPID(int pid)
	{
		pid = pid;
		if (pid == 0)
		{
			level = "PARENT";
		}
		else
		{
			level = "CHILD";
		}
	}

	void setCriticalSection(CriticalSection exec)
	{
		critical = exec;
	}
};
