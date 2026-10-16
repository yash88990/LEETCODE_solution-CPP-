class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0;
        for(int i = 0; i < n ; i++){
            if(jump < i)return false;
            jump = max(jump , nums[i] + i);
            if(jump >= n-1){
                return true;
            }
        }
        return false;
    }
};