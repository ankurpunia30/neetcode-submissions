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
    int count=0;
    //root left right
    void pre(TreeNode*root,int maxi){
        if(root==NULL)return ;
        if(root->val>=maxi){
            count++;
            maxi=root->val;
        }
        
        pre(root->left,maxi);
        pre(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        //we can do one thing is 
        //start with one node and track values
        //as soon as we get a greater value mark that 
        //other wise simply add value if it not greater than max path route value
        pre(root,INT_MIN);
        return count;
    }
};
