#include <iostream>
#include <unordered_map>

#include <algorithm>
#include <iterator>

using namespace std;

namespace utility
{

template<class T>
void print(T container)
{
    using ValueType = T::value_type;
    std::copy(container.begin(), container.end(), std::ostream_iterator<ValueType>(std::cout, " "));
    std::cout << std::endl;
}

} // namespace utility

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i=0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) == m.end() )
            {
                m[nums[i]] = i;
            }
            else
            {
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    {
        // Example 1
        utility::print(solution.twoSum(v, 9));
    }
    {
        // Example 2
        vector<int> v{3,2,4};
        utility::print(solution.twoSum(v, 6));
    }
    {
        // Example 3
        vector<int> v{3,3};
        utility::print(solution.twoSum(v, 6));
    }

    return 0;
}
