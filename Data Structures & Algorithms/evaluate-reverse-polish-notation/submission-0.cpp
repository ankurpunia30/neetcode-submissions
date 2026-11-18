class Solution {
public:
    int eval(int x,int y,string op){
        if(op=="+")return x+y;
        if(op=="-")return y-x;
        if(op=="*")return x*y;
        if(op=="/")return y/x;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        int evalAns=0;
        stack<int>st;
        for(auto it:tokens){
            if(it.size() > 1 || isdigit(it[0]))
            {
                st.push(stoi(it));
            }
            else{
                int x=st.top();st.pop();
                int y=st.top();st.pop();
                st.push(eval(x,y,it));
            }
        }   
        return st.top();
    }
};
