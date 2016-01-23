#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
        {
            return false;
        }
        return (n > 0 && 0 == (n & (n-1)) ) ? true : false;
    }
};

int main(void)
{
    Solution s;

    cout << s.isPowerOfTwo(1) << endl;
    cout << s.isPowerOfTwo(8) << endl;
    cout << s.isPowerOfTwo(0X40000000) << endl;
    cout << s.isPowerOfTwo(7) << endl;
    cout << s.isPowerOfTwo(0) << endl;
    cout << s.isPowerOfTwo(0XF0000000) << endl;

    return 0;
}

