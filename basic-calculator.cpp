#include <iostream>
#include <assert.h>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<long long>  numStack;
        stack<char> opStack;
        long long left  = 0;
        long long right = 0;
        long long result = 0;

        for (string::size_type i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                opStack.push(s[i]);
                right = 0;
                continue;
            }
            if (s[i] == '+' || s[i] == '-')
            {
                if (!opStack.empty() && (opStack.top() == '+' || opStack.top() == '-'))
                {
                    right = op(numStack.top(), right, opStack.top());
                    numStack.pop();
                    opStack.pop();
                }
                numStack.push(right);
                opStack.push(s[i]);
                right = 0;
                continue;
            }
            if (s[i] == ' ')
            {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                right = right * 10 + s[i] - '0';
                continue;
            }
            if (s[i] == ')')
            {
                char _op = opStack.top();
                if (_op == '+' || _op == '-')
                {
                    opStack.pop();
                    right  = op(numStack.top(), right, _op);
                    numStack.pop();
                }
                opStack.pop();  // pop '('
            }
        }

        if (!opStack.empty())
        {
            return (int)op(numStack.top(), right, opStack.top());
        }
        
        return (int)right;
    }

    long long op(long long left, long long right, char op)
    {
        return (op == '+') ? left + right : left - right;
    }
};


int main(void)
{
    Solution s;
    assert(s.calculate("0") == 0);
    assert(s.calculate("9") == 9);
    assert(s.calculate("0+9") == 9);
    assert(s.calculate("0-9") == -9);
    assert(s.calculate("-9+1+1") == -7);
    assert(s.calculate("1 - 1 + 2") == 2);
    assert(s.calculate(" 2-1 + 2 ") == 3);
    assert(s.calculate("(2-1) + 2 ") == 3);
    assert(s.calculate(" 2- ( 1 + 2 )") == -1);
    assert(s.calculate("((1 + 1))") == 2);
    assert(s.calculate("(1 + 1 + 1)") == 3);
    assert(s.calculate("(1+(4+5+2)-3)+(6+8)") == 23);
    assert(s.calculate("((1+(4+5+2)-3)+(6+8))") == 23);
    return 0;
}
