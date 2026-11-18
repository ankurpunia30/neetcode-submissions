class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        if (t.size() > s.size()) return "";

        for (char ch : t) mp[ch]++;

        int requiredSize = mp.size();
        int formed = 0;
        int i = 0, j = 0;
        int minlen = INT_MAX;
        int minStart = 0;
        unordered_map<char, int> window;

        while (j < s.size()) {
            window[s[j]]++;

            if (mp.count(s[j]) && window[s[j]] == mp[s[j]]) {
                formed++;
            }

            while (formed == requiredSize) {
                if (j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    minStart = i;
                }

                window[s[i]]--;
                if (mp.count(s[i]) && window[s[i]] < mp[s[i]]) {
                    formed--;
                }
                i++;
            }
            j++;
        }

        return minlen == INT_MAX ? "" : s.substr(minStart, minlen);
    }
};
