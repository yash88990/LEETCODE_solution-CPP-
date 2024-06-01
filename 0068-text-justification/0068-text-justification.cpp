class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;
        
        while (index < n) {
            int totalChars = words[index].size();
            int last = index + 1;
            
            // Determine how many words can fit into the current line
            while (last < n) {
                if (totalChars + 1 + words[last].size() > maxWidth) break;
                totalChars += 1 + words[last].size();
                last++;
            }
            
            string line;
            int numWords = last - index;
            // If it's the last line or the line has only one word, left justify
            if (last == n || numWords == 1) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        line += " ";
                    }
                }
                while (line.size() < maxWidth) {
                    line += " ";
                }
            } else {
                // Fully justify the line
                int totalSpaces = maxWidth - totalChars + (numWords - 1);
                int spaceBetween = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);
                
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        for (int j = 0; j <= (i - index < extraSpaces ? spaceBetween : spaceBetween - 1); j++) {
                            line += " ";
                        }
                    }
                }
            }
            
            result.push_back(line);
            index = last;
        }
        
        return result;
    }
};
