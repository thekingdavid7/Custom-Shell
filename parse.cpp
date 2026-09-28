#include "param.hpp"
#include "parse.hpp"
using namespace std;

Parse::Parse()
{

}

// This tokenizer is intentionally lightweight: it splits on spaces and then
// interprets special shell symbols such as <, >, and & in the resulting tokens.
// A more advanced implementation would use a full shell grammar, but this works
// for the simple command format used by the project.
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

    // Copy the input into a C-style buffer so strtok can be used safely.
    char *cstr = new char[input.length() + 1];
    strcpy(cstr, input.c_str());

    // Split the command line on spaces; this preserves each token in order.
    char *p = strtok(cstr, " ");
    while (p != 0)
    {
        tokens.push_back(string(p));
        p = strtok(NULL, " ");
    }

    delete[] cstr;

    // Inspect each token and update the Param object with command metadata.
    for (size_t i = 0; i < tokens.size(); i++)
    {
        string token = tokens[i];

        if (token[0] == '<')
        {
            if (token.length() > 1)
            {
                // Input redirection may be written as "<file" in a single token.
                param.setInputRedirect(const_cast<char*>(token.substr(1).c_str()));
            }
            else if (i + 1 < tokens.size())
            {
                // Or the file path may be the following token: "< file".
                param.setInputRedirect(const_cast<char*>(tokens[i + 1].c_str()));
                i++; // Skip the filename token after consuming it.
            }
        }
        else if (token[0] == '>')
        {
            if (token.length() > 1)
            {
                // Output redirection may be written as ">file".
                param.setOutputRedirect(const_cast<char*>(token.substr(1).c_str()));
            }
            else if (i + 1 < tokens.size())
            {
                // Or the filename may be the next token: "> file".
                param.setOutputRedirect(const_cast<char*>(tokens[i + 1].c_str()));
                i++; // Skip the filename token after consuming it.
            }
        }
        else if (token == "&")
        {
            if (i == tokens.size() - 1)
            {
                // Background execution is only valid as the final token.
                param.setBackground(1);
            }
            else
            {
                cerr << "Error: '&' must be at the end of the command." << endl;
                return vector<string>();
            }
        }
        else
        {
            // Regular command arguments are stored in the Param argument vector.
            param.addArgument(const_cast<char*>(tokens[i].c_str()));
        }
    }

    return tokens;
}