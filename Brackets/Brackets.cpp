#include "Brackets.h"

int Brackets::solution(string& S)
{
    unordered_map<char, char> brackets{ {'(',')'}, {'[',']'}, {'{','}'} };
    stack<char> brackets_checker;

    for (auto bracket : S) {
        if (brackets.contains(bracket)) {
            // open bracket
            brackets_checker.push(bracket);
        }
        else {
            //close bracket
            if (brackets_checker.empty() || (brackets[brackets_checker.top()] != bracket)) {
                return 0;
            }
            else {
                brackets_checker.pop();
            }
        }
    }

    if (brackets_checker.empty())
        return 1;
    else
        return 0;
}
