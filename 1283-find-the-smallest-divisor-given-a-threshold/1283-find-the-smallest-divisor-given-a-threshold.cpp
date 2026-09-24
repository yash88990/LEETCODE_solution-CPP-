class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1 , end = *max_element(nums.begin() , nums.end());
        int ans = -1;
        while(start <= end){
            int mid = start + ( end - start )/ 2;
            int total = 0;
            for(int num : nums){
                total += ceil(double(num) / mid);
            }
            if(total <= threshold){
                ans = mid;
                end = mid - 1;
            }else start = mid + 1 ;
        }
        return ans;
    }
};