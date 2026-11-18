class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
        if(s.size()!=t.size())return false;
        for(auto it:s)mp1[it]++;
        
        
        for(auto it:t){
            if(mp1.find(it)==mp1.end() || mp1[it]==0)return false;
            mp1[it]--;
        }
        return true;
    }
};
