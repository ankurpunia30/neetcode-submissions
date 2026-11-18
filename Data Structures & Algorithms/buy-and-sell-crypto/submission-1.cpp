class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //use a priority queue and keep maxscore as top-value[i]
        int mini=INT_MAX;
        int maxi=0;
        for(auto it:prices){
            mini=min(it,mini);
            maxi=max(maxi,it-mini);
        }
        return maxi;
    }
};
