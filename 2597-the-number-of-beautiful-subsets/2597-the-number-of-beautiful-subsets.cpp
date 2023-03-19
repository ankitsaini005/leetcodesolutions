class Solution {
public:
   // int dp[(1<<20)+1];
    map<int,int>mp;
    int solve(int idx,vector<int>&nums,int k,int n)
    {
        if(idx==n)
        {
            
            return 1;
        }
       
        int ans=0;
        if(mp[nums[idx]-k]==0)
        {
         //   int nwmask=(mask)|(1<<idx);
            mp[nums[idx]]++;
            ans+=solve(idx+1,nums,k,n);
            mp[nums[idx]]--;
        }
        ans+=solve(idx+1,nums,k,n);
      //  dp[mask]=ans;
        return ans;
    }
    int beautifulSubsets(vector<int>& nums, int k) 
    {
       // memset(dp,-1,sizeof dp);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return solve(0,nums,k,n)-1;
    }
};