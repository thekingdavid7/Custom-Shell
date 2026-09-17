#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cctype>
#include <cstring> //strtok
#include "param.hpp"
using namespace std;
class Parse
{
    public:
        Parse();
        
        vector<string> tokenize(const string& input, Param& param);

    private:

        // string currentToken;
        // vector<Token> tokens;

};

#endif