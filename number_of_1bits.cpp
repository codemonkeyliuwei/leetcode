#include <iostream>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n > 0)
        {
            if (0x1 == (n & 0x1))
            {
                result++;
            }

            n = n >> 1;
        }
        return result;
    }
};

int main(void)
{
    Solution s;
    int n = 0b111101110001;
    cout << s.hammingWeight(n) << endl;

    return 0;
}

