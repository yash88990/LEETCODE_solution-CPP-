#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0; // End of the current jump
        int farthest = 0; // Farthest point reachable from current jump
        
        for (int i = 0; i < n - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]); // Update the farthest reachable point
            
            if (i == currentEnd) { // If we reached the end of current jump
                ++jumps; // Increment jumps
                currentEnd = farthest; // Update the end of the current jump
            }
        }
        
        return jumps;
    }
};
