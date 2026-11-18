class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //one way is sort and compare and put into array
        map<string,vector<string>>mp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }

        vector<vector<string>>s;
        for(auto it:mp){
            s.push_back(it.second);
        }
        return s;
    }
};
