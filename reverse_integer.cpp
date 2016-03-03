#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long r = 0;
        
        while (x != 0)
        {
            r = r * 10 + x % 10;
            x /= 10;

            if (r > numeric_limits<int>::max() || r < numeric_limits<int>::min())
            {
                return 0;
            }
        }
        
        return (int)r;
    }
};

int main(void)
{
    Solution s;
    cout << s.reverse(1000000003) << endl;
    //cout << numeric_limits<int>::max() << endl;
    //cout << numeric_limits<int>::min() << endl;
    return 0;
}

