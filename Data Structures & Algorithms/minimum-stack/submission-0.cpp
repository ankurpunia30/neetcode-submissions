class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(!st.empty())
        st.push({val,min(val,st.top().second)});
        else{
            st.push({val,val});
        }
    }
    
    void pop() {
        if(!st.empty())
        st.pop();
    }
    
    int top() {
        if(!st.empty())
        return st.top().first;
        return -1;
    }
    
    int getMin() {
        if(!st.empty())
        return st.top().second;
        return 0;
    }
};
