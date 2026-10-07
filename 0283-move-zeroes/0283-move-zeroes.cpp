class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j =0 , cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0)cnt++;
            else{
                nums[j++] = nums[i];
            }
        }
        for(int i = j ; i < nums.size() ; i++){
            nums[j++] = 0;
        }
    }
};