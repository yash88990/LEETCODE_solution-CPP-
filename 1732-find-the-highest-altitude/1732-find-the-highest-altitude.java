class Solution {
    public int largestAltitude(int[] gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;

        for (int gainValue : gain) {
            // Calculate new altitude
            currentAltitude += gainValue;
            
            // Update max altitude seen so far
            maxAltitude = Math.max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
}