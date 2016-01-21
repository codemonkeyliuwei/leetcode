#include <iostream>
#include <string>
#include <limits>

using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        long long r = 0;
        size_t i = 0;
        bool  negative = false;

        // Ìø¹ý¿Õ¸ñ
        while (' ' == str[i]) {
            i++;
        }

        // ÅÐ¶Ï·ûºÅÎ»
        if (str[i] == '-') {
            negative = true;
            i++;
        }
        else if (str[i] == '+') {
            negative = false;
            i++;
        }

        // Ìø¹ý0
        while ('0' == str[i]) {
            i++;
        }
        
        for (; i < str.size(); i++){
            if (str[i] >= '0' && str[i] <= '9'){
                r = r * 10 + str[i] - '0';
                if (!negative && r > numeric_limits<int>::max())
                    return numeric_limits<int>::max();
                if (negative && -r < numeric_limits<int>::min())
                    return numeric_limits<int>::min();
            }
            else {
                break;
            }
        }

        return negative ? -r : r;
    }
};

int main(void)
{
    Solution s;
    cout << s.myAtoi("123") << endl;
    cout << s.myAtoi("  123") << endl;
    cout << s.myAtoi("  +123") << endl;
    cout << s.myAtoi("-123") << endl;
    cout << s.myAtoi("  -123") << endl;
    cout << s.myAtoi("-  123") << endl;
    cout << s.myAtoi("123-") << endl;
    cout << s.myAtoi("00123") << endl;
    cout << s.myAtoi("-00123") << endl;
    cout << s.myAtoi("12.3") << endl;
    cout << s.myAtoi(".123") << endl;
    cout << s.myAtoi("a123") << endl;
    cout << s.myAtoi("1a23") << endl;
    cout << s.myAtoi(" -001a23") << endl;
    cout << s.myAtoi("123a") << endl;
    cout << s.myAtoi(" 2147483647") << endl;
    cout << s.myAtoi(" 2147483648") << endl;
    cout << s.myAtoi("-2147483648") << endl;
    cout << s.myAtoi("-2147483649") << endl;
    cout << s.myAtoi("9223372036854775809") << endl;
    cout << s.myAtoi("-9223372036854775808") << endl;
    

    cout << "int max: " << numeric_limits<int>::max()
         << ", min: "  << numeric_limits<int>::min() << endl;
    cout << "long long max: " << numeric_limits<long long>::max()
         << ", min: "  << numeric_limits<long long>::min() << endl;
    return 0;
}

