class Solution {
public:
    void leftview(Node*root,vector<int>&ans)
    {
        if(root==NULL)
        return;
        if(root->left!=NULL)
        {
            ans.push_back(root->data);
            leftview(root->left,ans);
        }
        else if(root->right!=NULL)
        {
            ans.push_back(root->data);
            leftview(root->right,ans);
        }
    }
    
    void rightview(Node*root,vector<int>&ans)
    {
        if(root==NULL)
        return;
        if(root->right!=NULL)
        {
            rightview(root->right,ans);
            ans.push_back(root->data);
           
        }
        else if(root->left!=NULL)
        {
            rightview(root->left,ans);
            ans.push_back(root->data);
            
        }
    }
    
    void bottomview(Node* root,vector<int>&ans)
    {
        if(root==NULL)
        return;
        if(root!=NULL)
        {
            bottomview(root->left,ans);
            if(root->left==NULL && root->right==NULL)
            ans.push_back(root->data);
            bottomview(root->right,ans);
        }
    }
    vector<int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL)
        return ans;
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            return ans;
        }
        ans.push_back(root->data);
        leftview(root->left,ans);
        bottomview(root,ans);
        rightview(root->right,ans);
        return ans;
        
    }
};
