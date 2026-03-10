#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> difference1;
        vector<int> difference2;

        // Elements in nums1 but not in nums2
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                difference1.push_back(num);
            }
        }

        // Elements in nums2 but not in nums1
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                difference2.push_back(num);
            }
        }

        return {difference1, difference2};
    }
};