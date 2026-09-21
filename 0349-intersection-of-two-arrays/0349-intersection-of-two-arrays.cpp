class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        vector<int>arr1,arr2;
        int n1 = nums1.size() , n2 = nums2.size();
        arr1.push_back(nums1[0]);
        for(int i = 1 ; i < n1 ; i++){
            if(nums1[i] != nums1[i-1]){
                arr1.push_back(nums1[i]);
            }

        }
        arr2.push_back(nums2[0]);
        for(int i = 1 ; i < n2 ; i++){
            if(nums2[i] != nums2[i-1]){
                arr2.push_back(nums2[i]);
            }

        }
        int i = 0 , j= 0;
        vector<int>ans;
        int arr1size = arr1.size() , arr2size=arr2.size();
        while( i < arr1size && j < arr2size){
            if(arr1[i] == arr2[j]){
                ans.push_back(arr1[i]);
                i++;
                j++;
            }else if(arr1[i] > arr2[j])j++;
            else i++;
        }
        return ans;
    }
};