#include <queue>

class RecentCounter {
private:
    std::queue<int> requests;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        // Add the current timestamp to the queue
        requests.push(t);
        
        // Remove all requests older than 3000 milliseconds
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }
        
        // Return the number of requests within the last 3000 milliseconds
        return requests.size();
    }
};