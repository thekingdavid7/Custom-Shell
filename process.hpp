#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "param.hpp"
using namespace std;

class Process
{
    public:
        Process();
        ~Process();
        
        void executeCommand(Param& param); //pass by reference NOT copy
        
    private:
    
};

#endif