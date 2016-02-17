#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        if (nums.size() < 3)
        {
            return out;
        }
        return out;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    int array[] = {-1, 0, 1, 2, -1, -4};
    vector<int> in(array, array + sizeof(array) / sizeof(int));
    vector<vector<int>> out = s.threeSum(in);
    assert(out.size() == 2);
    assert(out[0][0] == -1);
    assert(out[0][1] == 0);
    assert(out[0][2] == 1);
    assert(out[1][0] == -1);
    assert(out[1][1] == -1);
    assert(out[1][2] == 2);

    return 0;
}