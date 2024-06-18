class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        
        // Create pairs of (difficulty, profit) for each job
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        
        // Sort jobs by difficulty
        sort(jobs.begin(), jobs.end());
        
        // Sort workers by their ability
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0;
        int j = 0;
        int bestProfit = 0;
        
        // Iterate through each worker
        for (int ability : worker) {
            // Find the maximum profit among the jobs the current worker can handle
            while (j < n && jobs[j].first <= ability) {
                bestProfit = max(bestProfit, jobs[j].second);
                ++j;
            }
            // Accumulate the maximum profit for the current worker
            maxProfit += bestProfit;
        }
        
        return maxProfit;
    }
};