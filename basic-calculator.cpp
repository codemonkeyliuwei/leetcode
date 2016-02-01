#include <iostream>
#include<assert.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        
    }
};


int main(void)
{
    Solution s;
    assert(s.calculate("1 + 1") == 2);
    assert(s.calculate(" 2-1 + 2 ") == 3);
    assert(s.calculate("(1+(4+5+2)-3)+(6+8)") == 23);
    return 0;
}
