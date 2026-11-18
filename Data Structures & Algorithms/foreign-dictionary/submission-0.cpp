class Solution {
public:
    pair<char, char> findDiff(string& a, string& b) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) return {a[i], b[i]};
        }
        // Invalid case: prefix problem
        if (a.size() > b.size()) return {'#', '#'};
        return {' ', ' '}; // no ordering info
    }

    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // Collect all unique characters
        for (auto& word : words) {
            for (char ch : word) {
                adj[ch];        // ensure entry exists
                indegree[ch];   // initialize indegree to 0
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            auto [a, b] = findDiff(words[i], words[i + 1]);
            if (a == '#' && b == '#') return ""; // invalid order
            if (a != ' ' && b != ' ') {
                adj[a].push_back(b);
                indegree[b]++;
            }
        }

        // Topological Sort using Kahn's Algorithm (BFS)
        queue<char> q;
        for (auto& [ch, deg] : indegree) {
            if (deg == 0) q.push(ch);
        }

        string order;
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            order += curr;

            for (char neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check for cycle
        if (order.size() != adj.size()) return "";

        return order;
    }
};
