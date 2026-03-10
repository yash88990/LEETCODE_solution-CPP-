import java.util.HashMap;
import java.util.Map;

class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length;
        int count = 0;
        
        // Using maps to store the frequency of rows and columns
        Map<String, Integer> rowMap = new HashMap<>();
        Map<String, Integer> colMap = new HashMap<>();

        // Step 1: Count occurrences of rows
        for (int i = 0; i < n; i++) {
            StringBuilder rowStr = new StringBuilder();
            for (int j = 0; j < n; j++) {
                rowStr.append(grid[i][j]).append(",");
            }
            String key = rowStr.toString();
            rowMap.put(key, rowMap.getOrDefault(key, 0) + 1);
        }

        // Step 2: Count occurrences of columns
        for (int j = 0; j < n; j++) {
            StringBuilder colStr = new StringBuilder();
            for (int i = 0; i < n; i++) {
                colStr.append(grid[i][j]).append(",");
            }
            String key = colStr.toString();
            colMap.put(key, colMap.getOrDefault(key, 0) + 1);
        }

        // Step 3: Find matching row and column pairs
        for (String rowKey : rowMap.keySet()) {
            if (colMap.containsKey(rowKey)) {
                count += rowMap.get(rowKey) * colMap.get(rowKey);
            }
        }

        return count;
    }
}