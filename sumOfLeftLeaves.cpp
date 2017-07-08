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
    bool isLeaf(TreeNode *r)
    {
        return (r && !r->left && !r->right);
    }
    
    void sumOfLeftLeaves(TreeNode *root, int *ans)
    {
        if (!root)
            return;
        TreeNode *l  = root->left;
        if (isLeaf(l))
            *ans+=(l->val);
        
        sumOfLeftLeaves(l, ans);
        sumOfLeftLeaves(root->right, ans);
    }
    
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int ans = 0;
        sumOfLeftLeaves(root, &ans);
        return ans;
    }
};