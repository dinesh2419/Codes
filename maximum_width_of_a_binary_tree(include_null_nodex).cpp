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
    int widthOfBinaryTree(TreeNode* root) 
    {
        deque< pair<TreeNode*,int> >q;
        q.push_back({root,1});
        int ans=0;
        while(q.size()!=0)
        {
            int n=q.size();
            int temp=(q.back().second)-(q.front().second)+1;
            ans=max(ans,temp);
            
            while(n!=0)
            {
                auto it=q.front();
                q.pop_front();
                
                struct TreeNode* current=it.first;
                int index=it.second;
               
                if(current!=NULL && current->left!=NULL)
                {
                    q.push_back({current->left,(long long)2*index+1});
                }
                
                if(current!=NULL && current->right!=NULL)
                {
                    q.push_back({current->right,(long long)2*index+2});
                }
                n--;
            }
            
            
        }
        return ans;
    }
};
