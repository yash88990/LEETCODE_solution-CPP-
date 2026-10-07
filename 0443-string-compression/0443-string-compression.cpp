class Solution {
public:
    int compress(vector<char>& s) {
        int n = s.size();
        int index = 0;

        for(int i = 0 ; i < n ; i++){
            char ch = s[i];
            int cnt = 0 ;
            while(i < n && s[i] == ch){
                cnt++;
                i++;
            }

            if(cnt == 1)s[index++] = ch;
            else{
                s[index++] = ch;
                string digit = to_string(cnt);
                for(char c : digit)s[index++] = c;
            }
            i--;
        }
        s.resize(index);
        return index;

    }
};