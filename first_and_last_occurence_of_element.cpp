class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
         int low=0;
         int high=nums.size()-1;
         int res1=-1;
         while(low<=high)
         {
             int mid=low+(high-low)/2;
             if(nums[mid]==target)
             {
                 res1=mid;
                 high=mid-1;
             }
             else if(nums[mid]>target)
             {
                 high=mid-1;
             }
             else
             {
                 low=mid+1;
             }    
        }
        low=0,high=nums.size()-1;
        int res2=-1;
        while(low<=high)
         {
             int mid=low+(high-low)/2;
             if(nums[mid]==target)
             {
                 res2=mid;
                 low=mid+1;
             }
             else if(nums[mid]>target)
             {
                 high=mid-1;
             }
             else
             {
                 low=mid+1;
             }    
        }
        if(res1==-1 && res2==-1)
        {
            vector<int>ans;
            ans.push_back(-1);
            ans.push_back(-1);
                return ans;
        }
        vector<int>v;
        v.push_back(res1);
        v.push_back(res2);
        return v;
        
    }
};