#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <vector>
using namespace std;

class Parse
{
    public:
        Parse();
        ~Parse();
        
        vector<string> tokenize(const string& input);

    private:

        // string currentToken;
        // vector<Token> tokens;

};

#endif