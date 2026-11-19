class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #sort the list first
        nums.sort()
        #use counter to calculate counts
        count=1
        mappings=[]
        for i in range(1,len(nums)):
            if nums[i]==nums[i-1]:
                count+=1
            else:
                mappings.append([count,nums[i-1]])
                count=1
        
        mappings.append([count,nums[-1]])
        #not sure what will come here
        mappings.sort(key=lambda x:x[0],reverse=True)
        ans=[mappings[i][1] for i in range(k) if i < len(mappings)]
        return ans
        

        
        