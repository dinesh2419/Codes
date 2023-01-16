class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>v;
        stack<int>s;
        int n=nums2.size(),i;
        for(i=n-1;i>=0;i--)
        {
            if(s.size()==0)
            {
                v.push_back(-1);
                s.push(nums2[i]);
            }
            else if(s.size()!=0 && nums2[i]<=s.top())
            {
                v.push_back(s.top());
                s.push(nums2[i]);
            }
            else if(s.size()!=0 && nums2[i]>s.top())
            {
                while(s.size()!=0 && nums2[i]>s.top())
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    v.push_back(-1);
                    s.push(nums2[i]);
                }
                else
                {
                    v.push_back(s.top());
                    s.push(nums2[i]);
                }
            }
        }
        reverse(v.begin(),v.end());
        map<int,int>m;
        int size=v.size();
        for(i=0;i<n;i++)
        {
            m[nums2[i]]=v[i];
        }
        vector<int>ans;
        int x=nums1.size();
        for(i=0;i<x;i++)
        {
            auto it=m.find(nums1[i]);
            ans.push_back(it->second);
        }
         return ans;
        
        
        
    }
};