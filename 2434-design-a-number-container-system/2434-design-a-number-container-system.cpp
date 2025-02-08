#include <unordered_map>
#include <map>
#include <set>

class NumberContainers {
private:
    std::unordered_map<int, int> indexToNumber; // Maps index to number
    std::unordered_map<int, std::set<int>> numberToIndices; // Maps number to a sorted set of indices

public:
    NumberContainers() {}
    
    void change(int index, int number) {
        // If the index is already occupied by some number, remove it from the numberToIndices map
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }
        // Insert or update the index with the new number
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        if (numberToIndices.count(number) && !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin(); // Get the smallest index
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */
