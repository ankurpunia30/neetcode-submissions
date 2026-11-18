class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //use a priority queue and keep maxscore as top-value[i]
        priority_queue<int,vector<int>,greater<int>>pq;
        int maxi=0;
        for(auto it:prices){
            pq.push(it);
            maxi=max(maxi,it-pq.top());
        }
        return maxi;
    }
};
