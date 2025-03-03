class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int j = 0;
        for(int num : nums){
            if(num < pivot){
                ans[j] = num;
                j++;
            }
        }
        for(int num : nums){
            if(num == pivot){
                ans[j] = num;
                j++;
            }
        }
        for(int num : nums){
            if(num > pivot){
                ans[j] = num;
                j++;
            }
        }
        return ans;
    }
};