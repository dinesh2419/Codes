class Solution {
public:
    int findMin(vector<int>& nums) 
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
               return nums[start];
            }
            else if(nums[mid]<nums[prev] && nums[mid]<nums[next])
            {
                return nums[mid];
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
};