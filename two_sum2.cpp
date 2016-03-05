#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> out;

        sort(numbers.begin(), numbers.end(), less<int>());

        vector<int>::size_type i = 0;
        vector<int>::size_type j = numbers.size() - 1;

        while (i < j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum > target)
            {
                --j;
            }
            else if (sum < target)
            {
                ++i;
            }
            else
            {
                out.push_back(i);
                out.push_back(j);
                break;
            }
        }
        return out;
    }
};


int main(void)
{
    Solution s;

    int cnum[] = {2, 11, 7, 11, 15};
    int target = 18;
    vector<int> num(cnum, cnum + sizeof(cnum) / sizeof(int));
    vector<int> result = s.twoSum(num, target);

    cout << result[0] << '\t' << result[1] << endl;
    return 0;
}

