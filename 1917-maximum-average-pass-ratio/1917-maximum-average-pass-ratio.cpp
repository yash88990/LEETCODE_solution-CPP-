class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max-heap to store the marginal gain, passi, and totali
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        // Initialize the heap with the marginal gain of each class
        for (const auto& cls : classes) {
            int passi = cls[0];
            int totali = cls[1];
            double gain = calculateGain(passi, totali);
            maxHeap.push({gain, {passi, totali}});
        }

        // Assign extra students to maximize the average pass ratio
        while (extraStudents > 0) {
            auto top = maxHeap.top();
            maxHeap.pop();

            double gain = top.first;
            int passi = top.second.first;
            int totali = top.second.second;

            // Assign one extra student to this class
            passi++;
            totali++;
            extraStudents--;

            // Recalculate the gain and push back to the heap
            gain = calculateGain(passi, totali);
            maxHeap.push({gain, {passi, totali}});
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0.0;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int passi = top.second.first;
            int totali = top.second.second;
            totalPassRatio += (double)passi / totali;
        }

        return totalPassRatio / classes.size();
    }

private:
    // Helper function to calculate the marginal gain of adding an extra student
    double calculateGain(int passi, int totali) {
        return ((double)(passi + 1) / (totali + 1)) - ((double)passi / totali);
    }
};