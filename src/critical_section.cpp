#include <iostream>
#include <stdio.h>

class CriticalSection
{
public:
    bool locked;
    int id;
    int pid;
    int begin_pos;
    int end_pos;

    void initialize(int id, int start, int end = -1)
    {
        locked = false;
        begin_pos = start;
        end_pos = end;
        pid = -1;
    }

    void lock()
    {
        locked = true;
    }

    void unlock()
    {
        locked = false;
    }
};