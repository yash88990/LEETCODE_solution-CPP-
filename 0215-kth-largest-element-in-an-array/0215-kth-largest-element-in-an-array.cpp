#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Min-heap banate hain
      priority_queue<int, vector<int>,greater<int>> minHeap;
        
        // Har element ko check karte hain
        for (int num : nums) {
            minHeap.push(num);  // Element ko heap me dalte hain
            // Agar heap ka size k se zyada ho gaya, toh smallest element ko nikaal dete hain
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Ab heap ke top pe jo element hai, woh kth largest element hoga
        return minHeap.top();
    }
};
