class Solution {
public:
    bool find(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL)
        {
            if( (root->val)==0 )
            {
                return false;
            }
            else if( (root->val)==1 )
            {
                return true;
            }
        }
        
        bool lh=find(root->left);
        bool rh=find(root->right);
        
        if(root->val==2)
        {
            return (lh||rh);
        }
        else
        {
            return (lh&&rh);
        }
        
        
        
    }
    
    bool evaluateTree(TreeNode* root) 
    {
        return  find(root);
    }
};
