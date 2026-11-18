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
    int preind=0;
    unordered_map<int,int>mp;
    TreeNode* merge(int leftIndex,int rightIndex,vector<int>& preorder, vector<int>& inorder){
        if(leftIndex>rightIndex)return NULL;
        if(preind==preorder.size())return NULL;
        //going to the next index in preorder
        //finding position in inorder
        TreeNode* root=new TreeNode(preorder[preind++]);
        int element=root->val;
        int position=mp[element];
        //find element from preorder
        root->left=merge(leftIndex,position-1,preorder,inorder);
        root->right=merge(position+1,rightIndex,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //find position in the inorder of element of preorder
        //becuase preorder=>root,left,right
        //whereas in inorder it will be =>left root  right
       
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return merge(0,inorder.size()-1,preorder,inorder);
    }
};
