class Solution {
public:
    int d = 0;

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);

        d = max(d, leftHeight + rightHeight);  // Update diameter

        return max(leftHeight, rightHeight) + 1;  // Return height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return d;
    }
};
