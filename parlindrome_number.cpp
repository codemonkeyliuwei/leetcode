#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }

        int len = 1;
        while (x / len >= 10)
            len *= 10;

        while (x > 0) {
            int left  = x / len;
            int right = x % 10;

            if (left != right) {
                return false;
            }
            else {
                x = (x % len) / 10;
                len /= 100;
            }
        }

        return true;
    }
};

int main(void)
{
    Solution s;

    cout << "Expect true:" << endl;
    cout << s.isPalindrome(0) << endl;
    cout << s.isPalindrome(1) << endl;
    cout << s.isPalindrome(11) << endl;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(1221) << endl;
    cout << s.isPalindrome(12321) << endl;

    cout << "Expect false:" << endl;
    cout << s.isPalindrome(12) << endl;
    cout << s.isPalindrome(123421) << endl;

    cout << s.isPalindrome(-1) << endl;
    cout << s.isPalindrome(-11) << endl;
    cout << s.isPalindrome(-121) << endl;
    cout << s.isPalindrome(-1221) << endl;
    cout << s.isPalindrome(-12321) << endl;
    return 0;
}

