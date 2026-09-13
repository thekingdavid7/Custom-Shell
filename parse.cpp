#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <cstring> //strtok
#include "parse.hpp"
using namespace std;

Parse::Parse()
{

}

Parse::~Parse()
{
    
}

//This was me trying to figure out how to parse the input string into tokens
//this is written in c++, idk if he wants it in c++ or c for this part but it is much easier
//in c++, or so ive been told. Also it gives an error becuase token isnt a class so i cant return a vector<token>
enum class TokenType
{
    WORD,
    PIPE,
    REDIRECT_IN,
    REDIRECT_OUT,
    APPENDOUT,
    BACKGROUND,
    ERROR
};

// struct Token
// {
//     TokenType type;
//     string value;
// };

vector<string> Parse::tokenize(const string& input)
{
    vector<string> tokens;
    char *cstr = new char[input.length() + 1]; //pointer starting at the beginning of the input string
        //make memory to give space for input
    strcpy(cstr, input.c_str()); //copy input to cstr

    char * p = strtok(cstr, " "); //tokenize the input string by spaces
    while (p != 0)
    {
        tokens.push_back(string(p)); //add the word to list
        p = strtok(NULL, " "); //continue scanning cstr
    }

    delete[] cstr; //free the memory allocated for cstr

    // vector<string> tokens;
    // string currentToken;
    // bool inQuotes = false;

    // for (char c : input) {
    //     if (c == '"') {
    //         inQuotes = !inQuotes;
    //         continue;
    //     }

    //     if (isspace(c) && !inQuotes) {
    //         if (!currentToken.empty()) {
    //             tokens.push_back({TokenType::WORD, currentToken});
    //             currentToken.clear();
    //         }
    //     } else if (!inQuotes && (c == '|' || c == '<' || c == '>' || c == '&')) {
    //         if (!currentToken.empty()) {
    //             tokens.push_back({TokenType::WORD, currentToken});
    //             currentToken.clear();
    //         }
    //         TokenType type;
    //         switch (c) {
    //             case '|': type = TokenType::PIPE; break;
    //             case '<': type = TokenType::REDIRECT_IN; break;
    //             case '>': type = TokenType::REDIRECT_OUT; break;
    //             case '&': type = TokenType::BACKGROUND; break;
    //             default: type = TokenType::ERROR; break;
    //         }
    //         tokens.push_back({type, string(1, c)});
    //     } else {
    //         currentToken += c;
    //     }
    // }
    // if (!currentToken.empty()) {
    //     tokens.push_back({TokenType::WORD, currentToken});
    // }

    return tokens; //return the mutable copy of the input string
}