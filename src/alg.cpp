// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char ch) {
    switch (ch) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    default:
        return 0;
    }
}

std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack1;
    std::string result = "";
    for (int i = 0; i < inf.size(); i++) {
        if (isdigit(inf[i]) != 0) {
            result += inf[i];
        } else if (getPrior(inf[i]) == 2 || getPrior(inf[i]) == 3) {
            result += " ";
            if (stack1.isEmpty() || getPrior(stack1.get()) == 0 ||
                getPrior(inf[i]) > getPrior(stack1.get())) {
                stack1.push(inf[i]);
            } else if (getPrior(inf[i]) <= getPrior(stack1.get())) {
                while (getPrior(inf[i]) <= getPrior(stack1.get())) {
                    result += stack1.pop();
                    result += " ";
                }
                stack1.push(inf[i]);
            }
        } else if (getPrior(inf[i]) == 0) {
            stack1.push(inf[i]);
        } else if (getPrior(inf[i]) == 1) {
            while (getPrior(stack1.get()) != 0) {
                result += " ";
                result += stack1.pop();
            }
            stack1.pop();
        }
    }
    while (!stack1.isEmpty()) {
        result += " ";
        result += stack1.pop();
    }
    return std::string(result);
}

int eval(std::string pref) {
    TStack<int, 100> stack2;
    for (int i = 0; i < pref.size(); i++) {
        if (isdigit(pref[i]) != 0) {
            int number = pref[i] - '0';
            stack2.push(number);
        } else if (getPrior(pref[i]) == 2 || getPrior(pref[i]) == 3) {
            int operand2 = stack2.pop();
            int operand1 = stack2.pop();
            switch (pref[i]) {
            case '+':
                stack2.push(operand1 + operand2);
                break;
            case '-':
                stack2.push(operand1 - operand2);
                break;
            case '*':
                stack2.push(operand1 * operand2);
                break;
            case '/':
                stack2.push(operand1 / operand2);
                break;
            default:
                throw std::string("Unknown operation!");
            }
        }
    }
    return stack2.pop();
}
