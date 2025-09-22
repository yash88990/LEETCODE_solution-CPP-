#include <queue>
#include <unordered_set>

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        nextSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        if (!minHeap.empty()) {
            result = minHeap.top();
            minHeap.pop();
            addedBackSet.erase(result);
        } else {
            result = nextSmallest;
            nextSmallest++;
        }
        return result;
    }
    
    void addBack(int num) {
        if (num < nextSmallest && addedBackSet.find(num) == addedBackSet.end()) {
            minHeap.push(num);
            addedBackSet.insert(num);
        }
    }

private:
    int nextSmallest;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::unordered_set<int> addedBackSet;
};