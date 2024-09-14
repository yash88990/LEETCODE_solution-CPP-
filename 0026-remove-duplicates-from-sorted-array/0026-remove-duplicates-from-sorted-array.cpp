class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0 ;
        for(int i = 0 ; i < nums.size() ; i++ ){
            if(nums[index] != nums[i]){
                index++;
                nums[index] = nums[i];
            }
        }
        return index+1;
    }
};