class Solution {
public:
     unordered_map<int,pair<int,int>>dp,dp1;
     unordered_map<int,pair<int,int>>r_dp,r_dp1;
    void dfs(int u,int p,int n,vector<vector<int>>&adj,int f)
    {
        if(f==0)
        dp[u]={0,0};
        else
        dp1[u]={0,0};
        int odd=0;
        int even=0;
        for(auto it:adj[u])
        {
            if(it==p)
                continue;
            dfs(it,u,n,adj,f);
            even+=(f==0)?dp[it].first:dp1[it].first;
            odd+=(f==0)?dp[it].second:dp1[it].second;
            odd++;
        }
        //cout<<f<<" "<<u<<" "<<odd<<" "<<even<<"\n";
        if(f==0)
        dp[u]=make_pair(odd,even);
        else
        dp1[u]=make_pair(odd,even);
    }
    int maxi=-1;
    int nd=-1;
    
    void dfs1(int u,int p,int n,vector<vector<int>>&adj,int f)
    {
        if(f==0)
            r_dp[u]=dp[u];
        else
            r_dp1[u]=dp1[u];
        if(p!=-1)
        {
        pair<int,int>pr=(f==0)?r_dp[p]:r_dp1[p];
          //  cout<<f<<" "<<u<<"\n";
           if(f==0)
            {
                pr.first-=dp[u].second;
                pr.second-=dp[u].first;
                pr.first--;
             r_dp[u].first+=pr.second+1;
            r_dp[u].second+=pr.first;
              //  cout<<f<<" "<<u<<" "<<r_dp[u].first<<" "<<r_dp[u].second<<"\n";
            }
            else
            {
              pr.first-=dp1[u].second;
              pr.second-=dp1[u].first;
                pr.first--;
              r_dp1[u].first+=pr.second+1;
              r_dp1[u].second+=pr.first; 
                //cout<<f<<" "<<u<<" "<<r_dp1[u].first<<" "<<r_dp1[u].second<<"\n";
             if(r_dp1[u].first>maxi)
               {
                   maxi=r_dp1[u].first;
                   nd=u;
               }
            }
        }
       
            //cout<<f<<" "<<it<<" "<
        for(auto it:adj[u])
        {
            if(it==p)
                continue;
            dfs1(it,u,n,adj,f);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) 
    {
      int n=edges1.size();
      int m=edges2.size();
      vector<vector<int>>adj,adj1;
      adj.resize(n+1);
      adj1.resize(m+1);
      for(int i=0;i<n;i++)
      {
          int u=edges1[i][0];
          int v=edges1[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
      for(int i=0;i<m;i++)
      {
          int u=edges2[i][0];
          int v=edges2[i][1];
          adj1[u].push_back(v);
          adj1[v].push_back(u);
      }
        dfs(0,-1,n,adj,0);
        dfs(0,-1,m,adj1,1);
        dfs1(0,-1,n,adj,0);
        dfs1(0,-1,m,adj1,1);  
         if(r_dp1[0].first>maxi)
               {
                   maxi=r_dp1[0].first;
                   nd=0;
               }
        vector<int>ans;
        for(int i=0;i<n+1;i++)
        {
            int cal=r_dp[i].second+r_dp1[nd].first;
            ans.push_back(cal+1);
        }
        return ans;
    }
};