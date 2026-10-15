class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //method 1 

        // int j = 0;
        // for(int i = m  ; i < m +n  ; i++){
        //     nums1[i] = nums2[j++];
        // }
        // sort(nums1.begin() , nums1.end());

        //method 2 
        int i = m-1 , j = n-1 , k = m+ n -1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j])nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while(j>= 0)nums1[k--] = nums2[j--];
    }
};