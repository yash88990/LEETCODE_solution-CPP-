class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> ans;
        for(int num : nums1){
            ans.push_back(num);
        }
         for(int num : nums2){
            ans.push_back(num);
        }
        sort(ans.begin() , ans.end());
        int n = ans.size();
        int mid = n/2;
        double res = 0.0;
        if(n % 2 != 0)return ans[mid];
        else{
             res = (ans[mid] + ans[mid - 1]) / 2;
            
        } 
        return res;
        
            
    }
};