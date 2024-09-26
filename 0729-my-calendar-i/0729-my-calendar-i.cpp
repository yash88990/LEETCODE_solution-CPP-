#include <vector>
using namespace std;

class MyCalendar {
public:
    // Vector to store the booked intervals
    vector<pair<int, int>> bookings;

    // Constructor to initialize the calendar
    MyCalendar() {}

    // Function to book an event if it doesn't cause double booking
    bool book(int start, int end) {
        // Iterate through the existing bookings
        for (const auto& interval : bookings) {
            int booked_start = interval.first;
            int booked_end = interval.second;

            // Check for overlap
            if (start < booked_end && end > booked_start) {
                return false;
            }
        }

        // If no overlap, add the new interval to bookings
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
