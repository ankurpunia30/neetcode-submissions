class Solution {
public:
    bool isAnagram(string s, string t) {
        // map<char,int>mp;
        // if(s.size()!=t.size())return false;
        // for(auto it:s){
        //     mp[it]++;

        // }

        // for(auto it:t){
        //     mp[it]--;
        //     if(mp[it]<0){
        //         return false;
        //     }
        // }
        // return true;
        int xorSum=0;
        int charSum=0;
        if(t.size()!=s.size())return false;
        for(int i=0;i<t.size();i++){
            xorSum^=t[i]^s[i];
            charSum+=t[i]-s[i];
        }
        return xorSum==0 && charSum==0;
    }
};
