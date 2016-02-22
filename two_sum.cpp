#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::tr1;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        unordered_map<int, int>::iterator it = hmap.begin();
        for (vector<int>::size_type i = 0; i < numbers.size(); i++)
        {
            it = hmap.find(target - numbers[i]);
            if (it != hmap.end())
            {
                result.push_back(it->second);
                result.push_back(i+1);
                return result;
            }
            
            hmap.insert(pair<int, int>(numbers[i], i));
        }
    }

private:
    unordered_map<int, int> hmap;
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

