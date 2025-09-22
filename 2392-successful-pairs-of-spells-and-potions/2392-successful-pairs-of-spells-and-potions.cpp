#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::vector<int> result;
        std::sort(potions.begin(), potions.end());

        for (const auto& spell : spells) {
            long long required_potion_strength = std::ceil((double)success / spell);
            auto it = std::lower_bound(potions.begin(), potions.end(), required_potion_strength);
            int successful_count = potions.end() - it;
            result.push_back(successful_count);
        }

        return result;
    }
};