class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0 , maxjump = 0 , step = 0;
        for(int i = 0 ; i< n - 1 ; i++){
            maxjump = max(maxjump , i + nums[i]);
            if(i == step){
                jump++;
                step = maxjump;
                if(step >= n-1)break;
            }
        }
        return jump;
    }
};