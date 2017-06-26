/* Algo Used :

1. Use Pre-Order traversal.
2. Pass current level and answer vector to helper function.
3. If size of answer vector is same as level, that means that for that
      tree level, nothing has been added to answer vector. Hence add current value.
   Else
      There is already an entry available for this tree level in the answer vector.
      Compare existing entry with current root->val and add the maximum out of it 
      in the answer vector.

4. Recurse for left tree and right tree.
5. Return the answer vector.
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
    void largestValuesUtil(TreeNode *root, vector<int>&a, int level)
    {
        if (!root)
            return;
            
        if (a.size() == level)
            a.push_back(root->val);
        else
            a[level] = max(a[level], root->val);
        
        largestValuesUtil(root->left,a,level+1);
        largestValuesUtil(root->right,a,level+1);
    }
    
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int>ans;
        largestValuesUtil(root,ans,0);
        return ans;
    }
};