class Solution 
{
public:
    int findindex(vector<int>&nums)
    {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int start=0,end=n-1;
        if(nums[start]<nums[end])
            return nums[start];
        while(start<=end)
        {
            int mid=(start+end)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            if(nums[start]<nums[end])
            {
                return start;
            }
            else if(nums[mid]<nums[prev] && nums[mid]<nums[next])
            {
                return mid;
            }
            if(nums[start]<=nums[mid])
            {
                start=mid+1;
            }
            else if(nums[mid]<=nums[end])
            {
                end=mid-1;
            }
        }
        return INT_MIN;
    }
    
    int BS(vector<int>&nums,int target,int low,int high)
    {
        if(nums.size()==1 && nums[0]==target)
        {
            return 0;
        }
        if(nums.size()==1 && nums[0]!=target)
        {
            return -1;
        }
        int x=low,y=high;
        while(x<=y)
        {
            int mid=(x+y)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
             y=mid-1;
            else
              x=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) 
    {
        if(nums.size()==1 && nums[0]==target)
        {
            return 0;
        }
        if(nums.size()==1 && nums[0]!=target)
        {
            return -1;
        }
        int index;
        index=findindex(nums);
       // cout<<index;
        if(index==0)
        {
            return BS(nums,target,0,nums.size()-1);
        }
        
        int m1=BS(nums,target,0,index-1);
        int m2=BS(nums,target,index,nums.size()-1);

        if(m1==-1 && m2==-1)
            return -1;
        else if(m1==-1 && m2!=-1)
            return m2;
        else 
            return m1;
    }
};