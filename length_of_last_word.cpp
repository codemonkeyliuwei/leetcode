#include <string>

#include <assert.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = (int)s.size()-1;

        while (i >= 0 && isspace(s[i]))
        {
            --i;
        }

        while (i >= 0 && isalpha(s[i]))
        {
            ++len;
            --i;
        }
       
        return len;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    assert(s.lengthOfLastWord("Hello World") == 5);
    assert(s.lengthOfLastWord("Hello World ") == 5);
    assert(s.lengthOfLastWord("Hello") == 5);
    assert(s.lengthOfLastWord(" ") == 0);
    assert(s.lengthOfLastWord("") == 0);
}