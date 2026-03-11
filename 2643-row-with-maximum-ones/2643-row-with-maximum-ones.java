class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {

        int m = mat.length;
        int n = mat[0].length;

        int totalOnes = Integer.MIN_VALUE;
        int minRow = Integer.MAX_VALUE;

        for (int i = 0; i < m; i++) {
            int onesCount = 0;

            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    onesCount++;
                }
            }

            if (totalOnes < onesCount) {
                minRow = i;
                totalOnes = onesCount;
            }
        }

        return new int[]{minRow, totalOnes};
    }
}