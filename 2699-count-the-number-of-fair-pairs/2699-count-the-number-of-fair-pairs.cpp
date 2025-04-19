#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int up = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            count += (up - low);
        }
        
        return count;
    }
};
