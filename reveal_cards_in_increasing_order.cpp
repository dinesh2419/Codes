class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        sort(deck.begin(),deck.end());
        int i,n=deck.size();
        queue<int>q;
        for(i=0;i<n;i++)
        {
            q.push(i);
        }
        vector<int>final;
        while(q.size()!=0)
        {
            int ms=q.front();
            q.pop();
            final.push_back(ms);
            if(q.size()>0)
            {
                int temp=q.front();
                q.pop();
                q.push(temp);
            }
        }
        
        map<int,int>m;
        for(i=0;i<n;i++)
        {
            m[final[i]]=deck[i];
        }
        vector<int>ans;
        for(auto it=m.begin();it!=m.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};