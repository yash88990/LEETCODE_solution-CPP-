#include <vector>
#include <map>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        std::map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        for (auto it = count.begin(); it != count.end(); ++it) {
            int start = it->first;
            int occurrences = it->second;
            if (occurrences > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (count[start + i] < occurrences) {
                        return false;
                    }
                    count[start + i] -= occurrences;
                }
            }
        }

        return true;
    }
};
