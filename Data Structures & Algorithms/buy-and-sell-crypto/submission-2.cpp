class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //main goal is to buy at less and sell at high
        int maxBuy=prices[0];
        int ans=0;
        for(int i=0;i<prices.size();i++){
            maxBuy=min(maxBuy,prices[i]);
            ans=max(ans,prices[i]-maxBuy);
        }
        return ans;
    }
};
