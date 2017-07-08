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
    bool isValidBSTUtil(TreeNode *root, int *predecessor)
    {
        if (!root)
            return true;
            
        if (   !isValidBSTUtil(root->left, predecessor)
            || *predecessor != -1 && (*predecessor >= root->val))
            return false;
            
        *predecessor = root->val;
        return isValidBSTUtil(root->right, predecessor);
    }

    bool isValidBST(TreeNode* root) 
    {
        int predecessor = -1;
        return isValidBSTUtil(root,&predecessor);   
    }
};