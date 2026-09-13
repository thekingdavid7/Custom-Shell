#include <iostream>
#include <vector>
#include <string>
#include "parse.hpp"
#include "process.hpp"
using namespace std;

int main(void)
{
    string input = "";
    Parse parse;
    Process process;

    while (input != "exit")
    {
        cout << "$$$ ";
        getline(cin, input);

        vector<string> tokens = parse.tokenize(input);
        
        for (size_t i = 0; i < tokens.size(); i++)
        {
            cout << tokens[i] << endl; //print each token to the console
        }
    }

    return 0;
}
