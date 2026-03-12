class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1, e = *max_element(nums.begin() , nums.end()) , ans = -1;
        while(s <= e ){
            int m = s + ( e - s )/2;
            int total = 0;
            for(int num : nums)total += (num + m - 1)/m;
            if(total <= threshold){
                ans = m;
                e = m - 1;
            }else s = m + 1;

        }
        return ans;
    }
};