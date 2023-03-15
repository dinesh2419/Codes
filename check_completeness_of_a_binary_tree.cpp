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
    bool isCompleteTree(TreeNode* root)
    {
        int temp=0;
        queue< pair<TreeNode*,int> >q;
        q.push({root,1});
        while(q.size()!=0)
        {
            auto it=q.front();
            q.pop();
            struct TreeNode* current=it.first;
            int index=it.second;
            if(index!=temp+1)
            {
                return false;
            }
            temp=index;
            if(current!=NULL && current->left!=NULL)
            {
                q.push({current->left,2*index});
            }
            if(current!=NULL && current->right!=NULL)
            {
                q.push({current->right,2*index+1});
            }
        }
        return true;
    }
};
