class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0 ;
        int current_sum  = 0 ;
        int min_length = INT_MAX ;
        for(int i = 0 ;  i < nums.size() ; i++ ){
            current_sum += nums[i] ;
            while(current_sum >= target ){
                min_length = min(min_length , i - left + 1 ) ;
                current_sum -= nums[left];
                left++;
            }
        }   
        if(min_length == INT_MAX){
            return 0 ;
        }else{
            return min_length ;
        }
    }
};