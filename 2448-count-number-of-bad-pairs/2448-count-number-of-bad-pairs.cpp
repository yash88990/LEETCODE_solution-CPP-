#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;
        unordered_map<int, long long> freq;
        long long goodPairs = 0;
        
        for (int i = 0; i < n; i++) {
            int val = nums[i] - i;
            if (freq.find(val) != freq.end()) {
                goodPairs += freq[val];  // Count pairs where val[i] == val[j]
            }
            freq[val]++;
        }
        
        return totalPairs - goodPairs;
    }
};