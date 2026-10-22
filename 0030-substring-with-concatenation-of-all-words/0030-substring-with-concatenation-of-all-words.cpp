class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>result;
        if(s.empty() || words.empty())return result;
        int wordlen = words[0].size();
        int numwords = words.size();
        int totallen = wordlen * numwords;
        if(s.length() < totallen)return result;
        unordered_map<string,int>wordcount;
        for(auto i : words)wordcount[i]++;
        for(int i = 0 ; i < wordlen ; i++){
            int left = i , right = i ;
            unordered_map<string ,int>seen;
            int cnt = 0;
            while(right + wordlen <= s.length()){
                string sub = s.substr(right , wordlen);
                right += wordlen;

                if(wordcount.find(sub) != wordcount.end()){
                    seen[sub]++;
                    cnt++;

                    while(seen[sub] > wordcount[sub]){
                        string leftsub = s.substr(left , wordlen);
                        seen[leftsub]--;
                        left += wordlen;
                        cnt--;
                    }
                    if(cnt == numwords)result.push_back(left);
                }else{
                    seen.clear();
                    cnt = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};