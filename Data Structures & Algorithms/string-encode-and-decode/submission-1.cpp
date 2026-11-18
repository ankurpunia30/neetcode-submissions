class Solution {
public:

    string encode(vector<string>& strs) {
        string t=".";
        string ans="";
        for(auto it:strs){
            ans+=it+t;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>t;
        string ans="";
        for(auto it:s){
            
            if(it=='.'){
                t.push_back(ans);
                ans="";
            }
            else{
                ans+=it;
            }
        }
        return t;
    }
};
