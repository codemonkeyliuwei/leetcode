#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        
        if (n <= 0)
        {
            return s;
        }
        
        if (n > 0 && n <= 26)
        {
            s.push_back((char)('A' + n - 1));
            return s;
        }
        else if (0 == n%26)
        {
            s += convertToTitle((n-26)/26);
            s += convertToTitle(26);
            return s;
        }
        else
        {
            s += convertToTitle(n/26);
            s += convertToTitle(n%26);
            return s;
        }
    }
};


int main(void)
{
    Solution s;
    cout << s.convertToTitle(26*2);
    return 0;
}

