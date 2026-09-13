#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <vector>
#include "param.hpp"
using namespace std;
class Parse
{
    public:
        Parse();
        ~Parse();
        
        vector<string> tokenize(const string& input, Param& param);

    private:

        // string currentToken;
        // vector<Token> tokens;

};

#endif