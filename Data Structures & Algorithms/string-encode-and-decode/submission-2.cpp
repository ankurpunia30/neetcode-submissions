class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto it : strs){
            ans += to_string(it.size()) + "#" + it;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while(i < s.size()){
            int j = i;

            // find '#'
            while(s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));

            // move to start of string
            j++;

            ans.push_back(s.substr(j, len));

            // move to next encoded part
            i = j + len;
        }

        return ans;
    }
};
