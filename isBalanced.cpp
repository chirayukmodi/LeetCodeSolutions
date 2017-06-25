/* Algo Used:

PostOrder Traversal

1. Recurse for left subtree.
2. Recurse for right subtree.
3.    If left subtree call returns -1,
   OR If right subtree call returns-1
   OR If height diffrence between left subtree
      and right subtree is > 1, return -1
      which means that tree beneath this node
      is node height balanced hence over all tree
      is not height balanced.

4. Else return TRUE. 

Note that in the same recursion we are
getting the height of the tree so time
complexity will be O(n). 
*/

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
    int isBalancedUtil(TreeNode *root)
    {
        if (!root)
            return 0;
            
        int l = isBalancedUtil(root->left);
        int r = isBalancedUtil(root->right);
            
        return (  (l == -1 || r == -1 || abs(l-r) > 1)
                ? -1
                : (1+max(l,r)));
    }
    bool isBalanced(TreeNode* root) 
    {
        return (  isBalancedUtil(root) == -1
                ? false
                : true);
    }
};