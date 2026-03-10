class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        int idx = 0;
        
        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;
            
            // Count occurrences of the current character
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }
            
            // Write character to the array
            chars[idx++] = ch;
            
            // If group size is > 1, write the digits of the count
            if (count > 1) {
                String str = Integer.toString(count);
                for (char digit : str.toCharArray()) {
                    chars[idx++] = digit;
                }
            }
            
            // Correct for the outer loop's i++
            i--;
        }
        
        // Note: In Java arrays cannot be resized like C++ vectors, 
        // but the problem returns the new length.
        return idx;
    }
}