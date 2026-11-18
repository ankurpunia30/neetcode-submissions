class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> count1(26, 0), count2(26, 0);

        // Count frequency of each char in s1
        for (char c : s1) {
            count1[c - 'a']++;
        }

        // Initialize the first window in s2
        for (int i = 0; i < s1.size(); ++i) {
            count2[s2[i] - 'a']++;
        }

        // Slide the window over s2
        for (int i = s1.size(); i < s2.size(); ++i) {
            if (count1 == count2) return true;

            // Slide the window: remove left char and add right char
            count2[s2[i - s1.size()] - 'a']--;
            count2[s2[i] - 'a']++;
        }

        // Check the last window
        return count1 == count2;
    }
};
