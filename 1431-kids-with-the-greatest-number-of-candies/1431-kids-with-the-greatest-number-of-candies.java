import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> ans = new ArrayList<>();
        
        // Find the maximum element in the array
        int maxi = candies[0];
        for (int candy : candies) {
            if (candy > maxi) {
                maxi = candy;
            }
        }
        
        // Check if each child can have the maximum number of candies
        for (int i = 0; i < candies.length; i++) {
            if (candies[i] + extraCandies >= maxi) {
                ans.add(true);
            } else {
                ans.add(false);
            }
        }
        
        return ans;
    }
}