class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue< pair<int,int> >q;
        int i,j;
        int m=grid.size(),n=grid[0].size();
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        set< pair<int,int> >s;
        int ans=0;
        q.push({-1,-1});
        while(q.size()!=0)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==-1 && y==-1 && q.size()==0)
            {
                break;
            }
            else if(x==-1 && y==-1 && q.size()!=0)
            {
                ans++;
                q.push({-1,-1});
            }
            else if(x!=-1 && y!=-1)
            {
                grid[x][y]=2;
                if(y+1<=n-1 && grid[x][y+1]==1)
                {
                    if(s.count({x,y+1})==0)
                    {
                       q.push({x,y+1});
                       s.insert({x,y+1});
                    }   
                }
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    if(s.count({x,y-1})==0)
                    {
                       q.push({x,y-1});
                       s.insert({x,y-1});
                    }   
                }
                if(x+1<=m-1 && grid[x+1][y]==1)
                {
                    if(s.count({x+1,y})==0)
                    {
                      q.push({x+1,y});
                      s.insert({x+1,y});
                    }   
                }
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    if(s.count({x-1,y})==0)
                    {
                      q.push({x-1,y});
                      s.insert({x-1,y});
                    }   
                }
            }
         }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        
        return ans;
        
        
        
        
        
        
    }
};
