class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int maxlen=0;
        for(auto it:nums){
            if(s.find(it-1)==s.end()){
                int curr=it;
                int len=1;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    len++;
                }
                maxlen=max(maxlen,len);
            }
        }
        return maxlen;
    }
};
