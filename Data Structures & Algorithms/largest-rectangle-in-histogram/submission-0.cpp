class Solution {
public:
    vector<int>nextSmallerLeft(vector<int>&heights){
        vector<int>ans(heights.size(),-1);
        stack<int>st;
        
        for(int i=0;i<heights.size();i++){

            while(!st.empty() &&  heights[st.top()]>=heights[i]){
                st.pop();
            }
            
            if(!st.empty())
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>nextSmallerRight(vector<int>&heights){
vector<int>ans(heights.size(),heights.size());
        stack<int>st;
        
        for(int i=heights.size()-1;i>=0;i--){

            while(!st.empty() &&  heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty())
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>left=nextSmallerLeft(heights);
        vector<int>right=nextSmallerRight(heights);
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int  height=heights[i];
            int width=(right[i]-left[i]-1);
            maxArea=max(maxArea,height*width);
        }
        return maxArea;
    }
};
