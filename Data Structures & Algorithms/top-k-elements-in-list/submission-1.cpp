class Solution {
public:
    //above time complexity is o(nlogn)
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n=nums.size();
       map<int,int>mp;
       for(auto it:nums)mp[it]++;
       vector<vector<int>>v(n+1);
       for(auto it:mp){
        v[it.second].push_back(it.first);
       }
        vector<int> result;
    for (int i = n; i >= 0 && result.size() < k; --i) {
        for (int num : v[i]) {
            result.push_back(num);
            if (result.size() == k) break;
        }
    }

    return result;

    }
};
