#include <iostream>
#include <vector>
#include <string>
#include "param.hpp"
#include "parse.hpp"
#include "process.hpp"
using namespace std;

int main(void)
{
    string input = "";
    Parse parse;

    cout << "$$$ ";
    getline(cin, input);

    while (input != "exit")
    {
        Param param;
        vector<string> tokens = parse.tokenize(input, param);

        // for (size_t i = 0; i < tokens.size(); i++)
        // {
        //     cout << tokens[i] << endl; //print each token to the console
        // }

        cout << "$$$ ";
        getline(cin, input);
    }

    return 0;
}
