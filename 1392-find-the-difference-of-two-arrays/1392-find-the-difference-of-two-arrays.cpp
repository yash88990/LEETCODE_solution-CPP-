#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());
        
        std::vector<int> difference1, difference2;
        
        for (int num : nums1) {
            if (set2.find(num) == set2.end() && std::find(difference1.begin(), difference1.end(), num) == difference1.end()) {
                difference1.push_back(num);
            }
        }
        
        for (int num : nums2) {
            if (set1.find(num) == set1.end() && std::find(difference2.begin(), difference2.end(), num) == difference2.end()) {
                difference2.push_back(num);
            }
        }
        
        return {difference1, difference2};
    }
};