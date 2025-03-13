class Solution {
public:
    bool canmakezero(int k , int n ,vector<int>& nums, vector<vector<int>>& queries ){
        vector<int> dp(n+ 1 , 0);
        for(int i = 0 ; i < k ; i++){
            int l = queries[i][0] , r = queries[i][1] , value = queries[i][2];
            dp[l] += value;
            dp[r + 1] -= value;
        }
        int sum = 0;
        for(int i = 0; i < n ; i++){
            sum += dp[i];
            if(nums[i] > sum)return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size() , m = queries.size();
        if(*max_element(nums.begin() , nums.end()) == 0)return 0;
        int left = 0 , right = m + 1 ;
        while(left < right){
            int mid = left + ( right - left) / 2 ;
            if(canmakezero(mid , n , nums , queries)){
                right = mid ;
            }else{
                left =mid +1 ;
            }
        }
        return left > m ? -1 : left;
    }
};