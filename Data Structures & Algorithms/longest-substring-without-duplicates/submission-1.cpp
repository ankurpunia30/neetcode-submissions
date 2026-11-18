class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>mp;
        int i=0;int  j=0;
        int ans=0;int n=s.size();
        while(i<n && j<n){
            
            while(mp.find(s[j])!=mp.end()){
                mp.erase(s[i]);
                i++;
            }
            mp.insert(s[j]);
            ans=max(ans,j-i+1);
            j++;

        }
        return ans;
    }
};
