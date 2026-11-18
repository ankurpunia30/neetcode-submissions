class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #{i,j}=>sum==target
        #one way is to sort the array and later check from both sides
        #another way is to use dictionary with format
        #{key:value}=>{number:index}
        #iterate and check does there exist any number where abs(nums[i]-target)==0 so pick that {index,current index}
        mappings=dict()
        for i in range(0,len(nums)):
            difference=target-nums[i]
            if (difference) in mappings:
                return [mappings[difference],i]
            mappings[nums[i]]=i
        return ValueError("No Valid Pair found") 