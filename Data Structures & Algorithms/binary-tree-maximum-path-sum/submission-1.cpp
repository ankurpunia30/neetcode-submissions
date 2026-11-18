/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxi=INT_MIN;
    int FindAns(TreeNode* root){
        if(root==NULL)return 0;
        int curr=root->val;
        int leftSub=max(0,FindAns(root->left));
        int rightSub=max(0,FindAns(root->right));
        int path=leftSub+rightSub+curr;
        maxi=max(maxi,path);
        return curr+max(leftSub,rightSub);
    }
    int maxPathSum(TreeNode* root) {
        //find max sum path along the nodes
        //left subtree right subtree and current node
        FindAns(root);
        return maxi;
    }
};
