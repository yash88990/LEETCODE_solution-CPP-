import java.util.LinkedList;
import java.util.Queue;

class RecentCounter {
    private Queue<Integer> q;

    public RecentCounter() {
        // Initialize the queue, mirroring your C++ constructor
        q = new LinkedList<>();
    }
    
    public int ping(int t) {
        // Add the new timestamp
        q.add(t);
        
        // Remove timestamps that are older than t - 3000
        while (!q.isEmpty() && q.peek() < t - 3000) {
            q.poll();
        }
        
        // The size of the queue represents the number of recent pings
        return q.size();
    }
}