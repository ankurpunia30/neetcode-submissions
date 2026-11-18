class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len=1;
        int maxlen=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1+nums[i-1]){
                len++;
                maxlen=max(maxlen,len);
            }
            else if(nums[i]==nums[i-1])continue;
            else{
                len=1;
                maxlen=max(maxlen,len);
            }
        }
        return nums.size()==0?0:maxlen;
    }
};
