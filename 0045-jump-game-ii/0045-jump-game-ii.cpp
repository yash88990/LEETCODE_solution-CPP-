class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 )return 0;
        int jumps = 0;
        int currentend = 0;
        int farthest = 0;

        for(int i = 0 ; i < n-1 ; i++){
            farthest = max(farthest , i + nums[i]);
            if(i == currentend){
                jumps++;
                currentend = farthest ;
                if(currentend >= n- 1)break;
            }
        }
        return jumps;
    }
};