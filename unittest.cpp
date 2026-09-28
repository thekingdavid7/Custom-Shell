#include <iostream>
#include <cassert>
#include "param.hpp"
#include "parse.hpp"
#include "process.hpp"

using namespace std;

void testArguments()
{
    string input = "one two three";
    Param param;
    Parse parse;

    vector<string> tokens = parse.tokenize(input, param);

    cout << "Test Arguments:" << endl;

    for (int i = 0; i < tokens.size(); i++)
    {
        cout << "Token " << i << ": " << tokens[i] << endl;
        cout << "Param argument " << i << ": " << param.getArguments()[i] << endl;
        assert(tokens[i] == param.getArguments()[i]);
    }

    cout << endl << "Test Pass!" << endl;
    cout << "____________________________________________________________" << endl;
}

void testInputRedirect()
{
    string input = "<3";
    Param param;
    Parse parse;

    cout << "Test Input Redirect:" << endl;

    vector<string> tokens = parse.tokenize(input, param);
    
    assert(param.getInputRedirect() == string("3"));
    cout << "Input redirect: " << param.getInputRedirect() << endl;

    cout << endl << "Test Pass!" << endl;
    cout << "____________________________________________________________" << endl;
}

void testOutputRedirect()
{
    string input = ">3";
    Param param;
    Parse parse;

    cout << "Test Output Redirect:" << endl;

    vector<string> tokens = parse.tokenize(input, param);
    
    assert(param.getOutputRedirect() == string("3"));
    cout << "Output redirect: " << param.getOutputRedirect() << endl;

    cout << endl << "Test Pass!" << endl;
    cout << "____________________________________________________________" << endl;
}

void testBackground()
{
    string input = "3 &";
    Param param;
    Parse parse;

    cout << "Test Background:" << endl;

    vector<string> tokens = parse.tokenize(input, param);
    
    assert(param.getBackground() == 1);

    cout << endl << "Test Pass!" << endl;
    cout << "____________________________________________________________" << endl;
}

void testFailingInput()
{
    string input = "& 3";
    Param param;
    Parse parse;

    cout << "Test Failing Input:" << endl;

    vector<string> tokens = parse.tokenize(input, param);
    
    assert(param.getArguments()[0] == NULL);
    assert(param.getInputRedirect() == NULL);
    assert(param.getOutputRedirect() == NULL);
    assert(param.getBackground() == 0);


    cout << endl << "Test Pass!" << endl;
    cout << "____________________________________________________________" << endl;
}



int main()
{
    testArguments();
    testInputRedirect();
    testOutputRedirect();
    testBackground();
    testFailingInput();

    return 0;
}