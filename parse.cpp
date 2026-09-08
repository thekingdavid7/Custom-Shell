// Simple command-line parser for Custom-Shell
// Provides a function to split a command line into arguments,
// handling quotes and simple escaping.

#include <string>
#include <vector>
#include <cctype>

// Parse a command line into arguments. Handles double and single quotes
// and backslash escaping inside double quotes.
// Example: parseCommand("echo \"hello world\" foo") -> ["echo","hello world","foo"]
static std::vector<std::string> parseCommand(const std::string &line) {
    std::vector<std::string> args;
    std::string cur;
    enum State { S_WS, S_TOKEN, S_SQUOTE, S_DQUOTE } state = S_WS;

    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];
        switch (state) {
        case S_WS:
            if (std::isspace(static_cast<unsigned char>(c))) {
                // stay
            } else if (c == '\'') {
                state = S_SQUOTE;
            } else if (c == '"') {
                state = S_DQUOTE;
            } else {
                state = S_TOKEN;
                cur.push_back(c);
            }
            break;
        case S_TOKEN:
            if (std::isspace(static_cast<unsigned char>(c))) {
                args.push_back(cur);
                cur.clear();
                state = S_WS;
            } else if (c == '\'') {
                state = S_SQUOTE;
            } else if (c == '"') {
                state = S_DQUOTE;
            } else {
                cur.push_back(c);
            }
            break;
        case S_SQUOTE:
            if (c == '\'') {
                state = S_TOKEN;
            } else {
                cur.push_back(c);
            }
            break;
        case S_DQUOTE:
            if (c == '"') {
                state = S_TOKEN;
            } else if (c == '\\' && i + 1 < line.size()) {
                // simple escape inside double quotes
                ++i;
                cur.push_back(line[i]);
            } else {
                cur.push_back(c);
            }
            break;
        }
    }

    if (!cur.empty()) args.push_back(cur);
    return args;
}

// The file is intended to be included or compiled into the project.
// No main() here.
