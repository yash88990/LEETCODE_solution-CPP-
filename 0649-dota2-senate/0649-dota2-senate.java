import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public String predictPartyVictory(String senate) {
        Queue<Integer> radiant = new LinkedList<>();
        Queue<Integer> dire = new LinkedList<>();
        int n = senate.length();

        // Step 1: Add indices of each senator to their respective queues
        for (int i = 0; i < n; i++) {
            if (senate.charAt(i) == 'R') {
                radiant.add(i);
            } else {
                dire.add(i);
            }
        }

        // Step 2: Simulate the voting rounds
        while (!radiant.isEmpty() && !dire.isEmpty()) {
            int rIndex = radiant.poll();
            int dIndex = dire.poll();

            // The senator with the smaller index bans the other
            if (rIndex < dIndex) {
                // Radiant wins this round and rejoins the queue for the next round
                radiant.add(rIndex + n);
            } else {
                // Dire wins this round and rejoins the queue for the next round
                dire.add(dIndex + n);
            }
        }

        // Step 3: Determine the winner based on which queue still has senators
        return radiant.isEmpty() ? "Dire" : "Radiant";
    }
}