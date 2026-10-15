class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)return nums.size();
        int k = 2 ;
        for(int i = k ; i <  nums.size() ; i++){
            if(nums[i] != nums[k-2]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};