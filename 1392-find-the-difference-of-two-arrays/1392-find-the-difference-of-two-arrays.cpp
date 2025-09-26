class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin() , nums1.end());
        unordered_set<int> set2(nums2.begin() , nums2.end());
        vector<int>ans1 , ans2;
        for(int num : nums1){
            if(set2.find(num) == set2.end() && find(ans1.begin() , ans1.end() , num) == ans1.end())ans1.push_back(num);
        }
        for(int num : nums2  ){
            if(set1.find(num) == set1.end() && find(ans2.begin() , ans2.end() , num) == ans2.end())ans2.push_back(num);
        }
        return {ans1 , ans2};

    }
};