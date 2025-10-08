class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1 , e = *max_element(nums.begin() , nums.end());
        int ans = 0;
        if( nums.size() == threshold)return e;
        while(s <= e){
            int m = s + ( e - s )/2;
            int total = 0;
            for(int num : nums){
                total += (num + m -1 )/ m;
            }
            if(total <= threshold){
                ans = m;
                e = m - 1;
            }else s = m + 1;
        }

        return ans ;
    }
};