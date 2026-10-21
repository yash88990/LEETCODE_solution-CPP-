class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>result;
        int i = 0;
        int n = words.size();
        while(i < n){
            int j = i ;
            int linelength = 0;
            while(j < n && (linelength + words[j].size() + (j-i)) <= maxWidth){
                linelength += words[j].size();
                j++;
            }
            int numwords = j-i;
            int totalspace = maxWidth - linelength;
            string currline = "";
            if( j == n || numwords == 1){
                for(int k = i ; k < j ; k++){
                    currline += words[k];
                    if(k < j-1){
                        currline += " ";
                        totalspace--;
                    }
                }
                currline += string(totalspace , ' ');
            }else{
                int gaps = numwords - 1;
                int basespace = totalspace /gaps;
                int extraspace = totalspace % gaps;
                for(int k = i ; k < j ; k++){
                    currline += words[k];
                    if(k < j-1){
                        int spaceapply = basespace + (extraspace  > 0 ? 1 : 0);
                        currline += string(spaceapply , ' ');
                        extraspace--;
                    }
                }
            }
            result.push_back(currline);
            i=j;
        }
        return result;
    }
};