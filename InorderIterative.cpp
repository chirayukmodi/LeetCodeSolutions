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
    
    bool isLeaf (TreeNode *r)
    {
        return (!r->left && !r->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode * , bool>>s;
        pair <TreeNode *,bool>p;
        vector <int> ans;
        TreeNode* t;
        
        if (!root)
            return ans;
        
        s.push(make_pair(root,false));
        
        while(!s.empty())
        {
            p = s.top();
            s.pop();
            t = get<0>(p);
            
            if (   isLeaf(t) 
                || get<1>(p)
                || !t->left)
            {
                ans.push_back(t->val);
                if (t->right)
                    s.push(make_pair(t->right,false));
                continue;
            }
            
            s.push(make_pair(t, true));
            s.push(make_pair(t->left,false));
        }
        
        return ans;
    }
};