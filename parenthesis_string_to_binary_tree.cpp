class Solution{
public:
    int i=0;
    
    void construct(Node* root,string s)
    {
       if(i<s.size() && isdigit(s[i]))
       {
           int sum=0;
           while(i<s.size() && isdigit(s[i]))
           {
               sum*=10;
               sum+=s[i]-'0';
               i++;
           }
           root->data=sum;
        }
        
        if(i<s.size() && s[i]=='(')
        {
            root->left=new Node(0);
            i++;
            construct(root->left,s);
        }
        
        if(i<s.size() && s[i]== '(')
        {
            root->right=new Node(0);
            i++;
            construct(root->right,s);
        }
       
        if(i>=s.size() || s[i]==')')
        {
            i++;
            return;
        }
       
           
    }
    
    Node *treeFromString(string s)
    {
        int n=s.size();
        Node* root=new Node(0);
        construct(root,s);
        return root;
    }
};
