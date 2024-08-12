#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to maintain the k largest elements
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // Initialize the min-heap with the first k elements of the array
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);  // Add the new value to the min-heap
        if (minHeap.size() > k) {
            minHeap.pop();  // Maintain the size of the heap to be k
        }
        return minHeap.top();  // The root of the heap is the kth largest element
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
