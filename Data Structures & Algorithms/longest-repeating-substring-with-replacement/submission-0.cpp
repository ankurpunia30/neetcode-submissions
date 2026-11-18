class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int i = 0;
        int j = 0;
        vector<int> mp(26, 0); // frequency map for A-Z
        int maxFreq = 0;
        int n = s.size();

        while (j < n) {
            mp[s[j] - 'A']++;
            maxFreq = max(maxFreq, mp[s[j] - 'A']);

            // if more than k characters need to be replaced
            if ((j - i + 1) - maxFreq > k) {
                mp[s[i] - 'A']--;
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
            j++;
        }

        return maxlen;
    }
};
