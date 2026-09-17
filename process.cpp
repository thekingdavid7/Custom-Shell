#include "process.hpp"
using namespace std;

Process::Process()
{

}

Process::~Process()
{
    
}

void Process::executeCommand(Param& param)
{
    pid_t pid = fork(); //create a child
    //parent = pid > 0
    //child = pid == 0

    if (pid < 0) //handle fork breaking
    {
        cerr << "Fork failed" << endl;
        exit(1);
    }
    else if (pid == 0) //child process
    {
        char** args = param.getArguments();
        execvp(args[0], args); //execute command
        
        cerr << "Error executing command: " << args[0] << endl; //if execvp returns, there was an error
        exit(1);
    }
    else //parent process
    {
        if (!param.getBackground()) //if background is false, wait for child to finish
        //background determines whether the parent should execute a new command or wait for the child to finish executing the current command
        {
            waitpid(pid, NULL, 0); //wait for child to finish
        }
    }
}