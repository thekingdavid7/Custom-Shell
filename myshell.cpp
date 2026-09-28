#include <iostream>
#include <vector>
#include <string>
#include "param.hpp"
#include "parse.hpp"
#include "process.hpp"
using namespace std;

// Simple interactive shell loop:
// 1. Read one command line from the user.
// 2. Parse it into arguments and redirects.
// 3. Execute the command in a child process.
// 4. Continue until the user enters "exit".
int main(int argc, char *argv[])
{
    string input = "";
    Parse parse;
    Process process;
    bool debug = argc > 1 && string(argv[1]) == "-Debug";

    cout << "$$$ ";
    getline(cin, input);

    while (input != "exit")
    {
        Param param;
        vector<string> tokens = parse.tokenize(input, param);

        if (debug)
            param.printParams();

        // Execute the parsed command, including redirection and background handling.
        process.executeCommand(param);

        cout << "$$$ ";
        getline(cin, input);
    }

    return 0;
}
