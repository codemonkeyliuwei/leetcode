#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <assert.h>

using std::string;
using std::stack;

class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        char sign = '+';
        for (size_t i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i])) 
            {
                num = num * 10 + s[i] - '0';
            }

            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1)
            {
                switch (sign)
                {
                case '+':
                    break;
                case '-':
                    num = -num;
                    break;
                case '*':
                    num = numStack.top() * num;
                    numStack.pop();
                    break;
                case '/':
                    num = numStack.top() / num;
                    numStack.pop();
                    break;
                default:
                    break;
                }
                
                numStack.push(num);
                num  = 0;
                sign = s[i];
            }           
        }

        while (!numStack.empty())
        {
            num += numStack.top();
            numStack.pop();
        }

        return (int)num;
    }

private:
    stack<long long> numStack;
};

int main(int argc, char **argv)
{
    Solution s;
    string in1("3");
    string in2(" 32/300 - 100");
    string in3(" 0 - 3+5 / 2 ");

    int out1 = s.calculate(in1);
    assert(out1 == 3);

    int out2 = s.calculate(in2);
    assert(out2 == -100);

    int out3 = s.calculate(in3);
    assert(out3 == -1);
}