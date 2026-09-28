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

// Parses user input into a command line structure.
// The tokenizer separates whitespace and records redirection/background metadata
// in the Param object while preserving the raw token list as a simple vector.
class Parse
{
    public:
        Parse();

        // Break the input into tokens and populate Param with argument, redirect,
        // and background information for execution.
        vector<string> tokenize(const string& input, Param& param);

    private:

        // string currentToken;
        // vector<Token> tokens;

};

#endif