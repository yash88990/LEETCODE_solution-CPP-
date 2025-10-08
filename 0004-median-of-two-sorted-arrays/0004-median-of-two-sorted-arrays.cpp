#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Merge both arrays
        vector<int> merged;
        // merged.reserve(nums1.size() + nums2.size());
        merged.insert(merged.end(), nums1.begin(), nums1.end());
        merged.insert(merged.end(), nums2.begin(), nums2.end());

        // Step 2: Sort the merged array
        sort(merged.begin(), merged.end());

        // Step 3: Find median
        int n = merged.size();
        if (n % 2 == 1) {
            // Odd length → middle element
            return merged[n / 2];
        } else {
            // Even length → average of two middle elements
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
    }
};
