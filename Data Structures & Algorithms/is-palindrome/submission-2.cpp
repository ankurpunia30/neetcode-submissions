class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(auto it:s){
            if(isalpha(it))t+=tolower(it);
            else if(isdigit(it))t+=it;
        }
        for(int i=0;i<t.size()/2;i++){
            if(t[i]!=t[t.size()-i-1])return false;
        }
        return true;
    }
};
