class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //use a stack to keep track of next greater element
        //and at each point if there is greater ans[i]=st.top()-i;
        int n=temperatures.size();
        vector<int>ans(n);
        ans[n-1]=0;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(st.empty())ans[i]=0;
            else ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;

    }
};
