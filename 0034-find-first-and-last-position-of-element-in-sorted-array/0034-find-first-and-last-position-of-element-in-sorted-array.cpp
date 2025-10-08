class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0 , e = nums.size() -1;
        int first = -1 , last = -1;
        //first occurance of element
        while( s <=  e){
            int m = s + ( e -s )/2;
            if(nums[m] == target){
                first = m;
                e= m - 1 ;
            }else if(nums[m] < target)s = m + 1 ;
            else e = m - 1;
        }
        s = 0 , e = nums.size() - 1;

        //last occurance of element
        while( s <=  e){
            int m = s + ( e -s )/2;
            if(nums[m] == target){
                last = m;
                s = m + 1  ;
            }else if(nums[m] < target)s = m + 1 ;
            else e = m - 1;
        }
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;

    }
};