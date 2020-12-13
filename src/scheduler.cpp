// Round Robin Scheduling Algorithm

#include <iostream>

#include "dispatcher.cpp"

using namespace std;

class Scheduler
{
public:
    Process *job_queue;
    Process *ready_queue;
    int num_processes;

public:
    Scheduler()
    {
    }

    void initialize(Process incoming_processes[], PCB incoming_pcbs[], int total_processes)
    {
        int i;

        job_queue = incoming_processes;
    }

    void roundrobin()
    {
        int i, j, k, quantum;
        int num_processes = 0;
        float total;

        int first_bracket[num_processes][4];
        int second_bracket[num_processes][5];
        cout << "Set value of Q (Time Quantum): ";
        cin >> quantum;

        cout << "\n\nProcess\tArrival\tBurst\n";
        for (i = 0; i < num_processes; i++)
        {
            for (j = 0; j < 3; j++)
            {
                cin >> first_bracket[i][j];
            }
            first_bracket[i][3] = first_bracket[i][2];
        }
        cout << "\n\nTime-Line.....\n\n";

        i = first_bracket[0][1];
        int idle = 0;
        int counter = 0;
        int s = 0;
        k = 0;
        while (counter != num_processes)
        {
            if (k == num_processes)
            {
                k = 0;
            }
            if (first_bracket[k][1] <= i)
            {
                if (first_bracket[k][2] != 0)
                {
                    if (first_bracket[k][2] >= quantum)
                    {
                        printf("%5d\n    |p-%-4d|\n", i, first_bracket[k][0]);
                        first_bracket[k][2] -= quantum;
                        i += quantum;
                    }
                    else
                    {
                        printf("%5d\n    |p-%-4d|\n", i, first_bracket[k][0]);
                        i += first_bracket[k][2];
                        first_bracket[k][2] = 0;
                    }

                    if (first_bracket[k][2] == 0)
                    {
                        second_bracket[s][0] = first_bracket[k][0];
                        second_bracket[s][1] = first_bracket[k][1];
                        second_bracket[s][2] = i;
                        second_bracket[s][3] = first_bracket[k][3];
                        second_bracket[s][4] = ((i - first_bracket[k][1]) - first_bracket[k][3]);
                        total += ((i - first_bracket[k][1]) - first_bracket[k][3]);
                        s++;
                        counter++;
                    }
                    idle = 0;
                }
                k++;
            }
            else
            {
                if (idle == 0)
                {
                    idle = 1;
                    k = 0;
                }
                else if (idle == 1)
                {
                    printf("%5d\n        |Idle  |\n", i);
                    idle = 2;
                    i++;
                }
                else
                    i++;
            }
        }
        printf("%5d\n", i);
        cout << endl
             << endl;

        cout << "Table of Processes with completion record as they were completed";

        for (i = 0; i < s; i++)
        {
            cout << second_bracket[i][0] << "\t" << second_bracket[i][1] << "\t" << second_bracket[i][2] - 1 << "\t" << second_bracket[i][3] << "\t" << second_bracket[i][4] << "\n";
        }
        cout << "\n\nAvg. Wait Time = " << total / num_processes << endl
             << endl;
    }

    void shortestRemainingTime(Process queue[], int n)
    {
        int i;
        int wt[n], tat[n], total_wt = 0, total_tat = 0;

        int rt[n];

        // Get all the burst times
        for (i = 0; i < n; i++)
        {
            rt[i] = queue[i].bt;
        }
        int done = 0;
        int shortest = 0;
        int finish_time;
        int minimum = INT_MAX;
        int t = 0;
        bool check = false;

        while (done != n)
        {
            int j;
            // Getting the minimum time of the processes
            for (j = 0; j < n; j++)
            {
                if ((queue[j].art <= t) && (rt[j] < minimum) && rt[j] > 0)
                {
                    minimum = rt[j];
                    shortest = j;
                    check = true;
                }
            }
            if (check == false)
            {
                t++;
                continue;
            }
            // Subtracting remaining time
            rt[shortest]--;
            minimum = rt[shortest];
            if (minimum == 0)
            {
                minimum = INT_MAX;
            }
            // When process is done
            if (rt[shortest] == 0)
            {
                done++;
                check = false;
                finish_time = t + 1;
                wt[shortest] = finish_time - queue[shortest].bt - queue[shortest].art;
                if (wt[shortest] < 0)
                {
                    wt[shortest] = 0;
                }
            }
            t++;
        }

        for (i = 0; i < n; i++)
        {
            tat[i] = queue[i].bt + wt[i];
        }

        for (i = 0; i < n; i++)
        {
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];
            cout << " " << queue[i].pid << "\t\t" << queue[i].bt << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
        }

        cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
        cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
    }
};