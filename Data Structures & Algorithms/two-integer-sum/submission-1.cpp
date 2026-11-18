class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //as length is not big we can actually do with 2 loops
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return {mp[target-nums[i]],i};
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};
