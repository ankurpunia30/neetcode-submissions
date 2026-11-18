class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                if(sum<0){
                    j++;
                }
                if(sum>0){
                    k--;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};
