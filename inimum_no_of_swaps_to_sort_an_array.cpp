int minSwaps(vector<int>&nums)
	{
	    int ans=0;
	    vector< pair<int,int> >v;
	    int i;
	    for(i=0;i<nums.size();i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    for(i=0;i<nums.size();i++)
	    {
	        if(v[i].second==i)
	        {
	            continue;
	        }
	        else
	        {
	            ans++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return ans;
	    
	}
