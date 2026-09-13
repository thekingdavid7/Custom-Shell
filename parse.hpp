#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
using namespace std;

class Parse
{
    public:
        Parse();
        ~Parse();
        
        void tokenParse(const string& input);

    private:

        string currentToken;
        vector<Token> tokens;

};

#endif