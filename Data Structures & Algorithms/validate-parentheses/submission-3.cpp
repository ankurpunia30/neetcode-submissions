class Solution {
public:
    bool match(char top,char curr){
        if((top=='(' && curr==')')||(top=='[' && curr==']') || (top=='{' && curr=='}'))return true;
        return false;
    }
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            
            if(it=='(' || it=='[' || it=='{')st.push(it);
            else{
                if(st.empty())return false;
                int curr=st.top();st.pop();
                if(!match(curr,it)){
                    return false;
                }
            }

        }
        if(!st.empty())return false;
        return true;
    }
};
