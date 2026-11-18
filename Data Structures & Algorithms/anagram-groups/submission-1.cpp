class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //one way is simple sort one string 
        //later insert into map for that
        //last traverse and return the ans
        unordered_map<string,vector<string>>mp;
        int n=strs.size();
        
        for(auto it:strs){
        vector<int>v(26,0);
        for(auto x:it){
            v[x-'a']++;
        }
        string key="";
        for(int i=0;i<26;i++){
            key+='#'+to_string(v[i]);
        }
        mp[key].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
