class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int s = 0 , e = nums.size() -1;
        
        while(s <= e ){
            int m = s + ( e - s )/2;
            

            if(nums[m] == target)return true;
            else if(nums[s] == nums[m] && nums[m] == nums[e]){
                s++;
                e--;
                continue;
            }


            else if(nums[m] >= nums[s]){//left part sorted hai
                 if(target >= nums[s] && target <= nums[m]){
                    e = m - 1 ;
                 }else s = m + 1;
                 
            }else { // right part sorted h
                  if(target >= nums[m] &&  target <= nums[e]){
                    s =  m +1  ;
                  }else e = m -1;
            }
        }
        return false;
    }
};