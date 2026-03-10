class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        int s = flowerbed.length;

        for (int i = 0; i < s; i++) {
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty or out of bounds
                boolean emptyLeft = (i == 0 || flowerbed[i - 1] == 0);
                boolean emptyRight = (i == s - 1 || flowerbed[i + 1] == 0);

                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }

        return count >= n;
    }
}