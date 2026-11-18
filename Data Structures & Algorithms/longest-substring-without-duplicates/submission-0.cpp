class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len=0;
        int n=s.size();
        int i=0;
        int j=0;
        set<char>st;
        int maxlen=0;
        while(i<n && j<n){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};
