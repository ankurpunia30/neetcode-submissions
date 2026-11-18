class Solution {
public:
    int maxArea(vector<int>& heights) {
        //pick minimum and check for area
        //now got for the next of that minimum and so on
        int i=0;
        int ans=0;
        int j=heights.size()-1;
        while(i<j){
            if(heights[i]<heights[j]){
                ans=max(ans,(heights[i])*(j-i));
                i++;
            }
            else{
                ans=max(ans,(heights[j])*(j-i));
                j--;
            }
        }
        return ans;
    }
};
