#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <cctype>
using namespace std;

// Function to check a simple condition like "A==1", "x<y", etc.
bool checkCondition(string cond, map<string, int>& vars) {
    string left, op, right;
    stringstream ss(cond);
    ss >> left >> op >> right;

    auto getValue = [&](string token) {
        if (isalpha(token[0])) return vars[token];
        return stoi(token);
    };

    int a = getValue(left);
    int b = getValue(right);

    if (op == "==") return a == b;
    if (op == "!=") return a != b;
    if (op == "<")  return a < b;
    if (op == ">")  return a > b;
    return false;
}

// Recursive function to execute Futuris code
void runCode(vector<string>& lines, int& i, map<string, int>& vars) {
    while (i < lines.size()) {
        string line = lines[i];

        if (line == "end") { ++i; return; } // consume 'end' before returning

        stringstream ss(line);
        string cmd;
        ss >> cmd;

        // PRINT
        if (cmd == "print") {
            string val; ss >> val;
            if (!val.empty() && isalpha(val[0])) cout << vars[val] << "\n";
            else cout << val << "\n";
            ++i; continue;
        }

        // IF
        if (cmd == "if") {
            string cond = line.substr(3);
            bool ok = checkCondition(cond, vars);
            ++i; // move to next line

            if (ok) {
                if (i < lines.size() && lines[i] == "Yes") ++i;
                runCode(lines, i, vars); // execute Yes block

                // after runCode returns, i now past the 'end' of Yes block
                // skip No block if exists
                if (i < lines.size() && lines[i] == "No") {
                    ++i;
                    int depth = 1;
                    while (depth > 0 && i < lines.size()) {
                        if (lines[i].rfind("if", 0) == 0 || lines[i].rfind("for", 0) == 0) depth++;
                        else if (lines[i] == "end") depth--;
                        ++i;
                    }
                }
            } else {
                // skip Yes block
                if (i < lines.size() && lines[i] == "Yes") {
                    ++i;
                    int depth = 1;
                    while (depth > 0 && i < lines.size()) {
                        if (lines[i].rfind("if", 0) == 0 || lines[i].rfind("for", 0) == 0) depth++;
                        else if (lines[i] == "end") depth--;
                        ++i;
                    }
                }
                // execute No block
                if (i < lines.size() && lines[i] == "No") {
                    ++i;
                    runCode(lines, i, vars);
                }
            }
            continue;
        }

        // FOR
        if (cmd == "for") {
            string var, startStr, endStr;
            ss >> var >> startStr >> endStr;

            auto getValue = [&](string token) {
                if (!token.empty() && isalpha(token[0])) return vars[token];
                return stoi(token);
            };

            int start = getValue(startStr);
            int end = getValue(endStr);

            // capture inner block
            int startLine = i + 1;
            vector<string> block;
            int depth = 1;
            ++i;

            while (depth > 0 && i < lines.size()) {
                if (lines[i].rfind("for", 0) == 0) depth++;
                else if (lines[i] == "end") depth--;
                if (depth > 0) block.push_back(lines[i]);
                ++i;
            }

            // run loop
            for (int val = start; val <= end; ++val) {
                vars[var] = val;
                int j = 0;
                runCode(block, j, vars);
            }
            continue;
        }

        ++i; // move to next line
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string input;
    while (getline(cin, input)) {
        if (!input.empty()) lines.push_back(input);
    }

    if (lines.size() < 2) {
        cerr << "Insufficient input (need code + var names + var values)\n";
        return 0;
    }

    int n = lines.size();
    string varLine = lines[n - 2];
    string valLine = lines[n - 1];

    // extract code
    vector<string> code(lines.begin(), lines.end() - 2);

    // map variables
    map<string, int> vars;
    stringstream vs(varLine), vals(valLine);
    string name; int val;
    vector<string> names;

    while (vs >> name) names.push_back(name);
    for (int k = 0; k < names.size(); ++k) {
        vals >> val;
        vars[names[k]] = val;
    }

    int idx = 0;
    runCode(code, idx, vars);

    return 0;
}
