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
    void findBottomLeftValueUtil(TreeNode* root, int l, int* ans, int *al)
    {
        if (!root)
            return;
            
        if (l > *al)
        {
            *ans = root->val;
            *al = l;
        }
        
        findBottomLeftValueUtil(root->left, l+1, ans, al);
        findBottomLeftValueUtil(root->right, l+1, ans, al);
        
    }
    int findBottomLeftValue(TreeNode* root) 
    {
        int answer,level,a_level;
        answer = level = 0;
        a_level = -1;
        findBottomLeftValueUtil(root, level, &answer, &a_level);
        return answer;
    }
};