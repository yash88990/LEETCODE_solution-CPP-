class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int maxfreq = 0;
        for(auto & [element , frequency] : freq){
            maxfreq = max(maxfreq , frequency);
        }
        int sum = 0;
        for(auto &[element , frequency] : freq){
            if(frequency == maxfreq){
                sum += frequency;
            }
        }
        return sum;
    }
};
