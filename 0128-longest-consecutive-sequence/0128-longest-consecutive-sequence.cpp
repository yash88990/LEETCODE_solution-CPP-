class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end()); 

        int ans = 1, count = 1, n = nums.size();
        int start = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) continue; 

            if (nums[i] == start + 1) {
                count++;
            } else { 
                ans = max(ans, count);
                count = 1;
            }

            start = nums[i]; 
        }

        return max(ans, count); 
    }
};
