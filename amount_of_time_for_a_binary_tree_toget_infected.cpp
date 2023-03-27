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
class Solution 
{
public:
    map<int,TreeNode*>m;
    int amountOfTime(TreeNode* root, int start) 
    {
         queue<TreeNode*>q;
         q.push(root);
        struct TreeNode* temp=NULL;
        while(q.size()!=0)
        {
            struct TreeNode* current=q.front();
            q.pop();
            if(current!=NULL && current->left!=NULL)
            {
                q.push(current->left);
                m[current->left->val]=current;
            }
            if(current!=NULL && current->right!=NULL)
            {
                q.push(current->right);
                m[current->right->val]=current;
            }
            if((current->val)==start)
            {
                temp=current;
            }
        }
        
        set<int>s;
        queue<TreeNode*>f;
        f.push(temp);
        int ans=0;
        while(f.size()!=0)
        {
            int size=f.size();
            for(int i=0;i<size;i++)
            {
                struct TreeNode* var=f.front();
                f.pop();
                s.insert(var->val);
                if(var->left!=NULL)
                {
                    if(s.count(var->left->val)==0)
                    f.push(var->left);
                }
                if(var->right!=NULL)
                {
                    if(s.count(var->right->val)==0)
                    f.push(var->right);
                }
                if(m.count(var->val)!=0)
                {
                    auto it=m[var->val];
                    if(s.count(it->val)==0)
                    f.push(m[var->val]);
                }
            }
            ans++;
        }
        return ans-1;
    }
};
