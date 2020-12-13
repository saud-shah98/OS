
#include <iostream>
#include <fstream>

#include "scheduler.cpp"

int main()
{
	// Selecting Program & Amount of Processes Variables
	int selectedProgram;
	string program_dir;
	int executions;

	// Load First Template
	cout << "\n\t\tOperating System Starting...........\n";
	cout << "\nPrograms that are available:\t Program:A\t Program:B\t Program:C\t Program:D\t Program:E\t\n";
	// Ask User For Template, & How Many Processess
	cout << "\n\t\t Enter '1' for Program:A\n ";
	cout << "\n\t\t Enter '2' for Program:B\n ";
	cout << "\n\t\t Enter '3' for Program:C\n ";
	cout << "\n\t\t Enter '4' for Program:D\n ";
	cout << "\n\t\t Enter '5' for Program:E\n ";
	cin >> selectedProgram;

	switch (selectedProgram)
	{
	case 1:
		program_dir = "program_a.txt";
		break;
	case 2:
		program_dir = "program_b.txt";
		break;
	case 3:
		program_dir = "program_c.txt";
		break;

	case 4:
		program_dir = "program_d.txt";
		break;
	case 5:
		program_dir = "program_e.txt";
		break;
	}

	fstream program_template;
	program_template.open(program_dir, ios::in);
	// Save Instructions
	string program_template_instructions[33];
	if (program_template.is_open())
	{
		for (int i = 0; i < 5; ++i)
		{
			program_template >> program_template_instructions[i];
			cout << "\t" << program_template_instructions[i] << "\n";
		}
	}

	cout << "ENTER AMOUNT OF PROCESSES TO RUN (INTEGER): ";
	cin >> executions;
	Process new_processes[executions];
	PCB new_pcbs[executions];

	// // Creation of Process Object To Execute
	for (int i = 0; i < executions / 2; i++)
	{
		Process process;
		PCB pcb;
		CriticalSection exec;
		// process.setInstruction(program_template_instructions);
		// process.setInstruction(program_template);

		process.setCriticalSection(exec);
		int pid = fork();
		process.setPID(pid);
		pcb.setProcess(process);
		new_processes[i] = process;
		new_pcbs[i] = pcb;
	}

	Scheduler CPU;
	CPU.initialize(new_processes, new_pcbs, executions);
	return 0;
}
