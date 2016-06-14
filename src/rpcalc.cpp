#include <cstdlib>
#include <iostream>
#include <locale>
#include <string>
#include <sstream>

#include "Stack.h"

using namespace algo;
using namespace std;

void Prompt();
void ParseLine(const string& line, Stack<string>& stack);
double Calculate(Stack<string>& stack);
bool IsNumber(const string& num);
double Convert(const string& num);

int main(int argc, char* argv[])
{
    Stack<string> stack;
    string line;

    Prompt();
    while (getline(cin, line))
    {
        ParseLine(line, stack);
        cout << "Answer = " << Calculate(stack) << endl;
        stack.Clear();
        Prompt();
    }
    return 0;
}

void Prompt()
{
    cout << "Formula:> ";
}

void ParseLine(const string& line, Stack<string>& stack)
{
    stringstream sstream;
    sstream << line;
    string temp;

    while (sstream >> temp)
    {
        stack.Push(temp);
    }
}

double Calculate(Stack<string>& stack)
{
    double val = 0.0;
    string symbol = stack.Top();
    stack.Pop();

    if (symbol == "+")
    {
        val = Calculate(stack) + Calculate(stack);
    }
    else if (symbol == "-")
    {
        val = Calculate(stack) - Calculate(stack);
    }
    else if (symbol == "*")
    {
        val = Calculate(stack) * Calculate(stack);
    }
    else if (symbol == "/")
    {
        val = Calculate(stack) / Calculate(stack);
    }
    // else if (symbol == "^")
    // {
    //     val = Calculate(stack) ^ Calculate(stack);
    // }
    // else if (symbol == "%")
    // {
    //     val = Calculate(stack) % Calculate(stack);
    // }
    else if (IsNumber(symbol))
    {
        val = Convert(symbol);
    }
    else
    {
        // something is going craaaaaaaaaaaaaaazzzy
    }

    return val;
}

// could probably do this a better way (regex)
bool IsNumber(const string& num)
{
    for (auto x : num)
    {
        if (!isdigit(x) && x != 'e' && x != 'E' && x != '.' && x != '-')
        {
            return false;
        }
    }
    return true;
}

double Convert(const string& num)
{
    return atof(num.c_str());
}