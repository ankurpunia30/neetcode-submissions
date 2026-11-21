class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        mapping=set(i for i in nums)
        maxCount=1
        count=1
        for i in mapping:
            if i-1 not in mapping:
                count=1
                while i+count in mapping:
                    count+=1
            maxCount=max(maxCount,count)
        return maxCount