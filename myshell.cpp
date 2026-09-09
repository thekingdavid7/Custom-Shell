#include <iostream>
using namespace std;

#include "parse.hpp"
#include "process.hpp"

int main()
{
    cout << "Custom Shell v1.0" << endl;
    cout << "Type 'help' for commands." << endl;
    Parse parse;
    Process process;
    parse.function1();
    process.function1();
}
