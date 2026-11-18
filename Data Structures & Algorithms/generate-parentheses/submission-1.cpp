class Solution {
public:
    vector<string>ans;
    int N;
    bool isBalanced(string s){
        //check opening and closing bracket
        stack<char>st;
        for(int i=0;i<s.size();i++){
                if(s[i]=='(')st.push(s[i]);
                else{
                    if(st.empty())return false;
                    st.pop();
                }
            }

        return st.empty();
    }
    void generateString(int open,int close,string temp){
            if(temp.size()==2*N){
                
                    ans.push_back(temp);
                
            }
            if(open<N)
            generateString(open+1,close,temp+'(');
            if(close<open)
            generateString(open,close+1,temp+')');
    }
    vector<string> generateParenthesis(int n) {
        N=n;
        generateString(0,0,"");
        return ans;
    }
};
