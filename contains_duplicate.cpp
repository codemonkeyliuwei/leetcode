#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hmap;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            if (hmap.find(nums[i]) == hmap.end())
            {
                //hmap.insert(pair<int, int>(nums[i], i));
                ++hmap[nums[i]];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main(void)
{
    Solution s;

    int cnum[] = {2, 11, 7, 11, 15};
    vector<int> nums(cnum, cnum + sizeof(cnum) / sizeof(int));
    cout << s.containsDuplicate(nums) << endl;
}
