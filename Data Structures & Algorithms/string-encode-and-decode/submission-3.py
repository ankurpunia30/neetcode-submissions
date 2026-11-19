class Solution:
    def encode(self, strs: list[str]) -> str:
        # Format each chunk as "<length>#<string>" and join once in O(N)
        return "".join(f"{len(s)}#{s}" for s in strs)

    def decode(self, s: str) -> list[str]:
        res = []
        i = 0
        
        while i < len(s):
            # Find the '#' delimiter starting from index i
            j = s.find("#", i)
            length = int(s[i:j])
            
            # Extract the exact substring after '#'
            start = j + 1
            end = start + length
            res.append(s[start:end])
            
            # Jump i directly to the start of the next length prefix
            i = end
            
        return res