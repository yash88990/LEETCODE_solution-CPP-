class Solution {
public:
    long long maximumTripletValue(vector<int>& arr) {
        int n = arr.size();
        long long maxsum = LLONG_MIN;
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n; k++) {
                    long long sum = (long long)(arr[i] - arr[j]) * arr[k];
                    maxsum = max(maxsum, sum);
                }
            }
        }

        return maxsum < 0 ? 0 : maxsum;
    }
};
