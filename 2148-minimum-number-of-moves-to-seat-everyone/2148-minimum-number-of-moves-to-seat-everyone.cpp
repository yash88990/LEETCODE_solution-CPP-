#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Step 1: Sort both arrays
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        // Step 2: Calculate the total moves required
        int total_moves = 0;
        for (int i = 0; i < seats.size(); ++i) {
            total_moves += abs(seats[i] - students[i]);
        }
        
        return total_moves;
    }
};
