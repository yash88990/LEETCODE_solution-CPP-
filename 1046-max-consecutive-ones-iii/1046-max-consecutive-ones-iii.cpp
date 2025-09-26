class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left =0 ;
        int zerocnt = 0 , maxlen = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0)zerocnt++;
            while(zerocnt > k){
                if(nums[left] == 0) zerocnt--;
                left++;
            }
            maxlen = max(maxlen , i - left + 1 );
        }
        return maxlen;
    }
};