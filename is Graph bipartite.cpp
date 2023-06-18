class Solution 
{
public:
    vector<int>vis;
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
       int i,n=graph.size();
       for(i=0;i<n;i++)
       {
           vis.push_back(-1);
       }
       
       queue<int>q;
      for(int p=0;p<n;p++)
      {    
         if(vis[p]!=-1)
         {
             continue;
         }
       q.push(p);
       vis[p]=0;
       while(q.size()!=0)
       {
           int current=q.front();
           q.pop();
           vector<int>v=graph[current];
           for(i=0;i<v.size();i++)
           {
               if(vis[v[i]]==-1)
               {
                   if(vis[current]==0)
                   {
                       vis[v[i]]=1;
                       q.push(v[i]);
                   }
                   else
                   {
                       vis[v[i]]=0;
                       q.push(v[i]);
                   }
               }
               else
               {
                   if(vis[current]==vis[v[i]])
                   {
                       return false;
                   }
               }
           }
           // for(int k=0;k<n;k++)
           // {
           //     cout<<vis[k]<<" ";
           // }
       }
      }  
        
        return true;
        
        
    }
};
