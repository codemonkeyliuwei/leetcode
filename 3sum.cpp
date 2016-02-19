#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>

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

        for (unsigned int i = 0; i < nums.size() - 2; ++i)
        {
            for (unsigned int j = i+1; j < nums.size(); ++j)
            {
                unordered_map<int, int>::iterator it = HashMap.find(-nums[i]-nums[j]);
                if (it != HashMap.end())
                {
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[it->second]);
                    triplets.push_back(triplet);
                }
                else
                {
                    HashMap.insert(make_pair<int,int>(nums[j], j));
                }
            }
            HashMap.clear();
        }

        return triplets;
    }
private:
    unordered_map<int, int> HashMap;
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