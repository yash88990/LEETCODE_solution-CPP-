#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiantQueue;
        queue<int> direQueue;
        
        // Initialize the queues with indices of the senators
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                radiantQueue.push(i);
            } else {
                direQueue.push(i);
            }
        }
        
        // Simulate the voting process
        while (!radiantQueue.empty() && !direQueue.empty()) {
            int rIndex = radiantQueue.front();
            int dIndex = direQueue.front();
            radiantQueue.pop();
            direQueue.pop();
            
            if (rIndex < dIndex) {
                radiantQueue.push(rIndex + n); // Radiant bans Dire, re-enqueue Radiant
            } else {
                direQueue.push(dIndex + n); // Dire bans Radiant, re-enqueue Dire
            }
        }
        
        return radiantQueue.empty() ? "Dire" : "Radiant";
    }
};