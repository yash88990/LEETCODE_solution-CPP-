import java.util.Collections;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public String reverseWords(String s) {
        // Trim leading/trailing spaces and split by one or more spaces
        // This mirrors the behavior of 'ss >> word' in C++
        String[] words = s.trim().split("\\s+");
        
        // Convert to list to use Collections.reverse, mirroring reverse(newword.begin(), ...)
        List<String> wordList = new ArrayList<>(Arrays.asList(words));
        Collections.reverse(wordList);
        
        // Join the reversed words with a single space
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < wordList.size(); i++) {
            result.append(wordList.get(i));
            if (i < wordList.size() - 1) {
                result.append(" ");
            }
        }
        
        return result.toString();
    }
}