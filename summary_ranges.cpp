#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <iterator>


using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> strings;
        string str;
        stringstream ss;
        int i = 0, j = 0;
        int size = nums.size();
        for (; i < size && j < size; i++)
        {
            j = i;
            
        }
        
        return strings;
    }
};

int main(void)
{
    Solution s;
    int num[6] = {0, 1, 2, 4, 5, 7};
    vector<int> nums(&num[0], &num[5]);
    vector<string> vecStr = s.summaryRanges(nums);
    for (vector<string>::iterator it = vecStr.begin(); it != vecStr.end(); it++)
    {
        cout << *it << endl;
    }
    
    return 0;
}



