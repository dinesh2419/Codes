vector<int> diagonal(Node *root)
{
   vector<int>ans;
   if(root==NULL)
   return ans;
   queue<Node*>q;
   q.push(root);
   while(q.size()!=0)
   {
       struct Node* current=q.front();
       q.pop();
       while(current!=NULL)
       {
          if(current->left!=NULL)
          {
              q.push(current->left);
          }
          ans.push_back(current->data);
          current=current->right;
       }
   }
   return ans;
}
