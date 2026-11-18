class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //one way is to check using normal travesing 
        //another way is we can think of bs
        //first integer is greater than previous row last integer
        //one way is nlogm
        for(int i=0;i<matrix.size();i++){
            int ind=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
            if(matrix[i][ind]==target)return true;
        }
        return false;
    }
};
