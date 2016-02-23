#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int sum  = 0;
        int base = 1;
        
        for (int i = s.size()-1; i >= 0; i--)
        {
            sum += (s[i] + 1 - 'A') * base;
            base *= 26;
        }

        return sum;
    }
};

int main(void)
{
    Solution s;
    string str("BA");
    cout << s.titleToNumber(str) << endl;
    return 0;
}