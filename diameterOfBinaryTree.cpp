/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root, int *d)
    {
        if(!root)
            return 0;
        int l = diameterOfBinaryTree(root->left, d);
        int r = diameterOfBinaryTree(root->right, d);
        
        if (l+r > *d)
            *d = l+r;
        
        return (1+max(l,r));
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int d = 0;
        int height = diameterOfBinaryTree(root, &d);
        return d;
    }
};