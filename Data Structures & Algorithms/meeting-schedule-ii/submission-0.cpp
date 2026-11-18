#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * };
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });

        // Min-heap to keep track of end times
        priority_queue<int, vector<int>, greater<int>> pq;

        // Add the end time of the first meeting
        pq.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); ++i) {
            // If the room is free, reuse it (remove the earliest ending meeting)
            if (intervals[i].start >= pq.top()) {
                pq.pop();
            }
            // Allocate a room (add the current meeting's end time)
            pq.push(intervals[i].end);
        }

        // The size of the heap is the number of rooms needed
        return pq.size();
    }
};
