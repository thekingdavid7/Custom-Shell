#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>
using namespace std;

class Process
{
    public:
        Process();
        ~Process();
        
        void function1();
        
    private:
        string function2(const string& input);
};

#endif