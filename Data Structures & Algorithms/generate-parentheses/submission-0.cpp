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
    void generateString(int ind,string temp){
            if(ind==2*N){
                if(isBalanced(temp)){
                    ans.push_back(temp);
                }
                return ;
            }
            generateString(ind+1,temp+'(');
            
            generateString(ind+1,temp+')');
    }
    vector<string> generateParenthesis(int n) {
        N=n;
        generateString(0,"");
        return ans;
    }
};
