class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        for(int i = 0 ; i < n ; i++){
            char ch = chars[i];
            int count = 0;
            while(i < n && chars[i] == ch){
                count++;
                i++;
            }
            if(count == 1 )chars[index++] = ch;
            else{
                chars[index++] = ch;
                string str = to_string(count);
                for(char digit : str){
                    chars[index++] = digit;
                }
            }
            i--;

        }
        chars.resize(index);
        return index ;

    }
};