class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }   

        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
    vector<int >v;
        while(k-- && !pq.empty()){
            pair<int,int> val=pq.top();
            pq.pop();
            int num=val.second;
            v.push_back(num);
        }
        return v;
    }
};
