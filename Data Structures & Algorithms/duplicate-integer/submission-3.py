class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        mappings=set()
        for i in nums:
            if i in mappings:
                return True
            mappings.add(i)
        return False
        