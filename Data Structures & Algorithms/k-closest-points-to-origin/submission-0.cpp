class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap: we keep k smallest distances, so remove the largest when exceeding k
        priority_queue<pair<int, vector<int>>> pq;

        for (auto& point : points) {
            int x = point[0], y = point[1];
            int dist = x * x + y * y;  // Use squared distance (no sqrt needed)

            pq.push({dist, point});
            if (pq.size() > k) pq.pop();  // Maintain size = k
        }

        // Extract from heap
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
