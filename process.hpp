#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "param.hpp"
using namespace std;

// Responsible for turning a parsed command into a child process.
// This class handles redirection and waits for foreground commands to finish.
class Process
{
    public:
        Process();
        ~Process();

        // Forks a child, applies any redirects from Param, and executes the command.
        void executeCommand(Param& param); //pass by reference NOT copy

    private:

};

#endif