class Solution {
public:
    int trap(vector<int>& height) {
        //find the next greater to the left ngl[i]
        //find the next greater to the right say ngr[i]
        //for each point area stored will be min(ngl[i],ngr[i])-height[i]
        //or even we can use suffix and prefix max 
        int n=height.size();
        vector<int>leftMax(n),rightMax(n);
        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];
        for(int i=1;i<n;i++)leftMax[i]=max(leftMax[i-1],height[i]);
        for(int i=n-2;i>=0;i--)rightMax[i]=max(rightMax[i+1],height[i]);
        
        int res=0;
        for(int i=0;i<n;i++){
            res+=min(leftMax[i],rightMax[i])-height[i];
        }
        return res;
    }
};
