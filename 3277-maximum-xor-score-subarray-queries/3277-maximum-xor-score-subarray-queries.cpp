class Solution {
public:
    int maxi[2001][2001];
    int dp[2001][2001];
    int dfs(int i,int j,vector<int>&nums)
    {
        if(i==j)
        {
            dp[i][j]=nums[i];
            return dp[i][j];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=dfs(i,j-1,nums)^dfs(i+1,j,nums);
//cout<<" "<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
        return dp[i][j];
    }
    int dfs1(int i,int j,vector<int>&nums)
    {
        if(i==j)
        {
            maxi[i][j]=nums[i];
            return maxi[i][j];
        }
        if(i>j||j<i)
            return INT_MIN;
        if(maxi[i][j]!=-1)
            return maxi[i][j];
       // cout<<dp[i][j]<<"\n";
        maxi[i][j]=max(max(dp[i][j],dfs1(i+1,j,nums)),max(dp[i][j],dfs1(i,j-1,nums)));
        return maxi[i][j];
    }
    
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries)
    {
        vector<int>ans;
        int n=nums.size();
        int sz=queries.size();
        //int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
          for(int j=0;j<=n;j++)
          {
             dp[i][j]=-1;
             maxi[i][j]=-1;
          }
        }
        dfs(0,n-1,nums);
        dfs1(0,n-1,nums);
        for(int i=0;i<sz;i++)
        {
            ans.push_back(maxi[queries[i][0]][queries[i][1]]);
        }
        return ans;
    }
};