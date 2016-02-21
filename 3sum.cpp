#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using namespace std::tr1;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        if (nums.size() < 3)
        {
            return triplets;
        }

        sort(nums.begin(), nums.end(), less<int>());

        for (unsigned int i = 0; i < nums.size() - 2; ++i)
        {
            if (nums[i] > 0)
            {
                break;
            }
            vector<int>::size_type j = i+1;
            vector<int>::size_type k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] +nums[k];
                if (sum > 0)
                {
                    --k;
                }
                else if (sum < 0)
                {
                    ++j;
                }
                else
                {
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[k]);
                    triplets.push_back(triplet);
                    
                    ++j;
                    --k;
                    while (j < nums.size() - 1 && nums[j] == nums[j-1])
                    {
                        ++j;
                    }
                    while (k > 0 && nums[k] == nums[k+1])
                    {
                        --k;
                    }
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i+1])
            {
                ++i;
            }
        }

        return triplets;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    int array[] = {-1, 0, 1, 2, -1};
    int case1_out1[] = {-1, 0, 1};
    int case1_out2[] = {-1, -1, 2};
    vector<int> in(array, array + sizeof(array) / sizeof(int));
    vector<int> vec_out1(case1_out1, case1_out1 + sizeof(case1_out1) / sizeof(int));
    vector<int> vec_out2(case1_out2, case1_out2 + sizeof(case1_out2) / sizeof(int));
    vector<vector<int>> out = s.threeSum(in);
    assert(out.size() == 2);
    assert(out[0] == vec_out2);
    assert(out[1] == vec_out1);
  
    int array2[] = {0, 0, 0};
    vector<int> in2(array2, array2 + sizeof(array2) / sizeof(int));
    out.clear();
    out = s.threeSum(in2);
    assert(out.size() == 1);
    assert(out[0][0] == 0);
    assert(out[0][1] == 0);
    assert(out[0][2] == 0);

    return 0;
}