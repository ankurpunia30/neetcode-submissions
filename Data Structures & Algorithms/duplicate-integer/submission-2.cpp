class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //one way to traverse for each element
        //best case O(n)-->we got it into first time
        //worst case O(n^2)
        //another way is using hashing
        unordered_map<int,int>hashmap;
        for(auto it:nums){
            if(hashmap.find(it)!=hashmap.end())return true;
            hashmap[it]++;
        }
        return false;
    }
};