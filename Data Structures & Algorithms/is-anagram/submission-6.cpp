class Solution {
public:
    bool isAnagram(string s, string t) {
        //lets count based on character
        vector<int>values(26,0);
        for(auto it:s)values[it-'a']++;
        for(auto it:t)values[it-'a']--;
        for(auto it:values)if(it!=0)return false;
        return true;
    }
};
