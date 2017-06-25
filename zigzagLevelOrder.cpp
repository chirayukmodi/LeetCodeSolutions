/* Algo Used

1. Create a queue and add root into it.
2. While queue is not empty,
3. Take current size of the queue. It will show number of elements currently at a particular level of the tree.
4. Run a for loop for number of size times and for each element push it to the answer vector and push left and right child to queue.
5. Go to step 3. 

Note : Here we will maintain a boolean variable which will be set to true and false alternatively at each
       level of the tree. When it is true, we will start adding element at the end of the answer vector and we will
       start coming toward front.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        queue <TreeNode *> q;
        int size;
        bool startfromend = true;
        
        vector<vector<int>>V;
        
        if (!root)
            return V;
        q.push(root);
        size = 1;
        
        while(!q.empty())
        {
            size  = q.size();
            vector<int>v(size,-1);
            startfromend = !startfromend;
            for (int i = 0;i<size;i++)
            {
                TreeNode * t = q.front();
                q.pop();
                
                if (startfromend)
                    v[size-(i+1)] = t->val;
                else
                    v[i] = t->val;
            
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            V.push_back(v);
        }
        return V;
    }
};