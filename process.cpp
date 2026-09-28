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
    // Fork creates a child process to run the command independently from the shell.
    pid_t pid = fork();
    int status;

    if (pid < 0)
    {
        cerr << "Fork failed" << endl;
        exit(1);
    }
    else if (pid == 0)
    {
        char** args = param.getArguments();

        // Redirect stdout to a file when the user requests output redirection.
        if (param.getOutputRedirect() != NULL)
        {
            if (freopen(param.getOutputRedirect(), "w", stdout) == NULL)
            {
                perror("Failed to redirect output");
                exit(1);
            }
        }

        // Redirect stdin from a file when the user requests input redirection.
        if (param.getInputRedirect() != NULL)
        {
            if (freopen(param.getInputRedirect(), "r", stdin) == NULL)
            {
                perror("Failed to redirect input");
                exit(1);
            }
        }

        // Replace the child process with the requested command.
        execvp(args[0], args);

        cerr << "Error executing command: " << args[0] << endl;
        exit(1);
    }
    else
    {
        // Foreground jobs wait for the child to finish; background jobs return
        // immediately so the shell can continue accepting new input.
        if (!param.getBackground())
        {
            waitpid(pid, &status, 0);
        }
    }
}