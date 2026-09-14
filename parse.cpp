#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <cstring> //strtok
#include "param.hpp"
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

vector<string> Parse::tokenize(const string& input, Param& param)
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

    //this is not perfect and I have not tested this part, but try to test it when you work on Param
    for (size_t i = 0; i < tokens.size(); i++)
    {
        string token = tokens[i];

        if (token[0] == '<')
        {
            if (token.length() > 1)
            {   
                //if token length is > 1, the filename is attached to the '<' character, so we need to extract it
                //substring returns the string after '<' and c_str() returns a pointer to the beginning of the string
                //const_cast<char*> is used to remove the const qualifier from the pointer returned by c_str()
                param.setInputRedirect(const_cast<char*>(token.substr(1).c_str()));
            }
            else if (i + 1 < tokens.size())
            {
                //if token length is 1, the filename is the next token in the list, so we need to get it from there
                param.setInputRedirect(const_cast<char*>(tokens[i + 1].c_str()));
                i++; // Skip the next token since it's the filename
            }
        }
        else if (token[0] == '>')
        {
            if (token.length() > 1)
            {
                param.setOutputRedirect(const_cast<char*>(token.substr(1).c_str()));
            }
            else if (i + 1 < tokens.size())
            {
                param.setOutputRedirect(const_cast<char*>(tokens[i + 1].c_str()));
                i++; // Skip the next token since it's the filename
            }
        }
        else if (token[token.length() - 1] == '&')
        {
            param.setBackground(1);
        }
        else
        {
            param.addArgument(const_cast<char*>(tokens[i].c_str()));
        }
    }

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