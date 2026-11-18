class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0];
        int currSum=0;

        for(auto it:nums){
            currSum=max(currSum,0);
            currSum+=it;
            maxi=max(maxi,currSum);
        }
        return maxi;
    }
};
