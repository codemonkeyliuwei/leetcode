#include <string>
#include <stack>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (isOpen(s[i]))
            {
                myStack.push(s[i]);
                continue;
            }

            if (myStack.empty())
            {
                return false;
            }

            if ((s[i] == ')' && myStack.top() == '(')
                || (s[i] == ']' && myStack.top() == '[')
                || (s[i] == '}' && myStack.top() == '{'))
            {
                myStack.pop();
            }
            else
            {
                return false;
            }
        }

        return myStack.empty();
    }

    bool isOpen(char c)
    {
        return ('{' == c || '[' == c || '(' == c);
    }
};

int main(void)
{
    Solution s;
    string strCase1("()");
    assert(s.isValid(strCase1));

    string strCase2("()[]{}");
    assert(s.isValid(strCase2));

    string strCase3("{[()]}");
    assert(s.isValid(strCase3));

    string strCase4("{");
    assert(!s.isValid(strCase4));

    string strCase5("([)]");
    assert(!s.isValid(strCase5));

    string strCase6("]");
    assert(!s.isValid(strCase6));

    return 0;
}