class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>ans;
        int i=0,j=0,l=s.length(),k=p.length();
        map<int,int>m;
        for(i=0;i<k;i++)
        {
            m[p[i]]++;
        }
        int count=m.size();
        i=0;
        while(j<l)
        {
            m[s[j]]--;
            if(m[s[j]]==0)
            {
                count--;
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
               if(count==0)
               {
                   ans.push_back(i);
               }
                m[s[i]]++;
                if(m[s[i]]==1)
                {
                    count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};