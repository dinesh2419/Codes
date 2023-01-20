class StockSpanner {
public:
    stack<pair<int,int>>s;
    int index=0;
    StockSpanner() 
    {
        
    }
    
    int next(int price) 
    {
       if(s.size()==0)
       {
           s.push({price,index});
           int ans=index;
           index++;
           return ans+1;
        }
        else if(s.size()!=0 && s.top().first>price)
        {
            int temp=s.top().second;
            s.push({price,index});
            int ans=index;
            index++;
            return ans-temp;
        }
        else if(s.size()!=0 && s.top().first<=price)
        {
            while(s.size()!=0 && s.top().first<=price)
            {
                s.pop();
            }
            if(s.size()==0)
            {
                 s.push({price,index});
                int ans=index;
                index++;
                return ans+1;
            }
            else
            {
                int temp=s.top().second;
                s.push({price,index});
                int ans=index;
                index++;
                return ans-temp;
            }
            
        }
           return 1; 
    }
};