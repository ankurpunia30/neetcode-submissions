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
    void findAns(TreeNode* r1,TreeNode* r2){
        if(r1==NULL || r2==NULL)return ;
        
        findAns(r1->left,r2->right);
        swap(r1,r2);
        findAns(r1->right,r2->left);
        
    }
    TreeNode* invertTree(TreeNode* root) {
        //one way is to do level order traversal and change all the nodes value
        //another way is got to  left go to right and at each point change values
        if(root==NULL)return NULL;
        TreeNode* l=invertTree(root->right);
        TreeNode* r=invertTree(root->left);
        root->left=l;
        root->right=r;
        // findAns(root->left,root->right);
        return root;
    }
};
