class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size() ;
        vector<pair < int , int > > jobs(n) ;
        for(int i = 0 ; i < n ; i++ ){
            jobs[i] = {difficulty[i] , profit[i]};
        }
        sort(jobs.begin() , jobs.end());
        sort(worker.begin() , worker.end());
        int maxprofit = 0 ;
        int j = 0 ;
        int bestprofit = 0 ;
        for( int ability : worker ){
            while(j < n && jobs[j].first <= ability ){
                bestprofit = max(bestprofit , jobs[j].second);
                j++;
            }
            maxprofit += bestprofit ; 
        }
        return maxprofit ;
    }
};