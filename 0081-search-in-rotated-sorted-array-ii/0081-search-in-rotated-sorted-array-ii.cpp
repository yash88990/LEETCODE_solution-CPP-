class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int s = 0 , e = nums.size()-1;
        while(s <= e ){
            int m = s + ( e - s)/2;
            if(nums[m] == target)return true;
            if(nums[m] == nums[s] && nums[m] == nums[e]){
                s++;
                e--;
                continue;
            }
            else if(nums[m] >= nums[s]){ //left part sorted
                 if((target <= nums[m]) && (target >= nums[s]))e = m- 1;
                 else s = m + 1 ;

            }else{//right part sorted
                 if((target >= nums[m] && nums[e] >= target ))s = m + 1 ;
                 else e = m - 1;

            }
        }
        return false;
    }
};